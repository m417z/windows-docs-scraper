## Description

The **BYTES_TO_PAGES** macro takes the size in bytes of the transfer request and calculates the number of pages required to contain the bytes.

## Parameters

### `Size` [in]

Specifies the size in bytes of the transfer request.

## Remarks

**BYTES_TO_PAGES** returns the number of pages required to contain the specified number of bytes.

The system-defined constant PAGE_SIZE can be used to determine whether a given length in bytes for a transfer is less than the virtual memory page size of the current platform.