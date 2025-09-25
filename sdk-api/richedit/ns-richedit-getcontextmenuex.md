# GETCONTEXTMENUEX structure

## Description

Contains context menu information that is passed to the [IRichEditOleCallback::GetContextMenu](https://learn.microsoft.com/windows/win32/api/richole/nf-richole-iricheditolecallback-getcontextmenu) method.

## Members

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

The character-position range in the active display.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more of the following content menu flags:

| Value | Meaning |
| --- | --- |
| **GCMF_GRIPPER** | Get the context menu that is invoked by tapping a touch gripper handle. |
| **GCMF_SPELLING** | Get the context menu for a spelling error. |
| **GCMF_MOUSEMENU** | Get the context menu that is invoked by mouse. |
| **GCMF_TOUCHMENU** | Get the context menu that is invoked by touch. |

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The screen coordinates for the content menu.

### `pvReserved`

Type: **void***

Not used; must be zero.

## See also

[IRichEditOleCallback::GetContextMenu](https://learn.microsoft.com/windows/win32/api/richole/nf-richole-iricheditolecallback-getcontextmenu)