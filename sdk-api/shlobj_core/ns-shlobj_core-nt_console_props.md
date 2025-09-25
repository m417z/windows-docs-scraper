# NT_CONSOLE_PROPS structure

## Description

Holds an extra data block used by [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist). It holds console properties.

## Members

### `dbh`

Type: **[DATABLOCK_HEADER](https://learn.microsoft.com/windows/win32/api/shlobj_core/ns-shlobj_core-datablock_header)**

The [DATABLOCK_HEADER](https://learn.microsoft.com/windows/win32/api/shlobj_core/ns-shlobj_core-datablock_header) structure with the **NT_CONSOLE_PROPS** structure's size and signature. The signature for an **NT_CONSOLE_PROPS** structure is NT_CONSOLE_PROPS_SIG.

### `DUMMYSTRUCTNAME`

### `wFillAttribute`

Type: **WORD**

Fill attribute for the console.

### `wPopupFillAttribute`

Type: **WORD**

Fill attribute for console pop-ups.

### `dwScreenBufferSize`

Type: **[COORD](https://learn.microsoft.com/windows/console/coord-str)**

A [COORD](https://learn.microsoft.com/windows/console/coord-str) structure with the console's screen buffer size.

### `dwWindowSize`

Type: **[COORD](https://learn.microsoft.com/windows/console/coord-str)**

A [COORD](https://learn.microsoft.com/windows/console/coord-str) structure with the console's window size.

### `dwWindowOrigin`

Type: **[COORD](https://learn.microsoft.com/windows/console/coord-str)**

A [COORD](https://learn.microsoft.com/windows/console/coord-str) structure with the console's window origin.

### `nFont`

Type: **DWORD**

The font.

### `nInputBufferSize`

Type: **DWORD**

The input buffer size.

### `dwFontSize`

Type: **[COORD](https://learn.microsoft.com/windows/console/coord-str)**

A [COORD](https://learn.microsoft.com/windows/console/coord-str) structure with the font size.

### `uFontFamily`

Type: **UINT**

The font family.

### `uFontWeight`

Type: **UINT**

The font weight.

### `FaceName`

Type: **WCHAR[LF_FACESIZE]**

A character array that contains the font's face name.

### `uCursorSize`

Type: **UINT**

The cursor size.

### `bFullScreen`

Type: **BOOL**

A boolean value that is set to **TRUE** if the console is in full-screen mode, or **FALSE** otherwise.

### `bQuickEdit`

Type: **BOOL**

A boolean value that is set to **TRUE** if the console is in quick-edit mode, or **FALSE** otherwise.

### `bInsertMode`

Type: **BOOL**

A boolean value that is set to **TRUE** if the console is in insert mode, or **FALSE** otherwise.

### `bAutoPosition`

Type: **BOOL**

A boolean value that is set to **TRUE** if the console is in auto-position mode, or **FALSE** otherwise.

### `uHistoryBufferSize`

Type: **UINT**

The size of the history buffer.

### `uNumberOfHistoryBuffers`

Type: **UINT**

The number of history buffers.

### `bHistoryNoDup`

Type: **BOOL**

A boolean value that is set to **TRUE** if old duplicate history lists should be discarded, or **FALSE** otherwise.

### `ColorTable`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)[16]**

An array of [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) values with the console's color settings.