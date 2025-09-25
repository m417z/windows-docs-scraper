# IProviderProperties::SetValue

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Sets the value of the specified property key.

## Parameters

### `pIFunctionInstance` [in]

An [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

### `Key` [in]

The property key for the property to be set.

### `ppropVar` [in]

The property data. To remove the property from the store, specify a **PROPVARIANT** with the type VT_EMPTY.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The *pIFunctionInstance*, *pvProviderInstanceContext*, or *ppropVar* parameter is **NULL**. |

## See also

[IProviderProperties](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderproperties)