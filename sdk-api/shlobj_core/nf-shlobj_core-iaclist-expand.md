# IACList::Expand

## Description

Requests that the autocompletion client generate candidate strings associated with a specified item in its namespace.

## Parameters

### `pszExpand` [in]

Type: **PCWSTR**

A pointer to a null-terminated, Unicode string to be expanded by the autocomplete object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The autocomplete object calls this method when a delimiter is entered in the edit control. If the string pointed to by *pszExpand* matches an item in the autocompletion client's namespace, the client generates strings for those items that fall immediately under *pszExpand* in its namespace hierarchy. The client returns those strings next time the autocompletion object calls the client's [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) interface.

For example, assuming that the client's namespace consists of all the files and folders on the C: drive, and *pszExpand* is set to "C:\Program Files\", the client should generate a list of strings corresponding to the fully qualified paths of the files and subfolders of "C:\Program Files\".

## See also

[IACList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iaclist)