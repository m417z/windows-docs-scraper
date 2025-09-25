# IPropertyUI::ParsePropertyName

## Description

Developers should use [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) instead. Reads the characters of the specified property name and identifies the FMTID and PROPID of the property.

## Parameters

### `pszName` [in]

Type: **LPWSTR**

A string specifying the property name to parse.

### `pfmtid` [out]

Type: **FMTID***

The FMTID of the parsed property.

### `ppid` [out]

Type: **PROPID***

The PROPID of the parsed property name.

### `pchEaten` [in, out]

Type: **ULONG***

The number of characters that were consumed in parsing *pszName*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.