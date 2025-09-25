# IFileSystemBindData::GetFindData

## Description

Gets the file system information stored in the [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure.

## Parameters

### `pfd` [out]

Type: **[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa)***

A pointer to the [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure that receives the data.

## Return value

Type: **HRESULT**

Returns S_OK.

## Remarks

This method provides bind context information to [IShellFolder::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-parsedisplayname). The client accesses the object by calling [IBindCtx::GetObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getobjectparam) with the *pszKey* parameter set to the string "File System Bind Data".