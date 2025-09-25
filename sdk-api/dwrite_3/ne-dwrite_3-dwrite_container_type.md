# DWRITE_CONTAINER_TYPE enumeration

## Description

Specifies the container format of a font resource. A container format is distinct from
a font file format (DWRITE_FONT_FILE_TYPE) because the container describes the container
in which the underlying font file is packaged.

## Constants

### `DWRITE_CONTAINER_TYPE_UNKNOWN`

### `DWRITE_CONTAINER_TYPE_WOFF`

### `DWRITE_CONTAINER_TYPE_WOFF2`

## Remarks

DWRITE_CONTAINER_TYPE is returned by [IDWriteFactory5::AnalyzeContainerType](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefactory5-analyzecontainertype)