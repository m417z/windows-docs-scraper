# CRYPT_DECODE_PARA structure

## Description

The **CRYPT_DECODE_PARA** structure is used by the [CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex) function to provide access to memory allocation and memory freeing callback functions.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pfnAlloc`

This member is an optional pointer to a callback function used to allocate memory.

### `pfnFree`

This member is an optional pointer to a callback function used to free memory allocated by the allocate callback function.