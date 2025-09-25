# CryptMemAlloc function

## Description

The **CryptMemAlloc** function allocates memory for a buffer. It is used by all Crypt32.lib functions that return allocated buffers.

## Parameters

### `cbSize` [in]

Number of bytes to be allocated.

## Return value

Returns a pointer to the buffer allocated. If the function fails, **NULL** is returned. When you have finished using the buffer, free the memory by calling the [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) function.

## See also

[CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree)

[CryptMemRealloc](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemrealloc)