# IPropertyUI::GetDefaultWidth

## Description

Developers should use [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) instead. Gets the width of the property description.

## Parameters

### `fmtid` [in]

Type: **REFFMTID**

The FMTID of the property.

### `pid` [in]

Type: **PROPID**

The PROPID of the property.

### `pcxChars` [out]

Type: **ULONG***

The width of the property description.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.