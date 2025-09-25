# BeginDeferWindowPos function

## Description

Allocates memory for a multiple-window- position structure and returns the handle to the structure.

## Parameters

### `nNumWindows` [in]

Type: **int**

The initial number of windows for which to store position information. The [DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos) function increases the size of the structure, if necessary.

## Return value

Type: **HDWP**

If the function succeeds, the return value identifies the multiple-window-position structure. If insufficient system resources are available to allocate the structure, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The multiple-window-position structure is an internal structure; an application cannot access it directly.

[DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos) fills the multiple-window-position structure with information about the target position for one or more windows about to be moved. The [EndDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddeferwindowpos) function accepts the handle to this structure and repositions the windows by using the information stored in the structure.

If the system must increase the size of the multiple-window- position structure beyond the initial size specified by the *nNumWindows* parameter but cannot allocate enough memory to do so, the system fails the entire window positioning sequence (**BeginDeferWindowPos**, [DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos), and [EndDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddeferwindowpos)). By specifying the maximum size needed, an application can detect and process failure early in the process.

## See also

**Conceptual**

[DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos)

[EndDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddeferwindowpos)

**Reference**

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)