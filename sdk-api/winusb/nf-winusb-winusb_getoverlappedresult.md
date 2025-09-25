# WinUsb_GetOverlappedResult function

## Description

The **WinUsb_GetOverlappedResult** function retrieves the results of an overlapped operation on the specified file.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to the first interface on the device, which is returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

### `lpOverlapped` [in]

A pointer to an **OVERLAPPED** structure that was specified when the overlapped operation was started.

### `lpNumberOfBytesTransferred` [out]

A pointer to a variable that receives the number of bytes that were actually transferred by a read or write operation.

### `bWait` [in]

If this parameter is **TRUE**, the function does not return until the operation has been completed. If this parameter is **FALSE** and the operation is still pending, the function returns **FALSE** and the **GetLastError** function returns ERROR_IO_INCOMPLETE.

## Return value

If the function succeeds, the return value is any number other than zero. If the function fails, the return value is zero. To get extended error information, call **GetLastError**.

## Remarks

This function is like the Win32 API routine, **GetOverlappedResult**, with one difference—instead of passing a file handle that is returned from **CreateFile**, the caller passes an interface handle that is returned from [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). The caller can use either API routine, if the appropriate handle is passed. The **WinUsb_GetOverlappedResult**  function extracts the file handle from the interface handle and then calls **GetOverlappedResult**.

The results that are reported by the **WinUsb_GetOverlappedResult** function are those from the specified handle's last overlapped operation to which the specified **OVERLAPPED** structure was provided, and for which the operation's results were pending. A pending operation is indicated when the function that started the operation returns **FALSE**, and the **GetLastError** routine returns ERROR_IO_PENDING. When an I/O operation is pending, the function that started the operation resets the **hEvent** member of the **OVERLAPPED** structure to the nonsignaled state. Then when the pending operation has been completed, the system sets the event object to the signaled state.

The caller can specify that an event object is manually reset in the **OVERLAPPED** structure. If an automatic reset event object is used, the event handle must not be specified in any other wait operation in the interval between starting the overlapped operation and the call to **WinUsb_GetOverlappedResult**. For example, the event object is sometimes specified in one of the wait routines to wait for the operation to be completed. When the wait routine returns, the system sets an auto-reset event's state to nonsignaled, and a successive call to **WinUsb_GetOverlappedResult** with the *bWait* parameter set to **TRUE** causes the function to be blocked indefinitely.

If the *bWait* parameter is **TRUE**, **WinUsb_GetOverlappedResult** determines whether the pending operation has been completed by waiting for the event object to be in the signaled state.

If the **hEvent** member of the **OVERLAPPED** structure is **NULL**, the system uses the state of the file handle to signal when the operation has been completed. Do not use file handles for this purpose. It is better to use an event object because of the confusion that can occur when multiple concurrent overlapped operations are performed on the same file. In this situation, you cannot know which operation caused the state of the object to be signaled.

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)

[_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usb/ns-usb-_urb_control_descriptor_request)