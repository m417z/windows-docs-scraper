#!/usr/bin/env python3
"""
Windows Docs Scraper

A Python script that processes Windows Driver Kit DDI or Win32 API reference
documentation, extracting metadata, cleaning markdown content, and scraping
function prototypes from online documentation.
"""

import argparse
import hashlib
import json
import multiprocessing
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time
import traceback
import uuid
from contextlib import contextmanager
from dataclasses import dataclass
from enum import IntEnum, auto
from pathlib import Path
from typing import Dict, List, Optional, Tuple
from urllib.parse import quote, urljoin

import aria2p
import yaml
from bs4 import BeautifulSoup, Tag
from bs4.element import NavigableString
from markdownify import MarkdownConverter

# =============================================================================
# Constants and Configuration
# =============================================================================

USER_AGENT = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36'


class Nonce:
    """Global nonce values used for temporary markers in content processing."""
    PreCodeBlock1 = f'PRE_NONCE_1_{uuid.uuid4().hex.upper()}'
    PreCodeBlock2 = f'PRE_NONCE_2_{uuid.uuid4().hex.upper()}'
    LeadingSpaces = f'LEADING_SPACES_NONCE_{uuid.uuid4().hex.upper()}'
    TableBr = f'TABLE_BR_NONCE_{uuid.uuid4().hex.upper()}'


class DocsRepositoryType(IntEnum):
    ORGANIZED = auto()  # With file name prefixes and organized structure
    FUZZY = auto()      # Without file name prefixes, less organized


class ProcessingResult(IntEnum):
    """Result types from processing a markdown file."""
    CODE_EXTRACTED = auto()
    NO_CODE = auto()
    UNSUPPORTED = auto()
    ERROR = auto()


# =============================================================================
# Data Classes
# =============================================================================

@dataclass
class DocsRepositoryInfo:
    content_path: str
    base_url: str
    type: DocsRepositoryType


@dataclass
class WorkerArgs:
    """Arguments for worker process."""
    index: int
    total: int
    md_file: Path
    content_dir: Path
    output_path: Path
    base_url: str
    repo_type: DocsRepositoryType
    previous_output_path: Optional[Path]
    downloaded_html_path: Optional[Path]


@dataclass
class ProcessingStats:
    """Statistics from file processing."""
    code_extracted: int = 0
    code_not_extracted: int = 0
    unsupported: int = 0
    errors: int = 0

    def print_summary(self, output_path: Path):
        """Print processing summary."""
        print(f"\nProcessing complete:")
        print(f"Code definitions extracted: {self.code_extracted}")
        print(f"Code definitions not extracted: {self.code_not_extracted}")
        print(f"Unsupported files skipped: {self.unsupported}")
        print(f"Exceptions raised: {self.errors}")
        print(f"Output directory: {output_path}")


@dataclass
class ScraperConfig:
    """Configuration for the scraper."""
    input_path: Path
    output_path: Path
    content_dir: Path
    base_url: str
    repo_type: DocsRepositoryType
    previous_output_path: Optional[Path]
    input_filter: Optional[str]


# =============================================================================
# Repository Configuration
# =============================================================================

DOCS_REPOSITORY_INFO = {
    'windows-driver-docs-ddi': DocsRepositoryInfo(
        content_path='wdk-ddi-src/content',
        base_url='https://learn.microsoft.com/windows-hardware/drivers/ddi/',
        type=DocsRepositoryType.ORGANIZED,
    ),
    'sdk-api': DocsRepositoryInfo(
        content_path='sdk-api-src/content',
        base_url='https://learn.microsoft.com/windows/win32/api/',
        type=DocsRepositoryType.ORGANIZED,
    ),
    'windows-driver-docs': DocsRepositoryInfo(
        content_path='windows-driver-docs-pr',
        base_url='https://learn.microsoft.com/windows-hardware/drivers/',
        type=DocsRepositoryType.FUZZY,
    ),
    'win32': DocsRepositoryInfo(
        content_path='desktop-src',
        base_url='https://learn.microsoft.com/windows/win32/',
        type=DocsRepositoryType.FUZZY,
    ),
}


# =============================================================================
# Exceptions
# =============================================================================

class UnsupportedFuzzyDoc(Exception):
    """Raised when a fuzzy documentation page is unsupported for processing."""
    pass


# =============================================================================
# Aria2 Download Management
# =============================================================================

@contextmanager
def aria2_downloader(download_dir: str):
    """
    Context manager for aria2c daemon lifecycle.

    Starts aria2c daemon on entry, stops it and cleans up on exit.
    """
    process = None
    try:
        cmd = [
            'aria2c',
            '--enable-rpc',
            '--rpc-listen-port=6800',
            '--dir=' + download_dir,
            '--auto-file-renaming=false',
            '--allow-overwrite=true',
            '--user-agent=' + USER_AGENT,
            '--max-tries=50',
            '--retry-wait=5',
            '--max-connection-per-server=4',  # Reduce to avoid 429 errors
        ]
        process = subprocess.Popen(
            cmd,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )
        time.sleep(1)  # Wait for daemon to start

        api = aria2p.API(aria2p.Client(host="http://localhost", port=6800))
        yield api
    finally:
        if process is not None:
            process.terminate()
            try:
                process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                process.kill()


