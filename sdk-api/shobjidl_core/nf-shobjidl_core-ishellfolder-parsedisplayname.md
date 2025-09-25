# IShellFolder::ParseDisplayName

## Description

Translates the display name of a file object or a folder into an item identifier list.

## Parameters

### `hwnd` [in]

Type: **HWND**

A window handle. The client should provide a window handle if it displays a dialog or message box. Otherwise set *hwnd* to **NULL**.

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

Optional. A pointer to a bind context used to pass parameters as inputs and outputs to the parsing function. These passed parameters are often specific to the data source and are documented by the data source owners. For example, the file system data source accepts the name being parsed (as a [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure), using the [STR_FILE_SYS_BIND_DATA](https://learn.microsoft.com/windows/desktop/shell/str-constants) bind context parameter. [STR_PARSE_PREFER_FOLDER_BROWSING](https://learn.microsoft.com/windows/desktop/shell/str-constants) can be passed to indicate that URLs are parsed using the file system data source when possible. Construct a bind context object using [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) and populate the values using [IBindCtx::RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam). See **Bind Context String Keys** for a complete list of these.

If no data is being passed to or received from the parsing function, this value can be **NULL**.

### `pszDisplayName` [in]

Type: **LPWSTR**

A null-terminated Unicode string with the display name. Because each Shell folder defines its own parsing syntax, the form this string can take may vary. The desktop folder, for instance, accepts paths such as "C:\My Docs\My File.txt". It also will accept references to items in the namespace that have a GUID associated with them using the "::{GUID}" syntax. For example, to retrieve a fully qualified identifier list for the control panel from the desktop folder, you can use the following:

```cpp
::{CLSID for Control Panel}\::{CLSID for printers folder}

```

### `pchEaten` [out]

Type: **ULONG***

A pointer to a **ULONG** value that receives the number of characters of the display name that was parsed. If your application does not need this information, set *pchEaten* to **NULL**, and no value will be returned.

### `ppidl` [out]

Type: **PIDLIST_RELATIVE***

When this method returns, contains a pointer to the PIDL for the object. The returned item identifier list specifies the item relative to the parsing folder. If the object associated with *pszDisplayName* is within the parsing folder, the returned item identifier list will contain only one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure. If the object is in a subfolder of the parsing folder, the returned item identifier list will contain multiple **SHITEMID** structures. If an error occurs, **NULL** is returned in this address.

When it is no longer needed, it is the responsibility of the caller to free this resource by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pdwAttributes` [in, out]

Type: **ULONG***

The value used to query for file attributes. If not used, it should be set to **NULL**. To query for one or more attributes, initialize this parameter with the [SFGAO](https://learn.microsoft.com/windows/desktop/shell/sfgao) flags that represent the attributes of interest. On return, those attributes that are true *and* were requested will be set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Some Shell folders may not implement **IShellFolder::ParseDisplayName**. Each folder that does will define its own parsing syntax.

**ParseDisplayName** is not expected to handle the relative path or parent folder indicators (".\" or "..\"). It is up to the caller to remove these appropriately.

Do not use the SFGAO_VALIDATE flag in *pdwAttributes* to verify the existence of the item whose name is being parsed. **IShellFolder::ParseDisplayName** implicitly validates the existence of the item unless that behavior is overridden by a special bind context parameter.

Querying for some attributes may be relatively slow and use significant amounts of memory. For example, to determine if a file is shared, the Shell will load network components. This procedure may require the loading of several DLLs. The purpose of *pdwAttributes* is to allow you to restrict the query to only that information that is needed. The following code fragment illustrates how to find out if a file is compressed.

```cpp
LPITEMIDLIST pidl;
ULONG cbEaten;
DWORD dwAttribs = SFGAO_COMPRESSED;

hres = psf->ParseDisplayName(NULL,
                             NULL,
                             lpwszDisplayName,
                             &cbEaten,  // This can be NULL
                             &pidl,
                             &dwAttribs);

if(dwAttribs & SFGAO_COMPRESSED)
{
    // Do something with the compressed file
}

```

Since *pdwAttributes* is an in/out parameter, it should always be initialized. If you pass in an uninitialized value, some of the bits may be inadvertently set. **IShellFolder::ParseDisplayName** will then query for the corresponding attributes, which may lead to undesirable delays or memory demands. If you do not wish to query for attributes, set *pdwAttributes* to **NULL** to avoid unpredictable behavior.

This method is similar to the [IParseDisplayName::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iparsedisplayname-parsedisplayname) method.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)

[IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof)

[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka)