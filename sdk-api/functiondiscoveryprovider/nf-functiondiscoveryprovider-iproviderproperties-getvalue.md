# IProviderProperties::GetValue

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the value of the specified property key.

## Parameters

### `pIFunctionInstance` [in]

An [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

### `Key` [in]

The property key reference.

### `ppropVar` [out]

The value of the property key specified by *Key*. The **PROPVARIANT** type is VT_EMPTY if the key is not found in the property store.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the parameters contains an invalid argument. |
| **E_POINTER** | *ppropVar* parameter is **NULL**. |
| **E_OUTOFMEMORY** | The method is unable to allocate enough memory to perform the operation. |

## Remarks

To change the value of a property key, use the [SetValue](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-iproviderproperties-setvalue) method.

If a value for *Key* could not be found, the return value will be **S_OK** and *ppropVar* will be set to **VT_NULL**.

## See also

[IProviderProperties](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderproperties)