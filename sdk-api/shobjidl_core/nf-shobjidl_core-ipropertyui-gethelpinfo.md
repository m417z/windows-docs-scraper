# IPropertyUI::GetHelpInfo

## Description

Developers should use [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) instead. Gets

## Parameters

### `fmtid` [in]

Type: **REFFMTID**

The FMTID of the property.

### `pid` [in]

Type: **PROPID**

The PROPID of the property.

### `pwszHelpFile` [out]

Type: **LPWSTR**

The fully qualified path of the Help file.

### `cch` [in]

Type: **DWORD**

### `puHelpID` [out]

Type: **UINT***

The Help context ID for the property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.