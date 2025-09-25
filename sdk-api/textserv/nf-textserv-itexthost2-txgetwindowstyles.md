# ITextHost2::TxGetWindowStyles

## Description

Retrieves the window styles and extended windows styles of the text host window.

## Parameters

### `pdwStyle`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The window styles. For a description of the possible values, see [Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/window-styles).

### `pdwExStyle`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The extended windows styles. For a description of the possible values, see [Extended Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextHost2](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost2)