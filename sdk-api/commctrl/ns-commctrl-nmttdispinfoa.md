# NMTTDISPINFOA structure

## Description

Contains information used in handling the [TTN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/ttn-getdispinfo) notification code. This structure supersedes the
**TOOLTIPTEXT** structure.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `lpszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that will be displayed as the tooltip text. If **hinst** specifies an instance handle, this member must be the identifier of a string resource.

### `szText`

Type: **[TCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Buffer that receives the tooltip text. An application can copy the text to this buffer instead of specifying a string address or string resource. For tooltip text that exceeds 80 **TCHAR****s**, see comments in the remarks section of this document.

### `hinst`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the instance that contains a string resource to be used as the tooltip text. If **lpszText** is the address of the tooltip text string, this member must be **NULL**.

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that indicates how to interpret the **idFrom** member of the included [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure.

| Value | Meaning |
| --- | --- |
| **TTF_IDISHWND** | If this flag is set, **idFrom** is the tool's handle. Otherwise, it is the tool's identifier. |
| **TTF_RTLREADING** | Windows can be *mirrored* to display languages such as Hebrew or Arabic that read right-to-left (RTL). Normally, tooltip text is read in same direction as the text in its parent window. To have a tooltip read in the opposite direction from its parent window, add the TTF_RTLREADING flag to the **uFlags** member when processing the notification. |
| **TTF_DI_SETITEM** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). If you add this flag to **uFlags** while processing the notification, the tooltip control will retain the supplied information and not request it again. |

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Application-defined data associated with the tool.

## Remarks

You need to point the **lpszText** array to your own private buffer when the text used in the tooltip exceeds 80 **TCHAR**s in length. The system automatically strips the ampersand (&) accelerator **TCHAR****s** from all strings passed to a tooltip control, unless the control has the [TTS_NOPREFIX](https://learn.microsoft.com/windows/desktop/Controls/tooltip-styles) style.

> [!NOTE]
> The commctrl.h header defines NMTTDISPINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).