#!/usr/bin/env python3
"""
Windows Docs Scraper

A Python script that processes Windows Driver Kit DDI or Win32 API reference
documentation, extracting metadata, cleaning markdown content, and scraping
function prototypes from online documentation.
"""

import argparse
import json
import multiprocessing
import os
import re
import time
import traceback
import uuid
from dataclasses import dataclass
from enum import IntEnum, auto
from pathlib import Path
from typing import Dict, Optional, Tuple
from urllib.parse import quote, urljoin

import requests
import yaml
from bs4 import BeautifulSoup, Tag
from bs4.element import NavigableString
from markdownify import MarkdownConverter


class Nonce:
    """Global nonce values used for temporary markers in content processing."""
    PreCodeBlock1 = f'PRE_NONCE_1_{uuid.uuid4().hex.upper()}'
    PreCodeBlock2 = f'PRE_NONCE_2_{uuid.uuid4().hex.upper()}'
    LeadingSpaces = f'LEADING_SPACES_NONCE_{uuid.uuid4().hex.upper()}'
    TableBr = f'TABLE_BR_NONCE_{uuid.uuid4().hex.upper()}'


class DocsRepositoryType(IntEnum):
    # With file name prefixes and more-or-less organized structure and metadata.
    ORGANIZED = auto()

    # Without file name prefixes and less organized structure and metadata.
    FUZZY = auto()


class ProcessingResult(IntEnum):
    """Result types from processing a markdown file."""
    CODE_EXTRACTED = auto()
    NO_CODE = auto()
    UNSUPPORTED = auto()
    ERROR = auto()


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


class UnsupportedFuzzyDoc(Exception):
    """Raised when a fuzzy documentation page is unsupported for processing."""

    pass


REQUESTS_SESSION = requests.Session()
REQUESTS_SESSION.headers.update({
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36'
})


def html_escape(html: str) -> str:
    """
    Returns the given HTML with ampersands, quotes and carets encoded.
    https://stackoverflow.com/a/275246
    """
    return (
        html.replace('&', '&amp;')
        .replace('<', '&lt;')
        .replace('>', '&gt;')
        .replace('"', '&quot;')
        .replace("'", '&#39;')
    )


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
        help="Path to folder with previous output. If provided, .c files will be reused instead of contacting Microsoft server"
    )
    parser.add_argument(
        "--input-filter",
        help="Filter to only process files containing this string in their filename (e.g., 'nc-sercx-evt_sercx_apply_config')"
    )
    return parser.parse_args()


def extract_yaml_frontmatter(content: str) -> Tuple[Dict, str]:
    """
    Extract YAML front matter from markdown content.

    Returns:
        Tuple of (metadata_dict, content_without_frontmatter)
    """
    # Skip UTF-8 BOM if present
    if content.startswith('\ufeff'):
        content = content[1:]

    # Check if content starts with YAML front matter
    if not content.startswith('---'):
        raise RuntimeError("No YAML front matter found")

    # Find the end of the front matter
    lines = content.split('\n')
    end_idx = None
    for i, line in enumerate(lines[1:], 1):
        if line.strip() == '---':
            end_idx = i
            break

    if end_idx is None:
        raise RuntimeError("YAML front matter not closed with '---'")

    # Extract YAML front matter
    yaml_content = '\n'.join(lines[1:end_idx])
    remaining_content = '\n'.join(lines[end_idx + 1:]).lstrip('\n')

    metadata = yaml.safe_load(yaml_content)
    return metadata, remaining_content


def clean_markdown_content(content_url: str, content: str) -> str:
    """
    Clean markdown content by converting HTML tags to markdown and removing unsupported tags.

    Args:
        content: Raw markdown content that may contain HTML tags

    Returns:
        Cleaned markdown content with HTML converted to markdown
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
        return f'<caption></caption>'

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


def get_online_url_from_file_path(file_path: str, base_url: str) -> str:
    """
    Extract the online documentation URL from file path.
    """
    # Construct from file path
    # Example: ntifs/nf-ntifs-ntwritefile.md ->
    # https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntwritefile
    rel_path = Path(file_path).as_posix().lower()

    # Remove .md extension
    if rel_path.endswith('.md'):
        rel_path = rel_path[:-3]

    rel_path = rel_path.replace(',', '_').replace('&', '_').replace('~', '-').replace(' ', '')

    # URL encode the path to handle special characters like %
    rel_path = quote(rel_path, safe='/')

    if not base_url.endswith('/'):
        base_url += '/'

    return urljoin(base_url, rel_path)


def scrape_function_prototype(url: str) -> Optional[str]:
    """
    Scrape code definition from online documentation.
    Finds the first code block that follows the "Syntax" heading.
    Returns empty string if page exists but has no syntax section.
    Returns None only for actual errors (404, network issues, etc).
    """

    while True:
        try:
            response = REQUESTS_SESSION.get(url, timeout=10)
            if response.status_code == 404:
                print(f"Error, page not found (404): {url}")
                return None

            response.raise_for_status()
            break
        except Exception as e:
            print(f"Error getting {url}, will retry: {e}")
            time.sleep(5)

    soup = BeautifulSoup(response.content, 'html.parser')

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


def extract_fuzzy_type_ident(markdown_content: str) -> Tuple[str, str]:
    """
    Extract identifier from fuzzy documentation content.

    Args:
        markdown_content: The markdown content to extract identifier from

    Returns:
        The extracted identifier

    Raises:
        UnsupportedFuzzyDoc: If the document doesn't contain a supported identifier
        RuntimeError: If the identifier format is not supported
    """
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

    # Replace escaped underscores produced by some markdown sources (e.g., Foo\_Bar -> Foo_Bar)
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
    """
    Extract header file from fuzzy documentation content.

    Args:
        markdown_content: The markdown content to extract header from
    
    Returns:
        The extracted header file, or None if not found
    """
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


def process_markdown_file(
    relative_path: Path,
    input_dir: Path,
    output_dir: Path,
    base_url: str,
    repo_type: DocsRepositoryType,
    previous_output_dir: Optional[Path] = None,
) -> bool:
    """
    Process a single markdown file.

    Args:
        relative_path: Path relative to the content directory (e.g., 'ntifs/nf-ntifs-ntwritefile.md')
        input_dir: Path to the input content directory
        output_dir: Path to the output directory
        base_url: Base URL for the online documentation
        repo_type: Type of the documentation repository (organized or fuzzy)
        previous_output_dir: Optional path to previous output directory for reusing .c files

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
            if not base_name.startswith('ni-'):
                prototype = scrape_function_prototype(url)
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
    else:
        return False