def batch_download_urls(
    api: aria2p.API,
    urls: List[str],
    download_dir: Path,
) -> Dict[str, Path]:
    """
    Download multiple URLs using aria2c.

    Returns dict mapping URL to downloaded file path.
    Raises RuntimeError if any download fails (except 429 which triggers retry).
    """
    if not urls:
        return {}

    MAX_BACKOFF_SECONDS = 300  # 5 minutes
    BACKOFF_RESET_SECONDS = 300  # Reset backoff if no error for 5 minutes

    # Global backoff state
    backoff_delay = 1
    last_error_time = None

    # Map URL to filename and GID for tracking
    url_to_filename = {}
    url_to_gid = {}

    def queue_download(url: str) -> str:
        """Queue a URL for download and return its GID."""
        filename = hashlib.md5(url.encode()).hexdigest() + '.html'
        url_to_filename[url] = filename
        options = {'out': filename}
        download = api.add_uris([url], options=options)
        return download.gid

    # Queue all initial downloads
    for url in urls:
        url_to_gid[url] = queue_download(url)

    # Wait for all downloads to complete
    results = {}
    pending_urls = set(urls)
    total = len(urls)
    completed = 0

    while pending_urls:
        time.sleep(0.5)

        # Get all downloads (avoids GID not found errors)
        all_downloads = api.get_downloads()

        # Build a map of current downloads by GID
        downloads_by_gid = {d.gid: d for d in all_downloads}

        # Check each pending URL
        for url in list(pending_urls):
            gid = url_to_gid[url]
            filename = url_to_filename[url]
            file_path = download_dir / filename

            # Check if download is in aria2c's list
            if gid in downloads_by_gid:
                download = downloads_by_gid[gid]
                if download.is_complete:
                    results[url] = file_path
                    pending_urls.remove(url)
                    completed += 1
                    print(f"[{completed}/{total}] Downloaded: {url}")
                elif download.has_failed:
                    error_msg = download.error_message or f"Error code {download.error_code}"

                    # Check for 429 rate limiting error
                    if 'status=429' in error_msg or '429' in str(download.error_code):
                        current_time = time.time()

                        # Reset backoff if last error was more than 5 minutes ago
                        if last_error_time is not None:
                            time_since_last_error = current_time - last_error_time
                            if time_since_last_error > BACKOFF_RESET_SECONDS:
                                backoff_delay = 1

                        print(f"Rate limited (429), retrying in {backoff_delay}s...")
                        time.sleep(backoff_delay)

                        # Update backoff state
                        last_error_time = time.time()
                        backoff_delay = min(backoff_delay * 2, MAX_BACKOFF_SECONDS)

                        # Remove failed download from aria2c
                        try:
                            api.remove([download])
                        except Exception:
                            pass

                        # Re-queue the download
                        url_to_gid[url] = queue_download(url)
                    else:
                        raise RuntimeError(f"Download failed for {url}: {error_msg}")
            else:
                # Download not in list - check if file exists (completed and purged)
                if file_path.exists() and file_path.stat().st_size > 0:
                    results[url] = file_path
                    pending_urls.remove(url)
                    completed += 1
                    print(f"[{completed}/{total}] Downloaded: {url}")

    return results


# =============================================================================
# Argument Parsing and Validation
# =============================================================================

def parse_arguments() -> argparse.Namespace:
    """Parse command line arguments."""
    parser = argparse.ArgumentParser(
        description="Process Windows Driver Kit DDI or Win32 API reference documentation"
    )
    parser.add_argument(
        "--repository",
        required=True,
        choices=list(DOCS_REPOSITORY_INFO.keys()),
        help="Name of the documentation repository"
    )
    parser.add_argument(
        "--input",
        required=True,
        help="Path to the repository directory",
    )
    parser.add_argument(
        "--output",
        required=True,
        help="Output directory for processed files"
    )
    parser.add_argument(
        "--previous-output",
        help="Path to folder with previous output. If provided, .c files will be reused"
    )
    parser.add_argument(
        "--input-filter",
        help="Filter to only process files containing this string in their filename"
    )
    return parser.parse_args()


def check_aria2c_installation():
    """Check if aria2c is installed, exit with error if not."""
    if shutil.which('aria2c') is None:
        print("Error: aria2c not found. Please install aria2:")
        print("  - Windows: winget install aria2")
        print("  - macOS: brew install aria2")
        print("  - Linux: apt install aria2")
        sys.exit(1)


def create_config(args: argparse.Namespace) -> ScraperConfig:
    """Create scraper configuration from parsed arguments."""
    repo_info = DOCS_REPOSITORY_INFO[args.repository]
    input_path = Path(args.input)
    output_path = Path(args.output)
    content_dir = input_path / repo_info.content_path

    # Validate paths
    if not input_path.exists():
        raise RuntimeError(f"Error: Input directory does not exist: {input_path}")
    if not content_dir.exists():
        raise RuntimeError(f"Error: Content directory does not exist: {content_dir}")

    # Create output directory
    output_path.mkdir(parents=True, exist_ok=True)

    return ScraperConfig(
        input_path=input_path,
        output_path=output_path,
        content_dir=content_dir,
        base_url=repo_info.base_url,
        repo_type=repo_info.type,
        previous_output_path=Path(args.previous_output) if args.previous_output else None,
        input_filter=args.input_filter,
    )


# =============================================================================
# File Collection
# =============================================================================

def collect_markdown_files(config: ScraperConfig) -> Tuple[List[Path], int]:
    """
    Collect and filter markdown files from content directory.

    Returns tuple of (filtered_files, ignored_count).
    """
    all_files = list(config.content_dir.rglob("*.md"))
    filtered_files = []
    ignored_count = 0

    for md_file in all_files:
        base_name = md_file.stem

        # Skip index and toc files
        if base_name.lower() in ['index', 'toc']:
            ignored_count += 1
            continue

        # Apply organized repo filtering
        if config.repo_type == DocsRepositoryType.ORGANIZED:
            if '-' not in base_name:
                raise RuntimeError(f"Filename does not contain a dash: {md_file}")

            prefix = base_name.split('-', 1)[0]

            # Skip unsupported prefixes (na: header, nl: class, nn: interface)
            if prefix in ['na', 'nl', 'nn']:
                ignored_count += 1
                continue

            # Validate known prefixes (nc: callback, ne: enum, nf: function, ni: IOCTL, ns: struct)
            if prefix not in ['nc', 'ne', 'nf', 'ni', 'ns']:
                raise RuntimeError(f"Unknown file prefix '{prefix}' in file: {base_name}")

        filtered_files.append(md_file)

    # Apply input filter if provided
    if config.input_filter:
        filtered_files = [
            f for f in filtered_files
            if config.input_filter.lower() in f.stem.lower()
        ]

    if not filtered_files:
        raise RuntimeError(f"No valid markdown files found in: {config.content_dir}")

    return filtered_files, ignored_count


def collect_urls_to_download(
    markdown_files: List[Path],
    config: ScraperConfig,
) -> Tuple[List[str], Dict[Path, str]]:
    """
    Collect URLs that need to be downloaded.

    Returns tuple of (urls_list, md_file_to_url_map).
    """
    urls = []
    md_file_to_url = {}

    # Only ORGANIZED repos need downloads (FUZZY repos extract code from markdown)
    if config.repo_type != DocsRepositoryType.ORGANIZED:
        return urls, md_file_to_url

    for md_file in markdown_files:
        base_name = md_file.stem
        relative_path = md_file.relative_to(config.content_dir)

        # Skip IOCTL files (ni- prefix)
        if base_name.startswith('ni-'):
            continue

        # Skip if we have previous output
        if config.previous_output_path:
            previous_c_file = config.previous_output_path / relative_path.parent / f"{base_name}.c"
            if previous_c_file.exists():
                continue

        url = get_online_url_from_file_path(str(relative_path), config.base_url)
        urls.append(url)
        md_file_to_url[md_file] = url

    return urls, md_file_to_url


# =============================================================================
# URL and Path Utilities
# =============================================================================

def get_online_url_from_file_path(file_path: str, base_url: str) -> str:
    """Convert file path to online documentation URL."""
    rel_path = Path(file_path).as_posix().lower()

    if rel_path.endswith('.md'):
        rel_path = rel_path[:-3]

    rel_path = rel_path.replace(',', '_').replace('&', '_').replace('~', '-').replace(' ', '')
    rel_path = quote(rel_path, safe='/')

    if not base_url.endswith('/'):
        base_url += '/'

    return urljoin(base_url, rel_path)


# =============================================================================
# HTML and Markdown Processing
# =============================================================================

def html_escape(html: str) -> str:
    """Escape HTML special characters."""
    return (
        html.replace('&', '&amp;')
        .replace('<', '&lt;')
        .replace('>', '&gt;')
        .replace('"', '&quot;')
        .replace("'", '&#39;')
    )


