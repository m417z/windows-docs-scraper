# IProviderProperties::GetCount

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the number of properties in the property store.

## Parameters

### `pIFunctionInstance` [in]

An [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

### `pdwCount` [out]

The number of properties in the property store.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the parameters contains an invalid argument. |
| **E_POINTER** | *pdwCount* parameter is **NULL**. |

## See also

[IProviderProperties](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderproperties)