# CryptMemRealloc function

## Description

The **CryptMemRealloc** function frees the memory currently allocated for a buffer and allocates memory for a new buffer.

## Parameters

### `pv` [in]

A pointer to a currently allocated buffer.

### `cbSize` [in]

Number of bytes to be allocated.

## Return value

Returns a pointer to the buffer allocated. If the function fails, **NULL** is returned. When you have finished using the buffer, free the memory by calling the [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) function.

## See also

[CryptMemAlloc](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemalloc)

[CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree)