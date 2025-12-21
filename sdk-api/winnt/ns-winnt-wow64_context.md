# WOW64_CONTEXT structure

## Description

Represents a context frame on WOW64. Refer to the header file WinNT.h for the definition of this structure.

## Members

## Remarks

In the following versions of Windows, Slot 1 of Thread Local Storage (TLS) holds a pointer to a structure that contains a **WOW64_CONTEXT** structure starting at offset 4. This might change in later versions of Windows.

|  |  |
| --- | --- |
| Windows Vista | Windows Server 2008 |
| Windows 7 | Windows Server 2008 R2 |
| Windows 8 | Windows Server 2012 |
| Windows 8.1 | Windows Server 2012 R2 |

## See also

[Thread Environment Block (Debugging Notes)](https://learn.microsoft.com/windows/desktop/Debug/thread-environment-block--debugging-notes-)

[WOW64_FLOATING_SAVE_AREA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_floating_save_area)

[Wow64GetThreadContext](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64getthreadcontext)

[Wow64SetThreadContext](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64setthreadcontext)