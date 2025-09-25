# NT_FE_CONSOLE_PROPS structure

## Description

Holds an extra data block used by [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist). It holds the console's code page.

## Members

### `dbh`

Type: **[DATABLOCK_HEADER](https://learn.microsoft.com/windows/win32/api/shlobj_core/ns-shlobj_core-datablock_header)**

The [DATABLOCK_HEADER](https://learn.microsoft.com/windows/win32/api/shlobj_core/ns-shlobj_core-datablock_header) structure with the **NT_FE_CONSOLE_PROPS** structure's size and signature. The signature for an **NT_FE_CONSOLE_PROPS** structure is NT_FE_CONSOLE_PROPS_SIG.

### `DUMMYSTRUCTNAME`

### `uCodePage`

Type: **UINT**

The console's code page.