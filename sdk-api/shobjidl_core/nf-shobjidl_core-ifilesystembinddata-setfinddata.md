# IFileSystemBindData::SetFindData

## Description

Stores file system information in a [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure. This information is used by [ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-parsedisplayname).

## Parameters

### `pfd` [in]

Type: **const [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa)***

A pointer to the [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure that specifies the data you want to store.

## Return value

Type: **HRESULT**

Always returns **S_OK**.

## Remarks

After the client stores the file information, the instance of the object itself must be stored in a bind context by using the [IBindCtx::RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam) method with the *pszKey* parameter set to `L"File System Bind Data"`.