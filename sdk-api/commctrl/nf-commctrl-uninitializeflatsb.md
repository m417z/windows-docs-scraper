# UninitializeFlatSB function

## Description

Uninitializes flat scroll bars for a particular window. The specified window will revert to standard scroll bars.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window with the flat scroll bars that will be uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_FAIL** | One of the window's scroll bars is currently in use. The operation cannot be completed at this time. |
| **S_FALSE** | The window does not have flat scroll bars initialized. |
| **S_OK** | The operation was successful. |

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.