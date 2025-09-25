# SHILCreateFromPath function

## Description

[**SHILCreateFromPath** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications should use [SHParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shparsedisplayname) instead]

Creates a pointer to an item identifier list (PIDL) from a path.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a null-terminated string of maximum length MAX_PATH containing the path to be converted.

### `ppidl` [out]

Type: **PIDLIST_ABSOLUTE***

The path in *pszPath* expressed as a PIDL.

### `rgfInOut` [in, out, optional]

Type: **DWORD***

A pointer to a **DWORD** value that, on entry, indicates any attributes of the folder named in *pszPath* that the calling application would like to retrieve along with the PIDL. On exit, this value contains those requested attributes. For a list of possible attribute flags for this parameter, see [IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.