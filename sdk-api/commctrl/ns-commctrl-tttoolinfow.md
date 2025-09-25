# TTTOOLINFOW structure

## Description

The **TOOLINFO** structure contains information about a tool in a tooltip control.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of this structure, in bytes. This member must be specified.

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that control the tooltip display. This member can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| **TTF_ABSOLUTE** | Positions the tooltip window at the same coordinates provided by [TTM_TRACKPOSITION](https://learn.microsoft.com/windows/desktop/Controls/ttm-trackposition). This flag must be used with the TTF_TRACK flag. |
| **TTF_CENTERTIP** | Centers the tooltip window below the tool specified by the **uId** member. |
| **TTF_IDISHWND** | Indicates that the **uId** member is the window handle to the tool. If this flag is not set, **uId** is the tool's identifier. |
| **TTF_PARSELINKS** | [Version 6.0 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Indicates that links in the tooltip text should be parsed.<br><br>Note that Comctl32.dll version 6 is not redistributable but it is included in Windows or later. To use Comctl32.dll version 6, specify it in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview). |
| **TTF_RTLREADING** | Indicates that the tooltip text will be displayed in the opposite direction to the text in the parent window. |
| **TTF_SUBCLASS** | Indicates that the tooltip control should subclass the tool's window to intercept messages, such as [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove). If this flag is not set, you must use the [TTM_RELAYEVENT](https://learn.microsoft.com/windows/desktop/Controls/ttm-relayevent) message to forward messages to the tooltip control. For a list of messages that a tooltip control processes, see TTM_RELAYEVENT. |
| **TTF_TRACK** | Positions the tooltip window next to the tool to which it corresponds and moves the window according to coordinates supplied by the [TTM_TRACKPOSITION](https://learn.microsoft.com/windows/desktop/Controls/ttm-trackposition) messages. You must activate this type of tool using the [TTM_TRACKACTIVATE](https://learn.microsoft.com/windows/desktop/Controls/ttm-trackactivate) message. |
| **TTF_TRANSPARENT** | Causes the tooltip control to forward mouse event messages to the parent window. This is limited to mouse events that occur within the bounds of the tooltip window. |

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the window that contains the tool. If **lpszText** includes the LPSTR_TEXTCALLBACK value, this member identifies the window that receives the [TTN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/ttn-getdispinfo) notification codes.

### `uId`

Type: **[UINT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined identifier of the tool. If **uFlags** includes the TTF_IDISHWND flag, **uId** must specify the window handle to the tool.

### `rect`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The bounding rectangle coordinates of the tool. The coordinates are relative to the upper-left corner of the client area of the window identified by **hwnd**. If **uFlags** includes the TTF_IDISHWND flag, this member is ignored.

### `hinst`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the instance that contains the string resource for the tool. If **lpszText** specifies the identifier of a string resource, this member is used.

### `lpszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the buffer that contains the text for the tool, or identifier of the string resource that contains the text. This member is sometimes used to return values. If you need to examine the returned value, must point to a valid buffer of sufficient size. Otherwise, it can be set to **NULL**. If **lpszText** is set to LPSTR_TEXTCALLBACK, the control sends
the [TTN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/ttn-getdispinfo) notification code to the owner window to retrieve the text.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**Version 4.70 and later**. A 32-bit application-defined value that is associated with the tool.

### `lpReserved`

Type: **void***

Reserved. Must be set to **NULL**.

## Remarks

Normal windows display text left-to-right (LTR). Windows can be *mirrored* to display languages such as Hebrew or Arabic that read right-to-left (RTL). Normally, tooltip text is displayed in the same direction as the text in its parent window. If TTF_RTLREADING is set, tooltip text will read in the opposite direction from the text in the parent window.

> [!NOTE]
> The commctrl.h header defines TTTOOLINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).