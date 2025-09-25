#!/usr/bin/env python3
"""
Windows Docs Scraper

A Python script that processes Windows Driver Kit DDI or Win32 API reference
documentation, extracting metadata, cleaning markdown content, and scraping
function prototypes from online documentation.
"""

import argparse
import json
import re
import time
import traceback
from pathlib import Path
from typing import Dict, Optional, Tuple
from urllib.parse import quote, urljoin

import requests
import yaml
from bs4 import BeautifulSoup, Tag
from bs4.element import NavigableString
from markdownify import MarkdownConverter

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
        "--input",
        required=True,
        help="Path to windows-driver-docs-ddi or sdk-api directory",
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
    parser.add_argument(
        "--content-path",
        default="sdk-api-src/content",
        help="Path to the content directory relative to input directory (default: sdk-api-src/content)"
    )
    parser.add_argument(
        "--base-url",
        default="https://learn.microsoft.com/windows/win32/api/",
        help="Base URL for the online documentation (default: https://learn.microsoft.com/windows/win32/api/)"
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

    # Special cases.
    if (
        content_url.endswith('/ntddrilapitypes/ns-ntddrilapitypes-rilpositioninfogsm') or
        content_url.endswith('/ntddrilapitypes/ns-ntddrilapitypes-rilgsmnmr')
    ):
        unescaped = "(x=0, RSS < -110dBm\n\nx=63, RSS > -49dBm\n\n0 <x <63, -110+x < RSS < -109+x)"
        content = content.replace(unescaped, html_escape(unescaped))
    elif content_url.endswith('/ws2spi/nc-ws2spi-lpwspioctl'):
        content = content.replace('\n| <dl> <dt>', '\n| ')

    # Remove brackets in links.
    content = re.sub(r'\[([\s\S]*?)\]\(<([^)]+)>\)', r'[\1](\2)', content)

    # Make more html-to-markdown friendly by surrounding code blocks with <pre>
    # to prevent space removal. Yes, this is a horrible hack.
    pre_nonce_1 = '```PRE_NONCE_1_0008D8C0'
    pre_nonce_2 = '```PRE_NONCE_2_E8E8C3EF'
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
        return f'{pre_nonce_1}<pre>{match_content}</pre>{pre_nonce_2}'

    content = re.sub(r'```[\s\S]*?```', backticks_sub, content)

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
    leading_spaces_nonce = 'LEADING_SPACES_NONCE_26017BFF'
    content = re.sub(r'(^|>)( {2,})(?=[-*])', lambda m: m.group(1) + leading_spaces_nonce + '<!-- --> ' * len(m.group(2)), content, flags=re.MULTILINE)

    # Convert HTML tags to markdown. This will convert HTML tags like <strong>,
    # <em>, <code>, etc. to markdown equivalents and remove unsupported HTML
    # tags.
    class CustomMarkdownConverter(MarkdownConverter):
        def convert_td(self, el, text, parent_tags):
            # Convert newlines to <br> to preserve line breaks in table cells.
            # https://stackoverflow.com/a/12119310
            el_html = el.decode_contents()
            el_markdown = self.convert(el_html)
            el_markdown = el_markdown.replace('\n\n', '<br><br>')
            # Best effort to handle lists in table cells.
            el_markdown = el_markdown.replace('\n* ', '<br>* ')
            el_markdown = el_markdown.replace('\n- ', '<br>- ')
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
    cleaned_content = re.sub(rf' *{pre_nonce_1}\n *\n *```\n', '', cleaned_content)
    cleaned_content = re.sub(rf'\n *```\n *\n *{pre_nonce_2}', '', cleaned_content)
    assert pre_nonce_1 not in cleaned_content
    assert pre_nonce_2 not in cleaned_content

    # Remove the leading spaces nonce.
    cleaned_content = cleaned_content.replace(leading_spaces_nonce, '')

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
    rel_path = Path(file_path).as_posix()

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


def process_markdown_file(
    relative_path: Path,
    input_dir: Path,
    output_dir: Path,
    base_url: str,
    previous_output_dir: Optional[Path] = None,
) -> bool:
    """
    Process a single markdown file.

    Args:
        relative_path: Path relative to the content directory (e.g., 'ntifs/nf-ntifs-ntwritefile.md')
        input_dir: Path to the input content directory
        output_dir: Path to the output directory
        base_url: Base URL for the online documentation
        previous_output_dir: Optional path to previous output directory for reusing .c files

    Returns True if code was extracted, False otherwise.
    """

    url = get_online_url_from_file_path(str(relative_path), base_url)

    # Construct the full input file path
    input_file = input_dir / relative_path

    # Read the input file
    with open(input_file, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    if input_file.name in [
        "nf-winuser-get_pointerid_wparam.md",
        "nf-winuser-is_pointer_flag_set_wparam.md",
        "nf-winuser-is_pointer_incontact_wparam.md",
        "nf-winuser-is_pointer_inrange_wparam.md",
        "nf-winuser-is_pointer_new_wparam.md",
    ]:
        # Special case to fix the following error:
        # found character '\t' that cannot start any token
        # https://github.com/MicrosoftDocs/sdk-api/pull/2098
        content = re.sub(r"^(ms.keywords: .*?)\t,", r"\1,", content, flags=re.MULTILINE)
    elif input_file.name == "nf-msrdc-irdcgeneratorfiltermaxparameters-sethashwindowsize.md":
        # https://github.com/MicrosoftDocs/sdk-api/pull/2095#issuecomment-3331004704
        content = re.sub(r"^(description: .*?): ", r"\1 - ", content, flags=re.MULTILINE)

    # Extract YAML front matter
    metadata, markdown_content = extract_yaml_frontmatter(content)

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
    code_extracted = False

    # Skip scraping for IOCTL files
    if not base_name.startswith('ni-'):
        c_output = output_subdir / f"{base_name}.c"

        # Check if we can reuse from previous output
        if previous_output_dir:
            previous_c_file = previous_output_dir / relative_path.parent / f"{base_name}.c"
            if previous_c_file.exists():
                # Copy the existing .c file
                with open(previous_c_file, 'r', encoding='utf-8') as f:
                    prototype = f.read()
                with open(c_output, 'w', encoding='utf-8') as f:
                    f.write(prototype)
                code_extracted = True

        # If we didn't find a previous file, scrape from web
        if not code_extracted:
            prototype = scrape_function_prototype(url)
            if prototype is not None:  # Include empty string as success
                with open(c_output, 'w', encoding='utf-8') as f:
                    f.write(prototype)
                code_extracted = True

    return code_extracted


def main():
    """Main function."""
    args = parse_arguments()

    input_path = Path(args.input)
    output_path = Path(args.output)
    previous_output_path = Path(args.previous_output) if args.previous_output else None
    input_filter = args.input_filter
    content_path = args.content_path
    base_url = args.base_url

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

        # Skip index.md files
        if base_name in ['index', 'TOC']:
            ignored_count += 1
            continue

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

    # Process each file
    code_extracted = 0
    code_not_extracted = 0
    exception_count = 0
    total = len(markdown_files)

    for i, md_file in enumerate(markdown_files, 1):
        # Calculate relative path from content directory
        relative_path = md_file.relative_to(content_dir)
        base_name = relative_path.stem
        print(f"[{i}/{total}] Processing {base_name}...", end=" ")

        try:
            code_success = process_markdown_file(relative_path, content_dir, output_path, base_url, previous_output_path)
            if code_success:
                print("OK")
                code_extracted += 1
            else:
                print("No code extracted")
                code_not_extracted += 1
        except Exception as e:
            print("Error, exception raised:")
            print(traceback.format_exc())
            exception_count += 1

    print(f"\nProcessing complete:")
    print(f"Code definitions extracted: {code_extracted}")
    print(f"Code definitions not extracted: {code_not_extracted}")
    print(f"Exceptions raised: {exception_count}")
    print(f"Output directory: {output_path}")


if __name__ == "__main__":
    main()
