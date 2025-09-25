# HttpPrepareUrl function

## Description

The **HttpPrepareUrl** function parses, analyzes, and normalizes a non-normalized Unicode or punycode URL so it is safe and valid to use in other HTTP functions.

## Parameters

### `Reserved`

Reserved. Must be **NULL**.

### `Flags`

Reserved. Must be zero.

### `Url` [in]

A pointer to a string that represents the non-normalized Unicode or punycode URL to prepare.

### `PreparedUrl` [out]

On successful output, a pointer to a string that represents the normalized URL.

**Note** Free *PreparedUrl* using [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree).

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.