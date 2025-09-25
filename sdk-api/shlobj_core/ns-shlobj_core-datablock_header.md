# DATABLOCK_HEADER structure

## Description

Serves as the header for some of the extra data structures used by [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist).

## Members

### `cbSize`

Type: **DWORD**

The size of the extra data block.

### `dwSignature`

Type: **DWORD**

A signature that identifies the type of data block that follows the header.

## See also

[EXP_DARWIN_LINK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-exp_darwin_link)

[NT_CONSOLE_PROPS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-nt_console_props)

[NT_FE_CONSOLE_PROPS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-nt_fe_console_props)