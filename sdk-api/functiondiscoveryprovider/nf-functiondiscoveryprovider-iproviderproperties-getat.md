# IProviderProperties::GetAt

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the property key at the specified index.

## Parameters

### `pIFunctionInstance` [in]

A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

### `dwIndex` [in]

The index of the property key.

### `pKey` [out]

The property key.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the input parameters is invalid. |
| **E_POINTER** | The *pKey* parameter is **NULL**. |

## See also

[IProviderProperties](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderproperties)