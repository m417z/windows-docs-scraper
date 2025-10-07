# Windows Docs Scraper

A Python script that uses [the official Windows Driver Kit DDI reference
documentation sources](https://github.com/MicrosoftDocs/windows-driver-docs-ddi)
or [the official Win32 API reference documentation sources](
https://github.com/MicrosoftDocs/sdk-api) and stores them in a more convenient
format, along with function prototypes which are scraped from the online
documentation.

## Scope

Scraped files:

* `nc-*.md`: Callbacks
* `ne-*.md`: Enums
* `nf-*.md`: Functions
* `ni-*.md`: IOCTLs
* `ns-*.md`: Structs

Files which are intentionally ignored:

* `na-*.md`: Headers
* `nl-*.md`: Classes
* `nn-*.md`: Interfaces

## Example API reference entry

### Function

`NtWriteFile`

### Repository file

```
<windows-driver-docs-ddi>\wdk-ddi-src\content\ntifs\nf-ntifs-ntwritefile.md
```

A markdown documentation file with YAML Front Matter metadata.

### Online documentation

https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntwritefile

## Example output

### Documentation

```
<output-folder>\ntifs\nf-ntifs-ntwritefile.md
```

Markdown file without the YAML Front Matter metadata.

### Metadata

```
<output-folder>\ntifs\nf-ntifs-ntwritefile.json
```

JSON file with metadata extracted from the YAML Front Matter.

### Prototype

```
<output-folder>\ntifs\nf-ntifs-ntwritefile.c
```

C file with the function prototype, scraped from the online documentation.

## Usage

```console
python scraper.py \
    --repository windows-driver-docs-ddi \
    --input <path-to-cloned-repo-root> \
    --output <output-folder>
```
