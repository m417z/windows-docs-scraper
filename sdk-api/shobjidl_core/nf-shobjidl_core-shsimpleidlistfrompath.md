# SHSimpleIDListFromPath function

## Description

Deprecated. Returns a pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure when passed a path.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a null-terminated string that contains the path to be converted to a PIDL.

## Return value

Type: **PIDLIST_ABSOLUTE**

Returns a pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure if successful, or **NULL** otherwise.

## Remarks

Prior to Windows 7, this function was declared in Shlobj.h. In Windows 7 and later versions, it is declared in Shobjidl.h.

**Note** This function is available through Windows 7 and Windows Server 2003. It is possible that it will not be present in future versions of Windows.

An alternative to this function is as follows:

1. Call [SHGetDesktopFolder](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetdesktopfolder) to obtain [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) for the desktop folder.
2. Get the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)'s bind context ([IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)).
3. Call [IShellFolder::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-parsedisplayname) with the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) and the path.