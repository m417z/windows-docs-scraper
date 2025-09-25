# EXP_SZ_LINK structure

## Description

Holds an extra data block used by [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist). It holds expandable environment strings for the icon or target.

## Members

### `cbSize`

Type: **DWORD**

The size of the **EXP_SZ_LINK** structure.

### `dwSignature`

Type: **DWORD**

The structure's signature. It can have one of the following values.

#### EXP_SZ_LINK_SIG

Contains the link's target path.

#### EXP_SZ_ICON_SIG

Contains the links icon path.

### `szTarget`

Type: **__wchar_t[MAX_PATH]**

The null-terminated ANSI string with the path of the target or icon.

### `swzTarget`

Type: **WCHAR[MAX_PATH]**

The null-terminated Unicode string with the path of the target or icon.