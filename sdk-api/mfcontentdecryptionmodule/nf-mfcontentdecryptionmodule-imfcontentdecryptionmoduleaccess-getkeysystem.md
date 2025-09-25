## Description

Gets a string identifying the Key System being used by the Content Decryption Module (CDM).

## Parameters

### `keySystem`

Receives a pointer to an **LPWSTR** identifying the Key System.

## Return value

Returns S_OK on success.

## Remarks

The *keySystem* memory must be allocated and freed using [CoTaskMem](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc).

**GetKeySystem** is based on the Encrypted Media Extension specification's [MediaKeySystemAccess.getConfiguration](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysystemaccess-keysystem).

## See also