## Description

Creating an instance of [IMFContentDecryptionModuleFactory](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmodulefactory), a class factory for Content Decryption Module (CDM) objects, for a specified key system.

## Parameters

### `keySystem`

An LPWSTR identifying the Key System for which the interface is created.

### `riid`

The IID of the **IMFContentDecryptionModuleFactory** interface to create.

### `ppvObject`

Receives a pointer to the created interface.

## Return value

Returns S_OK on success.

## Remarks

## See also