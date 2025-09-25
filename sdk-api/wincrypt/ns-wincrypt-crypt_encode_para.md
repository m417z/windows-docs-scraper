# CRYPT_ENCODE_PARA structure

## Description

The **CRYPT_ENCODE_PARA** structure is used by the [CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex) function to provide access to memory allocation and memory freeing callback functions.

## Members

### `cbSize`

Indicates the size, in bytes, of the structure.

### `pfnAlloc`

This member is an optional pointer to a callback function used to allocate memory.

### `pfnFree`

This member is an optional pointer to a callback function used to free memory allocated by the allocate callback function.