# IPropertyValue::GetGuidArray (windows.foundation.h)

## Description

Gets the array of [Guid](https://learn.microsoft.com/dotnet/api/system.guid) values that is stored in the current [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object.

## Parameters

### `__valueSize` [out]

Type: **UINT32***

The number of values in the array.

### `value` [out]

Type: **GUID****

The array of [Guid](https://learn.microsoft.com/dotnet/api/system.guid) values.

The returned pointer must be freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue)

[IPropertyValueStatics::CreateGuidArray](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvaluestatics-createguidarray)