def process_file_worker(args: WorkerArgs):
    """
    Worker function for parallel processing of markdown files.

    Args:
        args: WorkerArgs dataclass containing all necessary parameters

    Returns:
        Tuple of (ProcessingResult, base_name, error_traceback)
    """
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
        )
        if code_success:
            return (ProcessingResult.CODE_EXTRACTED, base_name, None)
        else:
            return (ProcessingResult.NO_CODE, base_name, None)
    except UnsupportedFuzzyDoc:
        return (ProcessingResult.UNSUPPORTED, base_name, None)
    except Exception as e:
        return (ProcessingResult.ERROR, base_name, traceback.format_exc())


def main():
    """Main function."""
    args = parse_arguments()

    # Get repository info
    repo_info = DOCS_REPOSITORY_INFO[args.repository]
    content_path = repo_info.content_path
    base_url = repo_info.base_url
    repo_type = repo_info.type

    input_path = Path(args.input)
    output_path = Path(args.output)
    previous_output_path = Path(args.previous_output) if args.previous_output else None
    input_filter = args.input_filter

    # Validate input directory
    if not input_path.exists():
        raise RuntimeError(f"Error: Input directory does not exist: {input_path}")

    # Create output directory
    output_path.mkdir(parents=True, exist_ok=True)

    # Find all markdown files in the content directory
    content_dir = input_path / content_path
    if not content_dir.exists():
        raise RuntimeError(f"Error: Content directory does not exist: {content_dir}")

    markdown_files = list(content_dir.rglob("*.md"))

    # Filter out unsupported prefix files and index.md files
    filtered_files = []
    ignored_count = 0

    for md_file in markdown_files:
        base_name = md_file.stem

        if base_name.lower() in ['index', 'toc']:
            ignored_count += 1
            continue

        if repo_type == DocsRepositoryType.ORGANIZED:
            if '-' not in base_name:
                raise RuntimeError(f"Filename does not contain a dash: {md_file}")

            prefix = base_name.split('-', 1)[0]

            # Skip unsupported files
            # na: header
            # nl: class
            # nn: interface
            if prefix in ['na', 'nl', 'nn']:
                ignored_count += 1
                continue

            # Check for unknown prefixes and throw exception
            # nc: callback
            # ne: enum
            # nf: function
            # ni: IOCTL
            # ns: struct
            if prefix not in ['nc', 'ne', 'nf', 'ni', 'ns']:
                raise RuntimeError(f"Unknown file prefix '{prefix}' in file: {base_name}")

        filtered_files.append(md_file)

    markdown_files = filtered_files

    # Apply input filter if provided
    if input_filter:
        markdown_files = [f for f in markdown_files if input_filter.lower() in f.stem.lower()]

    if not markdown_files:
        raise RuntimeError(f"No valid markdown files found in: {content_dir}")

    print(f"Found {len(markdown_files)} markdown files to process ({ignored_count} files ignored)")

    # Determine number of worker processes
    num_workers = os.cpu_count() or 1
    print(f"Using {num_workers} worker processes")

    # Prepare arguments for worker processes
    total = len(markdown_files)
    worker_args = [
        WorkerArgs(
            index=i,
            total=total,
            md_file=md_file,
            content_dir=content_dir,
            output_path=output_path,
            base_url=base_url,
            repo_type=repo_type,
            previous_output_path=previous_output_path,
        )
        for i, md_file in enumerate(markdown_files, 1)
    ]

    # Process files in parallel
    code_extracted = 0
    code_not_extracted = 0
    exception_count = 0
    unsupported_count = 0
    processed_count = 0

    with multiprocessing.Pool(processes=num_workers) as pool:
        # Use imap_unordered for better performance and progress tracking
        for result in pool.imap_unordered(process_file_worker, worker_args):
            result_type, base_name, error_trace = result

            if result_type == ProcessingResult.CODE_EXTRACTED:
                processed_count += 1
                print(f"[{processed_count}/{total}] Processing {base_name}... OK")
                code_extracted += 1
            elif result_type == ProcessingResult.NO_CODE:
                processed_count += 1
                print(f"[{processed_count}/{total}] Processing {base_name}... No code extracted")
                code_not_extracted += 1
            elif result_type == ProcessingResult.ERROR:
                processed_count += 1
                print(error_trace)
                print(f"[{processed_count}/{total}] Processing {base_name}... Error, exception raised")
                exception_count += 1
            elif result_type == ProcessingResult.UNSUPPORTED:
                processed_count += 1
                unsupported_count += 1
                # Silently skip unsupported files (no output)

    print(f"\nProcessing complete:")
    print(f"Code definitions extracted: {code_extracted}")
    print(f"Code definitions not extracted: {code_not_extracted}")
    print(f"Unsupported files skipped: {unsupported_count}")
    print(f"Exceptions raised: {exception_count}")
    print(f"Output directory: {output_path}")


if __name__ == "__main__":
    main()
