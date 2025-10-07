# ReaderScroll callback function

\[*ReaderScroll* is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.\]

An application-defined callback function used when the mouse pointer is moved within the portion of the reader mode window that has been declared as the active scrolling area.

## Parameters

*prmi* \[in\]

Type: **PREADERMODEINFO**

A pointer to the [**READERMODEINFO**](https://learn.microsoft.com/windows/win32/controls/readermodeinfo) structure that was passed to the [**DoReaderMode**](https://learn.microsoft.com/windows/win32/controls/doreadermode) function. This structure defines the reader mode window and the active scrolling area.

*dx* \[in\]

Type: **int**

The distance to scroll horizontally. If the RMF\_VERTICALONLY flag is set in the [**READERMODEINFO**](https://learn.microsoft.com/windows/win32/controls/readermodeinfo) structure, this value is always 0.

*dy* \[in\]

Type: **int**

The distance to scroll vertically. If the RMF\_HORIZONTALONLY flag is set in the [**READERMODEINFO**](https://learn.microsoft.com/windows/win32/controls/readermodeinfo) structure, this value is always 0.

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This function should always return **TRUE**.

## Remarks

When the application receives notification from this function, the application is responsible for scrolling the reader mode window in the direction specified by the *dx* and *dy* parameters.

## Examples

The following example outlines an implementation of this function using a custom function to accomplish the scrolling.

```C++
BOOL CALLBACK
ReaderScrollCallback(PREADERMODEINFO prmi, int dx, int dy)
{
    if (prmi == NULL)
        return FALSE;

    // Call custom ScrollWindow method to scroll the window
    ScrollWindow(prmi->hwnd, dx, dy);

    return TRUE;
}
```

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

