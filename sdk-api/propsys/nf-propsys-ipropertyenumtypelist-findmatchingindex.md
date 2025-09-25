# IPropertyEnumTypeList::FindMatchingIndex

## Description

Compares the specified property value against the enumerated values in a list and returns the matching index.

## Parameters

### `propvarCmp` [in]

Type: **REFPROPVARIANT**

A reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that represents the property value.

### `pnIndex` [out]

Type: **UINT***

When this method returns, contains a pointer to the index in the enumerated type list that matches the property value, if any.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.