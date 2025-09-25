# SkipPointerFrameMessages function

## Description

Determines which pointer input frame generated the most recently retrieved message for the specified pointer and discards any queued (unretrieved) pointer input messages generated from the same pointer input frame. If an application has retrieved information for an entire frame using the [GetPointerFrameInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfo) function, the [GetPointerFrameInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfohistory) function or one of their type-specific variants, it can use this function to avoid retrieving and discarding remaining messages from that frame one by one.

## Parameters

### `pointerId` [in]

Identifier of the pointer. Pending messages will be skipped for the frame that includes the most recently retrieved input for this pointer.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Parallel-mode devices may report pointer input in frames, that is, they may report the state and position of all pointers from that device in a single input report to the system. Ideally, applications should view the entire frame as a single input unless the application-specific requirements dictate otherwise.

The **SkipPointerFrameMessages** function can be used in conjunction with the [GetPointerFrameInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfo) function (or one of its type-specific variants) to consume entire frames as a single input.

When an application sees a pointer message, it can use the [GetPointerFrameInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfo) function to retrieve the entire pointer input frame to which the pointer message belongs, hence obtaining an updated view of all of the pointers currently owned by the window. Note that the returned frame contains only pointers that are currently owned by the same window as the specified pointer.

Having retrieved the entire frame of information, the application can then call the **SkipPointerFrameMessages** function to skip remaining pointer messages associated with this frame that are pending retrieval. This saves the application the overhead of retrieving and processing the remaining messages one by one.

**Warning** The **SkipPointerFrameMessages** function should be used only when the caller can be sure that no other entity on the caller’s thread (such as [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal)) is expecting to retrieve pending pointer messages. For this reason, **SkipPointerFrameMessages** should not be used in conjunction with Direct Manipulation when processing multiple, simultaneous interactions.

Note that the information retrieved is associated with the pointer frame most recently retrieved by the calling thread. Once the calling thread retrieves its next message, the information associated with the previous pointer frame may no longer be available.

If the pointer frame contains no additional pointers besides the specified pointer, this function succeeds with no action.

If the calling thread does not own the window to which the pointer message has been delivered, this function fails with the last error set to **ERROR_ACCESS_DENIED**.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)