def extract_yaml_frontmatter(content: str) -> Tuple[Dict, str]:
    """
    Extract YAML front matter from markdown content.

    Returns tuple of (metadata_dict, content_without_frontmatter).
    """
    # Skip UTF-8 BOM if present.
    if content.startswith('\ufeff'):
        content = content[1:]

    # Check if content starts with YAML front matter.
    if not content.startswith('---'):
        raise RuntimeError("No YAML front matter found")

    # Find the end of the front matter.
    lines = content.split('\n')
    end_idx = None
    for i, line in enumerate(lines[1:], 1):
        if line.strip() == '---':
            end_idx = i
            break

    if end_idx is None:
        raise RuntimeError("YAML front matter not closed with '---'")

    # Extract YAML front matter.
    yaml_content = '\n'.join(lines[1:end_idx])
    remaining_content = '\n'.join(lines[end_idx + 1:]).lstrip('\n')

    metadata = yaml.safe_load(yaml_content)
    return metadata, remaining_content


def clean_markdown_content(content_url: str, content: str) -> str:
    """
    Clean markdown content by converting HTML tags to markdown.

    Handles Microsoft-specific markdown conventions and normalizes formatting.
    """
    # Replace nbsp with regular space.
    content = content.replace('\u00a0', ' ')

    # Remove newlines between table rows which can break tables.
    content = re.sub(r'</tr>\s+<tr>', '</tr><tr>', content)

    # Normalize newlines to <br>, a mix of <br> and <br/> causes issues for
    # markdownify.
    content = re.sub(r'(<br)\s*/>', r'\1>', content, flags=re.IGNORECASE)

    # Apply text replacements to standardize markdown section headers. These
    # patterns clean up Microsoft-specific markdown conventions.
    replacements = [
        (r"^(#+) +- *description *$", r"\1 Description"),
        (r"^(#+) +- *enum-fields *$", r"\1 Constants"),
        (r"^(#+) +- *parameters *$", r"\1 Parameters"),
        (r"^(#+) +- *prototype *$", r"\1 Prototype"),
        (r"^(#+) +- *remarks *$", r"\1 Remarks"),
        (r"^(#+) +- *requirements *$", r"\1 Requirements"),
        (r"^(#+) +- *returns *$", r"\1 Return value"),
        (r"^(#+) +- *see-also *$", r"\1 See also"),
        (r"^(#+) +- *struct-fields *$", r"\1 Members"),
        (r"^(#+) +- *syntax *$", r"\1 Syntax"),
        (r"^(#+) +- *field +(\S+)", r"\1 `\2`"),
        (r"^(#+) +- *param +(\S+)", r"\1 `\2`"),
        # IOCTL stuff.
        (r"^(#+) +- *in-out-buffer *$", r"\1 Input/output buffer"),
        (r"^(#+) +- *inout-buffer-length *$", r"\1 Input/output buffer length"),
        (r"^(#+) +- *input-buffer *$", r"\1 Input buffer"),
        (r"^(#+) +- *input-buffer-length *$", r"\1 Input buffer length"),
        (r"^(#+) +- *ioctl-major-code *$", r"\1 Major code"),
        (r"^(#+) +- *ioctlparameters *$", r"\1 Parameters"),
        (r"^(#+) +- *output-buffer *$", r"\1 Output buffer"),
        (r"^(#+) +- *output-buffer-length *$", r"\1 Output buffer length"),
        (r"^(#+) +- *status-block *$", r"\1 Status block"),
    ]

    for pattern, replacement in replacements:
        content = re.sub(pattern, replacement, content, flags=re.MULTILINE)

    # Remove <dl><dt>...</dt></dl> in table cells (mainly in win32).
    def remove_dl_dt_sub(match: re.Match) -> str:
        begin = match.group(1)
        dt_content = match.group(2)
        end = match.group(3)
        dt_content = re.sub(r'</dt>\s*<dt>', Nonce.TableBr, dt_content)
        return f'|{begin}{dt_content}{end}|'

    content = re.sub(r'\|(.*?)<dl>\s*<dt>\s*(.*?)\s*</dt>\s*</dl>(.*?)\|', remove_dl_dt_sub, content)

    # Remove brackets in links.
    content = re.sub(r'\[([\s\S]*?)\]\(<([^)]+)>\)', r'[\1](\2)', content)

    # Make more html-to-markdown friendly by surrounding code blocks with <pre>
    # to prevent space removal. Yes, this is a horrible hack.
    def backticks_sub(match: re.Match) -> str:
        match_content = match.group(0)
        # html encode content inside backticks to prevent html-to-markdown from
        # interpreting HTML tags inside code blocks.
        match_content = html_escape(match_content)
        start_index = match.start()
        table_open_count = content.count('<table', 0, start_index)
        table_end_count = content.count('</table>', 0, start_index)
        if table_open_count > table_end_count:
            # Inside a table, do not add nonce. Tables force single line.
            return match_content
        if '\n' not in match_content:
            # Inline code, do not add nonce.
            return match_content
        return f'```{Nonce.PreCodeBlock1}<pre>{match_content}</pre>```{Nonce.PreCodeBlock2}'

    content = re.sub(r'```[\s\S]*?```', backticks_sub, content)

    # Escape inline code blocks.
    def inline_code_sub(match: re.Match) -> str:
        beginning = match.group(1)
        ending = match.group(3)
        if beginning != '`' or ending != '`':
            # Only escape single backtick inline code.
            return match.group(0)

        code_content = match.group(2)
        code_content = html_escape(code_content)
        return f'{beginning}{code_content}{ending}'

    content = re.sub(r'(`+)(.*?)(`+)', inline_code_sub, content)

    # Escape all < symbols that are not part of HTML tags or comments.
    regex_bracket_not_html_tag = (
        r'(<)(?!/?(?:a|abbr|acronym|b|blockquote|br|caption|code|col|colgroup|dd'
        r'|del|details|div|dl|dt|em|figcaption|figure|h[1-6]|hr|i|img|kbd|li'
        r'|mark|ol|p|pre|q|s|samp|section|small|span|strong|sub|sup|table|tbody'
        r'|td|tfoot|th|thead|tr|u|ul)\b|!--)(/)?'
    )
    content = re.sub(regex_bracket_not_html_tag, r'&lt;\2', content, flags=re.IGNORECASE)

    # Make more html-to-markdown friendly by ensuring paragraphs are properly
    # separated and not collapsed together.
    def newlines_sub(match: re.Match) -> str:
        start_index = match.start()
        pre_open_count = content.count('<pre', 0, start_index)
        pre_end_count = content.count('</pre>', 0, start_index)
        if pre_open_count > pre_end_count:
            # Inside a pre block, do not add paragraph tags.
            return match.group(0)
        # A hack for a two-newline separator.
        return '<caption></caption>'

    content = re.sub(r'\n{2,}', newlines_sub, content)

    # A hack to prevent collapsing leading spaces, which is important for
    # things such as nested lists.
    content = re.sub(
        r'(^|>)( {2,})(?=[-*])',
        lambda m: m.group(1) + Nonce.LeadingSpaces + '<!-- --> ' * len(m.group(2)),
        content,
        flags=re.MULTILINE,
    )

    # Convert HTML tags to markdown. This will convert HTML tags like <strong>,
    # <em>, <code>, etc. to markdown equivalents and remove unsupported HTML
    # tags.
    class CustomMarkdownConverter(MarkdownConverter):
        def convert_td(self, el, text, parent_tags):
            # Convert newlines to <br> to preserve line breaks in table cells.
            # https://stackoverflow.com/a/12119310
            el_html = el.decode_contents()
            el_markdown = self.convert(el_html)
            el_markdown = el_markdown.replace('\n\n', Nonce.TableBr * 2)
            # Escape pipe characters to prevent breaking tables.
            el_markdown = el_markdown.replace('|', '\\|')
            # Best effort to handle lists in table cells.
            el_markdown = el_markdown.replace('\n* ', Nonce.TableBr + '* ')
            el_markdown = el_markdown.replace('\n- ', Nonce.TableBr + '- ')
            el_markdown = el_markdown.replace('\n', ' ')
            colspan = int(el.get('colspan', 1))
            return ' ' + el_markdown.strip() + ' |' * colspan

        def convert_dd(self, el, text, parent_tags):
            # convert_dd adds a colon with spaces. We don't want that.
            return self.convert_div(el, text, parent_tags)

    cleaned_content = CustomMarkdownConverter(
        newline_style='BACKSLASH',
        escape_asterisks=False,
        escape_underscores=False,
        escape_misc=False,
    ).convert(content)

    # Remove the pre nonces.
    cleaned_content = re.sub(rf' *```{re.escape(Nonce.PreCodeBlock1)}\n *\n *```\n', '', cleaned_content)
    cleaned_content = re.sub(rf'\n *```\n *\n *```{re.escape(Nonce.PreCodeBlock2)}', '', cleaned_content)
    assert Nonce.PreCodeBlock1 not in cleaned_content
    assert Nonce.PreCodeBlock2 not in cleaned_content

    # Remove the leading spaces nonce.
    cleaned_content = cleaned_content.replace(Nonce.LeadingSpaces, '')

    # Escape all < symbols that are not part of HTML tags. We also did this
    # before html-to-markdown, but html-to-markdown may introduce new < symbols
    # by converting &lt; back to <.
    def markdown_escape_sub(match: re.Match) -> str:
        # Skip if inside a code block.
        triple_backtick_count = cleaned_content.count('```', 0, match.start())
        if triple_backtick_count % 2 == 1:
            return match.group(0)

        # Skip if line inside of an inline code span.
        line_start = cleaned_content.rfind('\n', 0, match.start()) + 1
        backtick_count = cleaned_content.count('`', line_start, match.start())
        if backtick_count % 2 == 1:
            return match.group(0)

        # Skip if escaped with an odd number of backslashes.
        preceding_text = cleaned_content[:match.start()]
        trailing_backslashes = 0
        for char in reversed(preceding_text):
            if char == '\\':
                trailing_backslashes += 1
            else:
                break
        if trailing_backslashes % 2 == 1:
            return match.group(0)

        return '\\' + match.group(1) + (match.group(2) or '')

    cleaned_content = re.sub(
        r'(<)(?=/?[a-z]|!--)(/)?',
        markdown_escape_sub,
        cleaned_content,
        flags=re.IGNORECASE,
    )

    cleaned_content = re.sub(
        r'(&)(?=[a-z#]\w=;)()',
        markdown_escape_sub,
        cleaned_content,
        flags=re.IGNORECASE,
    )

    # Fix links.
    def links_sub(match: re.Match) -> str:
        # Don't touch content inside code blocks.
        triple_backtick_count = cleaned_content.count('```', 0, match.end())
        if triple_backtick_count % 2 == 1:
            return match.group(0)

        text = match.group(1)
        url = match.group(2).strip()

        url = url.replace('\\', '/')
        url = urljoin(content_url, url)
        if url.startswith('https://learn.microsoft.com/'):
            url = re.sub(r'/index(\.md|\.yml)?(?=#|$)', '/', url)
            url = re.sub(r'\.md(?=#|$)', '', url)

        return f'[{text}]({url})'

    cleaned_content = re.sub(r'\[([\s\S]*?)\]\(([^)]+)\)', links_sub, cleaned_content)

    # Replace table <br> nonces with actual <br>.
    cleaned_content = cleaned_content.replace(Nonce.TableBr, '<br>')

    # Fix pre-existing markdown tables with <br> newlines which were converted
    # to actual newlines and broke the table.
    def markdown_table_sub(match: re.Match) -> str:
        # Don't touch content inside code blocks.
        triple_backtick_count = cleaned_content.count('```', 0, match.start())
        if triple_backtick_count % 2 == 1:
            return match.group(0)

        table_text = match.group(0)
        table_text = table_text.replace('\\\n', '<br>')
        return table_text

    cleaned_content = re.sub(r'^\s*\|([^\n]*\\\n)+', markdown_table_sub, cleaned_content, flags=re.MULTILINE)

    # Remove trailing spaces on lines.
    cleaned_content = re.sub(r' +$', '', cleaned_content, flags=re.MULTILINE)

    # Remove excessive newlines (more than 2).
    cleaned_content = re.sub(r'\n{3,}', '\n\n', cleaned_content)
    cleaned_content = re.sub(r'(<br>){3,}', '<br><br>', cleaned_content)

    return cleaned_content


