# GetPointerFrameTouchInfo function

## Description

Gets the entire frame of touch-based information for the specified pointers (of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)) associated with the current message.

## Parameters

### `pointerId` [in]

An identifier of the pointer for which to retrieve frame information.

### `pointerCount` [in, out]

A pointer to a variable that specifies the count of structures in the buffer to which touchInfo points. If **GetPointerFrameTouchInfo** succeeds, *pointerCount* is updated with the total count of pointers in the frame.

### `touchInfo` [out]

Address of an array of [POINTER_TOUCH_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_touch_info) structures to receive the pointer information. This parameter can be NULL if **pointerCount* is zero.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Parallel-mode devices may report pointer input in frames, that is, they may report the state and position of all pointers from that device in a single input report to the system. Ideally, applications should view the entire frame as a single input unless the application-specific requirements dictate otherwise.

**GetPointerFrameTouchInfo** retrieves the entire pointer input frame associated with a pointer (of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)) message. Use [GetPointerTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfo) to retrieve information for a single pointer associated with a pointer message.

The frame contains only pointers that are currently owned by the same window as the specified pointer.

The information returned by **GetPointerFrameTouchInfo** is associated with the most recent pointer message retrieved by the calling thread. When the next message is retrieved by the calling thread, the information associated with the previous message may no longer be available.

If the application does not process pointer input messages as fast as they are generated, some messages may be coalesced into a [WM_POINTERUPDATE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerupdate) message. Use [GetPointerFrameTouchInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframetouchinfohistory) to retrieve the message history from the most recent **WM_POINTERUPDATE** message.

Having retrieved the entire frame of information, the application can then call the [SkipPointerFrameMessages](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-skippointerframemessages) function to skip remaining pointer messages associated with this frame that are pending retrieval. This saves the application the overhead of retrieving and processing the remaining messages one by one. However, the **SkipPointerFrameMessages** function should be used with care and only when the caller can be sure that no other entity on the caller’s thread is expecting to see the remaining pointer messages one by one as they are retrieved.

Note that the information retrieved is associated with the pointer frame most recently retrieved by the calling thread. Once the calling thread retrieves its next message, the information associated with the previous pointer frame may no longer be available.

If the pointer frame contains no additional pointers besides the specified pointer, this function succeeds and returns only the information for the specified pointer.

If the information associated with the pointer frame is no longer available, this function fails with the last error set to **ERROR_NO_DATA**.

If the calling thread does not own the window to which the pointer message has been delivered, this function fails with the last error set to **ERROR_ACCESS_DENIED**.

If the specified pointer is not of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type), this function fails with the last error set to **ERROR_DATATYPE_MISMATCH**.

For apps that have both client and non-client areas, the input frame can include both client and non-client data. To differentiate between client and non-client data, you must perform hit testing on the target window.

We recommend the following if you want to filter data from the input frame:

* For each update that does not include a pointer contact (a [POINTER_FLAG_UPDATE](https://learn.microsoft.com/windows/win32/inputmsg/pointer-flags-contants) without **POINTER_FLAG_INCONTACT**), hit test to determine if the input is client or non-client.
* For each new contact ([POINTER_FLAG_DOWN](https://learn.microsoft.com/windows/win32/inputmsg/pointer-flags-contants)), hit test to determine if the input is client or non-client and track this info.
* For each update that includes a pointer contact (a [POINTER_FLAG_UPDATE](https://learn.microsoft.com/windows/win32/inputmsg/pointer-flags-contants) with **POINTER_FLAG_INCONTACT**), use the tracking info to determine whether the input is client or non-client.
* For each [POINTER_FLAG_UP](https://learn.microsoft.com/windows/win32/inputmsg/pointer-flags-contants), use the tracking info to determine whether the input is client or non-client and then clear this pointer from the tracking data.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)

[GetPointerFrameTouchInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframetouchinfohistory)

[GetPointerTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfo)

[GetPointerTouchInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfohistory)