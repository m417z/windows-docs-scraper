# GetPointerTouchInfoHistory function

## Description

Gets the touch-based information associated with the individual inputs, if any, that were coalesced into the current message for the specified pointer (of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)). The most recent input is included in the returned history and is the same as the most recent input returned by the [GetPointerTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfo) function.

## Parameters

### `pointerId` [in]

An identifier of the pointer for which to retrieve information.

### `entriesCount` [in, out]

A pointer to a variable that specifies the count of structures in the buffer to which touchInfo points. If **GetPointerTouchInfoHistory** succeeds, *entriesCount* is updated with the total count of structures available. The total count of structures available is the same as the *historyCount* field in the [POINTER_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_info) structure returned by a call to [GetPointerInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfo) or [GetPointerTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfo).

### `touchInfo` [out, optional]

Address of an array of [POINTER_TOUCH_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_touch_info) structures to receive the pointer information. This parameter can be NULL if *entriesCount is zero.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the application does not process pointer input messages as fast as they are generated, some moves may be coalesced. When an application receives a coalescable pointer (of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)) message, it can use the **GetPointerTouchInfoHistory** function to retrieve information for all the individual inputs, if any, that were coalesced into the message. Note that the information retrieved is associated with the pointer message most recently retrieved by the calling thread. Once the calling thread retrieves its next message, the information associated with the previous message may no longer be available.

The information retrieved appears in reverse chronological order, with the most recent entry in the first row of the returned array. The most recent entry is the same as that returned by the [GetPointerTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfo) function.

If the count of rows in the buffer provided is insufficient to hold all available history entries, this function succeeds with the buffer containing the most recent entries and **entriesCount* containing the total count of entries available.

If the pointer frame contains no additional pointers besides the specified pointer, this function succeeds and returns only the information for the specified pointer.

If the information associated with the pointer frame is no longer available, this function fails with the last error set to **ERROR_NO_DATA**.

If the calling thread does not own the window (where the input was originally delivered or where the message was forwarded) to which the pointer message has been delivered, this function fails with the last error set to **ERROR_ACCESS_DENIED**.

If the specified pointer is not of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type), this function fails with the last error set to **ERROR_DATATYPE_MISMATCH**.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)

[GetPointerFrameTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframetouchinfo)

[GetPointerFrameTouchInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframetouchinfohistory)

[GetPointerTouchInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointertouchinfo)