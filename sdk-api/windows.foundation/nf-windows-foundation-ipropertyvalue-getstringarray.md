# IPropertyValue::GetStringArray (windows.foundation.h)

## Description

Gets the array of string values that is stored in the current [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object.

## Parameters

### `__valueSize` [out]

Type: **UINT32***

The number of values in the array.

### `value` [out]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)****

The array of string values.

The returned strings must be freed using [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring). The returned objects must be released using **IUnknown::Release**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue)

[IPropertyValueStatics::CreateStringArray](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvaluestatics-createstringarray)