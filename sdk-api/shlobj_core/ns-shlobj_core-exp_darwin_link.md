# EXP_DARWIN_LINK structure

## Description

Holds an extra data block used by [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist). It holds the link's Windows Installer ID.

## Members

### `dbh`

Type: **[DATABLOCK_HEADER](https://learn.microsoft.com/windows/win32/api/shlobj_core/ns-shlobj_core-datablock_header)**

[DATABLOCK_HEADER](https://learn.microsoft.com/windows/win32/api/shlobj_core/ns-shlobj_core-datablock_header) structure stating the size and signature of the **EXP_DARWIN_LINK** structure. The following is the only recognized signature value.

#### EXP_DARWIN_ID_SIG

The **EXP_DARWIN_LINK** structure contains a Windows Installer ID.

### `DUMMYSTRUCTNAME`

### `szDarwinID`

Type: **__wchar_t[MAX_PATH]**

The link's ID in the form of an ANSI string.

### `szwDarwinID`

Type: **WCHAR[MAX_PATH]**

The link's ID in the form of an Unicode string.

## Remarks

[IShellLinkDataList::GetFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinkdatalist-getflags) returns the flag SLDF_HAS_DARWINID for links that have a darwin signature.

## See also

[IShellLinkDataList::GetFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinkdatalist-getflags)