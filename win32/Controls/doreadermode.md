# DoReaderMode function

\[**DoReaderMode** is available through Windows XP with Service Pack 2 (SP2). It may be unavailable in subsequent versions.\]

Enables reader mode in a window.

## Parameters

*prmi* \[in\]

Type: **PREADERMODEINFO**

A pointer to a [**READERMODEINFO**](https://learn.microsoft.com/windows/win32/controls/readermodeinfo) structure that contains initialization information for the reader mode.

## Return value

This function does not return a value.

## Remarks

Reader mode is activated through supported devices by a mouse click, typically using a third mouse button or scroll wheel. Subsequent mouse movement in a specified area scrolls that area's contents rather than moving a pointer. Outside of that area, the mouse pointer is displayed and operates normally. A second click of the button or scroll wheel releases the device from reader mode.

> [!Note]
> This function is not declared in any public header. To use it, you must access it as ordinal 383 from Comctl32.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 4.72 or later) |

