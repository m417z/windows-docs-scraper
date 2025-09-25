# INamedPropertyStore::SetNamedValue

## Description

Sets the value of a named property.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

A pointer to the property name, as a Unicode string, in the named property store.

### `propvar` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the value to set for the property named in *pszName*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.