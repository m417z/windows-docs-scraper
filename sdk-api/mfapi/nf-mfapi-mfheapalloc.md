# MFHeapAlloc function

## Description

Allocates a block of memory.

## Parameters

### `nSize` [in]

Number of bytes to allocate.

### `dwFlags` [in]

Zero or more flags. For a list of valid flags, see **HeapAlloc** in the Windows SDK documentation.

### `pszFile` [in]

Reserved. Set to **NULL**.

### `line` [in]

Reserved. Set to zero.

### `eat` [in]

Reserved. Set to **eAllocationTypeIgnore**.

## Return value

If the function succeeds, it returns a pointer to the allocated memory block. If the function fails, it returns **NULL**.

## Remarks

In the current version of Media Foundation, this function is equivalent to calling the **HeapAlloc** function and specifying the heap of the calling process.

To free the allocated memory, call [MFHeapFree](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfheapfree).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)