# =============================================================================
# Prototype Extraction
# =============================================================================

def parse_function_prototype_from_file(html_path: Path, url: str) -> Optional[str]:
    """
    Parse code definition from downloaded HTML file.

    Finds the first code block that follows the "Syntax" heading.
    Returns empty string if page has no syntax section.
    """
    with open(html_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    soup = BeautifulSoup(content, 'html.parser')

    # Look for the "Syntax" heading using the id attribute
    syntax_heading = soup.find('h2', id='syntax')

    if not syntax_heading:
        # Page exists but has no syntax section - return empty string
        return ""

    # Find the first code block after the syntax heading
    current_element = syntax_heading
    prototype = None

    while current_element:
        current_element = current_element.find_next_sibling()
        if not current_element:
            break

        # Skip text nodes
        if isinstance(current_element, NavigableString):
            continue

        if not isinstance(current_element, Tag):
            continue

        # Look for code blocks in this element
        code_blocks = current_element.find_all(['code', 'pre'])
        for block in code_blocks:
            text = block.get_text().strip()
            if text:  # Return the first non-empty code block
                prototype = text
                break

        if prototype:
            break

        # Check if this element itself is a code block
        if current_element.name in ['code', 'pre']:
            text = current_element.get_text().strip()
            if text:  # Return the first non-empty code block
                prototype = text
                break

        # Stop at the next heading
        if current_element.name and current_element.name.startswith('h'):
            break

    if not prototype:
        raise RuntimeError(f"No code block found after 'Syntax' heading in {url}")

    # Replace nbsp with regular space
    prototype = prototype.replace('\u00a0', ' ')

    return prototype


# =============================================================================
# Fuzzy Document Processing
# =============================================================================

def extract_fuzzy_type_ident(markdown_content: str) -> Tuple[str, str]:
    """Extract identifier and type from fuzzy documentation content."""
    # Best effort to filter relevant pages. Not all pages have reliable
    # metadata such as topic_type, especially in windows-driver-docs.
    fuzzy_types = [
        'callback function',
        'function pointer',
        'control code',
        'enumeration',
        'structure',
        'function',
        'routine',
        'macro',
        'union',
    ]
    fuzzy_types_pattern = '|'.join(re.escape(t) for t in fuzzy_types)
    p = rf'^# (\S+) ({fuzzy_types_pattern})(:? *\([^)]+\.h\))? *$'
    match = re.search(p, markdown_content, flags=re.IGNORECASE | re.MULTILINE)

    if not match:
        raise UnsupportedFuzzyDoc

    fuzzy_ident = match.group(1).replace(R'\_', '_')
    assert isinstance(fuzzy_ident, str)
    if fuzzy_ident.endswith('A/W'):
        fuzzy_ident = fuzzy_ident.removesuffix('A/W') + 'W'

    fuzzy_type = match.group(2)

    # Skip templates/generics
    if '&lt;' in fuzzy_ident:
        raise UnsupportedFuzzyDoc

    # Skip C++ stuff
    if '::' in fuzzy_ident:
        raise UnsupportedFuzzyDoc

    # Skip unsupported identifiers
    if fuzzy_ident in [
        'NOTIFICATION-TYPE',
        'OBJECT-TYPE',
        'TEXTUAL-CONVENTION',
        'TRAP-TYPE',
        'GatherBlue(S,float,int2,int2,int2,int2)',
        'Load2(uint,uint)',
        'Load3(uint,uint)',
        'Load4(uint,uint)',
    ] or fuzzy_ident.startswith(R'MRxLowIOSubmit\['):
        raise UnsupportedFuzzyDoc

    if not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*', fuzzy_ident):
        raise RuntimeError(f"Unsupported identifier '{fuzzy_ident}'")

    return fuzzy_type, fuzzy_ident


def extract_fuzzy_header(markdown_content: str) -> Optional[str]:
    """Extract header file from fuzzy documentation content."""
    p = r'^\|\s*Header(?:<br\s*/?>)?\s*\|(.*)'
    match = re.search(p, markdown_content, flags=re.IGNORECASE | re.MULTILINE)

    if not match:
        p = r'^\*\*Header:\*\* (.*)'
        match = re.search(p, markdown_content, flags=re.IGNORECASE | re.MULTILINE)

    if not match:
        p = r'<td[^>]*><p>Header</p></td>\s*<td[^>]*>\s*(.*)'
        match = re.search(p, markdown_content, flags=re.IGNORECASE)

    if not match:
        return None

    header = match.group(1)
    header = re.sub(r'<[^>]+>', '', header)  # Remove HTML tags
    header = header.strip().lstrip('*').strip()
    match = re.match(r'([A-Za-z0-9_./-]+\.h)\b', header, flags=re.IGNORECASE)
    if not match:
        return None

    header = match.group(1)
    return header.lower()


# =============================================================================
# File Processing
# =============================================================================

def process_markdown_file(
    relative_path: Path,
    input_dir: Path,
    output_dir: Path,
    base_url: str,
    repo_type: DocsRepositoryType,
    previous_output_dir: Optional[Path] = None,
    downloaded_html_path: Optional[Path] = None,
) -> bool:
    """
    Process a single markdown file.

    Returns True if code was extracted, False otherwise.
    """
    url = get_online_url_from_file_path(str(relative_path), base_url)

    # Construct the full input file path
    input_file = input_dir / relative_path

    # Read the input file
    with open(input_file, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    # Extract YAML front matter
    metadata, markdown_content = extract_yaml_frontmatter(content)

    # For fuzzy repos, try to extract identifier and code definition
    fuzzy_code_definition = None
    if repo_type == DocsRepositoryType.FUZZY:
        if metadata.get('ms.topic') != 'reference':
            raise UnsupportedFuzzyDoc

        fuzzy_type, fuzzy_ident = extract_fuzzy_type_ident(markdown_content)
        metadata['_fuzzy_type'] = fuzzy_type
        metadata['_fuzzy_ident'] = fuzzy_ident

        if fuzzy_header := extract_fuzzy_header(markdown_content):
            metadata['_fuzzy_header'] = fuzzy_header

        p = r'^#+ Syntax *$\n\s*```.*\n([\s\S]+?)```'
        match = re.search(p, markdown_content, flags=re.IGNORECASE | re.MULTILINE)
        if match:
            fuzzy_code_definition = match.group(1).strip()
            markdown_content = markdown_content[:match.start(0)] + markdown_content[match.end(0):]

    # Clean markdown content (remove HTML tags, etc.)
    clean_content = clean_markdown_content(url, markdown_content)

    # Create output directory structure using the relative path
    output_subdir = output_dir / relative_path.parent
    output_subdir.mkdir(parents=True, exist_ok=True)

    # File base name without extension
    base_name = relative_path.stem

    # Save cleaned markdown
    md_output = output_subdir / f"{base_name}.md"
    with open(md_output, 'w', encoding='utf-8') as f:
        f.write(clean_content)

    # Save metadata as JSON
    if metadata:
        json_output = output_subdir / f"{base_name}.json"
        with open(json_output, 'w', encoding='utf-8') as f:
            json.dump(metadata, f, indent=2, ensure_ascii=False)

    # Try to scrape function prototype or code definition
    prototype = None

    # Check if we can reuse from previous output
    if previous_output_dir:
        previous_c_file = previous_output_dir / relative_path.parent / f"{base_name}.c"
        if previous_c_file.exists():
            # Read the existing .c file
            with open(previous_c_file, 'r', encoding='utf-8') as f:
                prototype = f.read()

    # If we didn't find a previous file
    if prototype is None:
        if repo_type == DocsRepositoryType.ORGANIZED:
            # Skip scraping for IOCTL files
            if not base_name.startswith('ni-') and downloaded_html_path is not None:
                prototype = parse_function_prototype_from_file(downloaded_html_path, url)
        elif repo_type == DocsRepositoryType.FUZZY:
            if fuzzy_code_definition is not None:
                prototype = fuzzy_code_definition

    # Save the prototype if we found one
    if prototype is not None:
        # Replace nbsp with regular space.
        prototype = prototype.replace('\u00a0', ' ')

        c_output = output_subdir / f"{base_name}.c"

        with open(c_output, 'w', encoding='utf-8') as f:
            f.write(prototype)

        return True

    return False


def process_file_worker(args: WorkerArgs) -> Tuple[ProcessingResult, str, Optional[str]]:
    """Worker function for parallel processing of markdown files."""
    relative_path = args.md_file.relative_to(args.content_dir)
    base_name = relative_path.stem

    try:
        code_success = process_markdown_file(
            relative_path,
            args.content_dir,
            args.output_path,
            args.base_url,
            args.repo_type,
            args.previous_output_path,
            args.downloaded_html_path,
        )
        if code_success:
            return (ProcessingResult.CODE_EXTRACTED, base_name, None)
        else:
            return (ProcessingResult.NO_CODE, base_name, None)
    except UnsupportedFuzzyDoc:
        return (ProcessingResult.UNSUPPORTED, base_name, None)
    except Exception:
        return (ProcessingResult.ERROR, base_name, traceback.format_exc())


def create_worker_args(
    markdown_files: List[Path],
    config: ScraperConfig,
    md_file_to_url: Dict[Path, str],
    download_results: Dict[str, Path],
) -> List[WorkerArgs]:
    """Create WorkerArgs for each markdown file."""
    total = len(markdown_files)
    worker_args = []

    for i, md_file in enumerate(markdown_files, 1):
        url = md_file_to_url.get(md_file)
        downloaded_html_path = download_results.get(url) if url else None

        worker_args.append(WorkerArgs(
            index=i,
            total=total,
            md_file=md_file,
            content_dir=config.content_dir,
            output_path=config.output_path,
            base_url=config.base_url,
            repo_type=config.repo_type,
            previous_output_path=config.previous_output_path,
            downloaded_html_path=downloaded_html_path,
        ))

    return worker_args


def process_files_parallel(
    worker_args: List[WorkerArgs],
    num_workers: int,
) -> ProcessingStats:
    """Process files in parallel and return statistics."""
    stats = ProcessingStats()
    total = len(worker_args)
    processed_count = 0

    with multiprocessing.Pool(processes=num_workers) as pool:
        for result in pool.imap_unordered(process_file_worker, worker_args):
            result_type, base_name, error_trace = result
            processed_count += 1

            if result_type == ProcessingResult.CODE_EXTRACTED:
                print(f"[{processed_count}/{total}] Processing {base_name}... OK")
                stats.code_extracted += 1
            elif result_type == ProcessingResult.NO_CODE:
                print(f"[{processed_count}/{total}] Processing {base_name}... No code extracted")
                stats.code_not_extracted += 1
            elif result_type == ProcessingResult.ERROR:
                print(error_trace)
                print(f"[{processed_count}/{total}] Processing {base_name}... Error, exception raised")
                stats.errors += 1
            elif result_type == ProcessingResult.UNSUPPORTED:
                stats.unsupported += 1

    return stats


# =============================================================================
# Main Entry Point
# =============================================================================

def main():
    """Main entry point."""
    args = parse_arguments()
    check_aria2c_installation()
    config = create_config(args)

    # Collect files
    markdown_files, ignored_count = collect_markdown_files(config)
    print(f"Found {len(markdown_files)} markdown files to process ({ignored_count} files ignored)")

    # Collect URLs to download
    urls_to_download, md_file_to_url = collect_urls_to_download(markdown_files, config)

    # Download and process
    download_dir = tempfile.mkdtemp(prefix='scraper_downloads_')
    try:
        download_results = {}

        if urls_to_download:
            print(f"Downloading {len(urls_to_download)} pages using aria2c...")
            with aria2_downloader(download_dir) as api:
                download_results = batch_download_urls(api, urls_to_download, Path(download_dir))
            print("Downloads complete. Processing files...")

        # Process files
        num_workers = os.cpu_count() or 1
        print(f"Using {num_workers} worker processes")

        worker_args = create_worker_args(
            markdown_files, config, md_file_to_url, download_results
        )
        stats = process_files_parallel(worker_args, num_workers)
        stats.print_summary(config.output_path)

    finally:
        shutil.rmtree(download_dir, ignore_errors=True)


if __name__ == "__main__":
    main()
