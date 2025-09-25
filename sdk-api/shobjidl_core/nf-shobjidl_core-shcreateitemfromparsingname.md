# SHCreateItemFromParsingName function

## Description

Creates and initializes a Shell item object from a parsing name.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a display name.

### `pbc` [in, optional]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

Optional. A pointer to a bind context used to pass parameters as inputs and outputs to the parsing function. These passed parameters are often specific to the data source and are documented by the data source owners. For example, the file system data source accepts the name being parsed (as a [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure), using the [STR_FILE_SYS_BIND_DATA](https://learn.microsoft.com/windows/desktop/shell/str-constants) bind context parameter.

[STR_PARSE_PREFER_FOLDER_BROWSING](https://learn.microsoft.com/windows/desktop/shell/str-constants) can be passed to indicate that URLs are parsed using the file system data source when possible. Construct a bind context object using [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) and populate the values using [IBindCtx::RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam). See **Bind Context String Keys** for a complete list of these. See the [Parsing With Parameters Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940368(v=vs.85)) for an example of the use of this parameter.

If no data is being passed to or received from the parsing function, this value can be **NULL**.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*, typically **IID_IShellItem** or **IID_IShellItem2**.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in *riid*. This is typically [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or [IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

We recommend that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct **IID** based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.