# IAccessibleObject::SetAccessibleName

## Description

Sets text that is retrieved by [IAccessible::get_accName](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accname) which accessibility tools use to obtain the Name Property of an object.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated, Unicode string containing the name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.