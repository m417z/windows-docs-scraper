# SetClipboardData function

## Description

Places data on the clipboard in a specified clipboard format. The window must be the current clipboard owner, and the application must have called the [**OpenClipboard**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-openclipboard) function. (When responding to the [WM_RENDERFORMAT](https://learn.microsoft.com/windows/win32/dataxchg/wm-renderformat) message, the clipboard owner must not call **OpenClipboard** before calling **SetClipboardData**.)

## Parameters

### `uFormat` [in]

Type: **UINT**

The clipboard format. This parameter can be a registered format or any of the standard clipboard formats. For more information, see [Standard Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/standard-clipboard-formats) and [Registered Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats).

### `hMem` [in, optional]

Type: **HANDLE**

A handle to the data in the specified format. This parameter can be **NULL**, indicating that the window provides data in the specified clipboard format (renders the format) upon request; this is known as [delayed rendering](https://learn.microsoft.com/windows/win32/dataxchg/clipboard-operations#delayed-rendering). If a window delays rendering, it must process the [WM_RENDERFORMAT](https://learn.microsoft.com/windows/win32/dataxchg/wm-renderformat) and [WM_RENDERALLFORMATS](https://learn.microsoft.com/windows/win32/dataxchg/wm-renderallformats) messages.

If **SetClipboardData** succeeds, the system owns the object identified by the *hMem* parameter. The application may not write to or free the data once ownership has been transferred to the system, but it can lock and read from the data until the [CloseClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closeclipboard) function is called. (The memory must be unlocked before the Clipboard is closed.) If the *hMem* parameter identifies a memory object, the object must have been allocated using the function with the **GMEM_MOVEABLE** flag.

## Return value

Type: **HANDLE**

If the function succeeds, the return value is the handle to the data.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Windows 8:** Bitmaps to be shared with Windows Store app apps must be in the **CF_BITMAP** format (device-dependent bitmap).

If an application calls **SetClipboardData** in response to [WM_RENDERFORMAT](https://learn.microsoft.com/windows/desktop/dataxchg/wm-renderformat) or [WM_RENDERALLFORMATS](https://learn.microsoft.com/windows/desktop/dataxchg/wm-renderallformats), the application should not use the handle after **SetClipboardData** has been called.

If an application calls [OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard) with hwnd set to **NULL**, [EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard) sets the clipboard owner to **NULL**; this causes **SetClipboardData** to fail.

The system performs implicit data format conversions between certain clipboard formats when an application calls the [GetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboarddata) function. For example, if the **CF_OEMTEXT** format is on the clipboard, a window can retrieve data in the **CF_TEXT** format. The format on the clipboard is converted to the requested format on demand. For more information, see [Synthesized Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats).

#### Examples

For an example, see [Copying Information to the Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

[CloseClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closeclipboard)

**Conceptual**

[GetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboarddata)

[OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard)

**Reference**

[RegisterClipboardFormat](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclipboardformata)

[WM_RENDERALLFORMATS](https://learn.microsoft.com/windows/desktop/dataxchg/wm-renderallformats)

[WM_RENDERFORMAT](https://learn.microsoft.com/windows/desktop/dataxchg/wm-renderformat)