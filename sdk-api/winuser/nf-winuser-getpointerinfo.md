# GetPointerInfo function

## Description

Gets the information for the specified pointer associated with the current message.

**Note** Use [GetPointerType](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertype) if you don't need the additional information exposed by **GetPointerInfo**.

## Parameters

### `pointerId` [in]

The pointer identifier.

### `pointerInfo` [out]

Address of a [POINTER_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_info) structure that receives the pointer information.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetPointerInfo** retrieves information for a single pointer associated with a pointer message.

Use [GetPointerFrameInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfo) to retrieve frame information associated with a message for a set of pointers.

The information returned by **GetPointerInfo** is associated with the most recent pointer message retrieved by the calling thread. When the next message is retrieved by the calling thread, the information associated with the previous message may no longer be available.

If the application does not process pointer input messages as fast as they are generated, some messages may be coalesced into a [WM_POINTERUPDATE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerupdate) message. Use [GetPointerInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfohistory) to retrieve the message history from the most recent **WM_POINTERUPDATE** message.

If the information associated with the message is no longer available, this function fails with the last error set to **ERROR_NO_DATA**.

If the calling thread does not own the window to which the pointer message has been delivered, this function fails with the last error set to **ERROR_ACCESS_DENIED**. Note that this may be the window to which the input was originally delivered or it may be a window to which the message was forwarded.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)

[GetPointerFrameInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfo)

[GetPointerFrameInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfohistory)

[GetPointerInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfohistory)