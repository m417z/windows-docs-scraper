## Description

The **DO_DOWNLOAD_RANGE** structure identifies a single range of bytes to download from a file. The **DO_DOWNLOAD_RANGE** structure is included within **DO_DOWNLOAD_RANGES_INFO** structure to provide an array of ranges to download.

## Members

### `Offset`

Zero-based offset to the beginning of the range of bytes to download from a file.

### `Length`

The length of the range, in bytes. Do not specify a zero-byte length. To indicate that the range extends to the end of the file, specify **DO_LENGTH_TO_EOF**.

## Remarks

## See also