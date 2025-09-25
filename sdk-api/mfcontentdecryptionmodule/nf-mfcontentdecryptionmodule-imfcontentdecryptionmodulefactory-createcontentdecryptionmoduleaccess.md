## Description

Creates an instance of the [IMFContentDecryptionModuleAccess](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmoduleaccess) interface.

## Parameters

### `keySystem`

An **LPWSTR** identifying the Key System for which the interface is created.

### `configurations`

An [IPropertyStore](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertystore) object containing the configuration options for the CDM.

### `numConfigurations`

A **DWORD** specifying the number of properties in the *configurations* parameter.

### `contentDecryptionModuleAccess`

Receives the created **IMFContentDecryptionModuleAccess** object.

## Return value

Returns S_OK on success.

## Remarks

**IMFContentDecryptionModuleAccess** is based on the Encrypted Media Extension specification's [MediaKeySystemAccess.getConfiguration](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#mediakeysystemaccess-interface).

## See also

- [IMFContentDecryptionModuleAccess](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmoduleaccess)