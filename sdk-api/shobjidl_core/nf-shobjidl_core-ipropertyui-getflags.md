# IPropertyUI::GetFlags

## Description

Developers should use [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) instead. Gets property feature flags for a specified property.

## Parameters

### `fmtid` [in]

Type: **REFFMTID**

The FMTID of the property.

### `pid` [in]

Type: **PROPID**

The PROPID of the property.

### `pflags` [out]

Type: **[PROPERTYUI_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_propertyui_flags)***

The [PROPERTYUI_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_propertyui_flags) for the property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.