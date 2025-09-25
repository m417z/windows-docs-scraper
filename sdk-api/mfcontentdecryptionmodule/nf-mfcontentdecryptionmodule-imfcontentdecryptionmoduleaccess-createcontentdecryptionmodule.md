## Description

Creates a [IMFContentDecryptionModule](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmodule) that represents a Content Decryption Module (CDM) for a DRM key system.

## Parameters

### `contentDecryptionModuleProperties`

An [IPropertyStore](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertystore) object containing the properties for the CDM.

### `contentDecryptionModule`

Receives the created **IMFContentDecryptionModule** object.

## Return value

Returns S_OK on success.

## Remarks

The following properties are supported for the *contentDecryptionModuleProperties* parameter.

| Property |Description
|-----------------------------------------------|---------------------------------------------------------------|
| [MF_CONTENTDECRYPTIONMODULE_INPRIVATESTOREPATH](https://learn.microsoft.com/windows/win32/medfound/mf-contentdecryptionmodule-inprivatestorepath) | A file path representing a storage location the Content Decryption Module (CDM) can use for content-specific data.|
| [MF_CONTENTDECRYPTIONMODULE_STOREPATH](https://learn.microsoft.com/windows/win32/medfound/mf-contentdecryptionmodule-storepath) | A file path representing a storage location the Content Decryption Module (CDM) can use for initialization. The path specified with this property will also be used for content-specific data if the **MF_CONTENTDECRYPTIONMODULE_INPRIVATESTOREPATH** property isn't set. |

## See also