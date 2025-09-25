# GetPointerPenInfo function

## Description

Gets the pen-based information for the specified pointer (of type [PT_PEN](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)) associated with the current message.

## Parameters

### `pointerId` [in]

An identifier of the pointer for which to retrieve information.

### `penInfo` [out]

Address of a [POINTER_PEN_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_pen_info) structure to receive the pen-specific pointer information.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetPointerPenInfo** retrieves information for a single pointer (of type [PT_PEN](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)) associated with a pointer message.

Use [GetPointerFramePenInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframepeninfo) to retrieve frame information associated with a message for a set of pointers.

The information returned by [GetPointerInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfo) is associated with the most recent pointer message retrieved by the calling thread. When the next message is retrieved by the calling thread, the information associated with the previous message may no longer be available.

If the application does not process pointer input messages as fast as they are generated, some messages may be coalesced into a [WM_POINTERUPDATE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerupdate) message. Use [GetPointerPenInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerpeninfohistory) to retrieve the message history from the most recent **WM_POINTERUPDATE** message.

If the information associated with the message is no longer available, this function fails with the last error set to **ERROR_NO_DATA**.

If the calling thread does not own the window to which the pointer message has been delivered, this function fails with the last error set to **ERROR_ACCESS_DENIED**. Note that this may be the window to which the input was originally delivered or it may be a window to which the message was forwarded.

If the specified pointer is not of type [PT_PEN](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type), this function fails with the last error set to **ERROR_DATATYPE_MISMATCH**.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)

[GetPointerFramePenInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframepeninfo)

[GetPointerFramePenInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframepeninfohistory)

[GetPointerPenInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerpeninfohistory)