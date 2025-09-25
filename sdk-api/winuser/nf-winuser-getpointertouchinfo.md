# GetPointerTouchInfo function

## Description

Gets the touch-based information for the specified pointer (of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)) associated with the current message.

## Parameters

### `pointerId` [in]

An identifier of the pointer for which to retrieve information.

### `touchInfo` [out]

Address of a [POINTER_TOUCH_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_touch_info) structure to receive the touch-specific pointer information.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetPointerTouchInfo** retrieves information for a single pointer (of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)) associated with a pointer message.

Use [GetPointerFrameTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframetouchinfo) to retrieve frame information associated with a message for a set of pointers.

The information returned by **GetPointerTouchInfo** is associated with the most recent pointer message retrieved by the calling thread. When the next message is retrieved by the calling thread, the information associated with the previous message may no longer be available.

If the application does not process pointer input messages as fast as they are generated, some messages may be coalesced into a [WM_POINTERUPDATE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerupdate) message. Use [GetPointerTouchInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfohistory) to retrieve the message history from the most recent **WM_POINTERUPDATE** message.

If the information associated with the message is no longer available, this function fails with the last error set to **ERROR_NO_DATA**.

If the calling thread does not own the window to which the pointer message has been delivered, this function fails with the last error set to **ERROR_ACCESS_DENIED**. Note that this may be the window to which the input was originally delivered or it may be a window to which the message was forwarded.

If the specified pointer is not of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type), this function fails with the last error set to **ERROR_DATATYPE_MISMATCH**.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)

[GetPointerFrameTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframetouchinfo)

[GetPointerFrameTouchInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframetouchinfohistory)

[GetPointerTouchInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfohistory)