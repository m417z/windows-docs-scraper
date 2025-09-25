## Description

The **ROUND_TO_PAGES** macro takes a size in bytes and rounds it up to the next full page.

## Parameters

### `Size` [in]

Specifies the size in bytes to round up to a page multiple.

## Remarks

**ROUND_TO_PAGES** returns a ULONG_PTR with the input size rounded up to a multiple of the virtual memory page size for the current platform.

Callers of **ROUND_TO_PAGES** can be running at any IRQL. The caller must ensure that the supplied parameter cannot cause memory overflow.