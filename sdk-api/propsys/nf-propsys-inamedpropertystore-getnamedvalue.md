# INamedPropertyStore::GetNamedValue

## Description

Gets the value of a named property from the named property store.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

A pointer to the property name, as a Unicode string, of the property in the named property store.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this method returns, contains a pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that holds the property's value.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

If the property named in *pszName* is not found in the property store, this method returns S_OK and the *pv* member is set to VT_EMPTY.