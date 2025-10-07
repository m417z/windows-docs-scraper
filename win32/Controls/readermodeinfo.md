# READERMODEINFO structure

\[**READERMODEINFO** is supported through Windows XP with Service Pack 2 (SP2). It might be unsupported in subsequent versions.\]

Contains information required to initialize the [**DoReaderMode**](https://learn.microsoft.com/windows/win32/controls/doreadermode) function.

## Members

**cbSize**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Required. The size of the structure, in bytes. Set this parameter to **sizeof(READERMODE)** before you call [**DoReaderMode**](https://learn.microsoft.com/windows/win32/controls/doreadermode).

**hwnd**

Type: **[**HWND**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Required. The handle of the window to be used for reader mode.

**fFlags**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags customizing the functionality of the reader mode window. This parameter can be 0; otherwise, one or more of the following values.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------|
| **RMF\_ZEROCURSOR**

0x01 | Sets the cursor in the center of the area specified in **prc**. If this flag is not specified, the cursor position remains unchanged.\ | | **RMF\_VERTICALONLY**

0x02 | Allows only vertical scrolling.\ | | **RMF\_HORIZONTALONLY**

0x04 | Allows only horizontal scrolling.\ |

**prc**

Type: **LPRECT**

A pointer to a [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the scrolling area in the reader mode window. If this member is **NULL**, then the entire window is used as the scrolling area.

**pfnScroll**

Type: **PFNREADERSCROLL**

A pointer to an application-defined [*ReaderScroll*](https://learn.microsoft.com/windows/win32/controls/readerscroll) callback function used to notify the application that the window needs to be scrolled in a particular direction.

**fFlags**

Type: **PFNREADERTRANSLATEDISPATCH**

A pointer to an application-defined [*TranslateDispatch*](https://learn.microsoft.com/windows/win32/controls/translatedispatch) callback function used to get first notification of any messages sent to the reader mode window.

**lParam**

Type: **[**LPARAM**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Additional information as needed by the application, read by the caller in the [*ReaderScroll*](https://learn.microsoft.com/windows/win32/controls/readerscroll) callback function.

## Remarks

This structure is not declared in any public header. To use it, you must include the declaration shown above in your own header.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

