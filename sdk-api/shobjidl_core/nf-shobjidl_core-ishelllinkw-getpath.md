# IShellLinkW::GetPath

## Description

Gets the path and file name of the target of a Shell link object.

## Parameters

### `pszFile` [out]

Type: **LPTSTR**

The address of a buffer that receives the path and file name of the target of the Shell link object.

### `cch` [in]

Type: **int**

The size, in characters, of the buffer pointed to by the *pszFile* parameter, including the terminating null character. The maximum path size that can be returned is MAX_PATH. This parameter is commonly set by calling ARRAYSIZE(pszFile). The ARRAYSIZE macro is defined in Winnt.h.

### `pfd` [in, out]

Type: **[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa)***

A pointer to a [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure that receives information about the target of the Shell link object. If this parameter is **NULL**, then no additional information is returned.

### `fFlags` [in]

Type: **DWORD**

Flags that specify the type of path information to retrieve. This parameter can be a combination of the following values.

#### SLGP_SHORTPATH

Retrieves the standard short (8.3 format) file name.

#### SLGP_UNCPRIORITY

Unsupported; do not use.

#### SLGP_RAWPATH

Retrieves the raw path name. A raw path is something that might not exist and may include environment variables that need to be expanded.

#### SLGP_RELATIVEPRIORITY

**Windows Vista and later**. Retrieves the path, if possible, of the shortcut's target relative to the path set by a previous call to [IShellLink::SetRelativePath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setrelativepath).

##### - fFlags.SLGP_RAWPATH

Retrieves the raw path name. A raw path is something that might not exist and may include environment variables that need to be expanded.

##### - fFlags.SLGP_RELATIVEPRIORITY

**Windows Vista and later**. Retrieves the path, if possible, of the shortcut's target relative to the path set by a previous call to [IShellLink::SetRelativePath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setrelativepath).

##### - fFlags.SLGP_SHORTPATH

Retrieves the standard short (8.3 format) file name.

##### - fFlags.SLGP_UNCPRIORITY

Unsupported; do not use.

## Return value

Type: **HRESULT**

Returns **S_OK** if the operation is successful and a valid path is retrieved. If the operation is successful but no path is retrieved, it returns **S_FALSE** and *pszFile* will be empty. Otherwise, it returns one of the standard HRESULT error values.