# GetPointerInputTransform function

## Description

Gets one or more transforms for the pointer information coordinates associated with the current message.

## Parameters

### `pointerId` [in]

An identifier of the pointer for which to retrieve information.

### `historyCount` [in]

The number of [INPUT_TRANSFORM](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input_transform) structures that *inputTransform* can point to.

This value must be no less than 1 and no greater than the value specified in **historyCount** of the [POINTER_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_info) structure returned by [GetPointerInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfo), [GetPointerTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfo), or [GetPointerPenInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerpeninfo) (for a single input transform) or [GetPointerInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfohistory), [GetPointerTouchInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfohistory), or [GetPointerPenInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerpeninfohistory) (for an array of input transforms).

If **GetPointerInputTransform** succeeds, *inputTransform* is updated with the total count of structures available. The total count of structures available is the same as the **historyCount** field of the [POINTER_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_info) structure.

### `inputTransform` [out]

Address of an array of [INPUT_TRANSFORM](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input_transform) structures to receive the transform information. This parameter cannot be NULL.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A consumer of pointer input messages typically uses [ScreenToClient](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-screentoclient) or [MapWindowPoints](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapwindowpoints) to convert screen coordinates to client coordinates.

If a transform is applied on the message consumer, use **GetPointerInputTransform** to retrieve the transform on the message consumer at the time the input occurred. The inverse of this transform can then be used to convert pointer input coordinates from screen coordinates to the client coordinates of the message consumer.

If an input transform is not associated with the input, the **GetPointerInputTransform** function fails with the last error set to **ERROR_NO_DATA**. Use [ScreenToClient](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-screentoclient) or [MapWindowPoints](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapwindowpoints) instead.

The input transform does not respect any right-to-left layout setting on the input target. An application that requires adjusted coordinates for right-to-left layout must perform the right-to-left mirroring or combine an appropriate mirroring transform with the input transform.

The information returned by **GetPointerInputTransform** is associated with the most recent pointer message retrieved by the calling thread. When the next message is retrieved by the calling thread, the information associated with the previous message might no longer be available.

If an application calls [GetPointerInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfo), it can call **GetPointerInputTransform** with the same pointer Id and a single [INPUT_TRANSFORM](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input_transform) output buffer to get the input transform associated with the data.

If an application calls [GetPointerFrameInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfo), it can call **GetPointerInputTransform** with the same pointer Id and a single [INPUT_TRANSFORM](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input_transform) output buffer to get the input transform associated with the data. The same input transform applies to the entire frame.

If an application calls [GetPointerInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfohistory), it can call **GetPointerInputTransform** with the same pointer Id and an output buffer to hold the entries retrieved using **GetPointerInfoHistory**. Each input transform in the returned array can be used with the corresponding entry in the array returned by **GetPointerInfoHistory**.

If an application calls [GetPointerFrameInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfohistory), it can call **GetPointerInputTransform** with the same pointer Id and an output buffer to hold the entries retrieved using [GetPointerInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfohistory). Each input transform in the returned array can be used with the corresponding frame in the array returned by **GetPointerFrameInfoHistory**, with the same input transform being applied to the entire frame.

If the information associated with the message is no longer available, this function fails with the last error set to **ERROR_INVALID_PARAMETER**.

If *historyCount* contains a value larger than the **historyCount** field of the [POINTER_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_info) structure returned by [GetPointerInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfo) (or the first **POINTER_INFO** structure in the array returned by [GetPointerInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfohistory)), the function fails with the last error set to **ERROR_INVALID_PARAMETER**.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)

[INPUT_TRANSFORM](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input_transform)