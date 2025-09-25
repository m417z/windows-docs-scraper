# IPropertyUI::GetPropertyDescription

## Description

Developers should use [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) instead. Gets the property description of a specified property.

## Parameters

### `fmtid` [in]

Type: **REFFMTID**

The FMTID of the property.

### `pid` [in]

Type: **PROPID**

The PROPID of the property.

### `pwszText` [out]

Type: **LPWSTR**

The description of the property.

### `cchText` [in]

Type: **DWORD**

The length of the property description.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.