# SHParseDisplayName function

## Description

Translates a Shell namespace object's display name into an item identifier list and returns the attributes of the object. This function is the preferred method to convert a string to a pointer to an item identifier list (PIDL).

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

A pointer to a zero-terminated wide string that contains the display name to parse.

### `pbc` [in, optional]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A bind context that controls the parsing operation. This parameter is normally set to **NULL**.

### `ppidl` [out]

Type: **PIDLIST_ABSOLUTE***

The address of a pointer to a variable of type [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) that receives the item identifier list for the object. If an error occurs, then this parameter is set to **NULL**.

### `sfgaoIn` [in]

Type: **SFGAOF**

A **ULONG** value that specifies the attributes to query. To query for one or more attributes, initialize this parameter with the flags that represent the attributes of interest. For a list of available SFGAO flags, see [SFGAO](https://learn.microsoft.com/windows/win32/shell/sfgao).

### `psfgaoOut` [out, optional]

Type: **SFGAOF***

A pointer to a **ULONG**. On return, those attributes that are true for the object and were requested in *sfgaoIn* are set. An object's attribute flags can be zero or a combination of SFGAO flags. For a list of available SFGAO flags, see [SFGAO](https://learn.microsoft.com/windows/win32/shell/sfgao).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You should call this function from a background thread. Failure to do so could cause the UI to stop responding.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)

[IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof)

[IShellFolder::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-parsedisplayname)

[ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist)

[SHGetPathFromIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetpathfromidlista)