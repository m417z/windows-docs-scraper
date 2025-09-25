# WinUsb_WritePipe function

## Description

The **WinUsb_WritePipe** function writes data to a pipe.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to the interface that contains the endpoint with which the pipe is associated.

To write to a pipe that is associated with an endpoint in the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `PipeID` [in]

*PipeID* corresponds to the **bEndpointAddress** field in the endpoint descriptor. For information about the layout of this field, see **Table 9-13** in "Universal Serial Bus Specification Revision 2.0" at [USB Technology](https://www.microsoft.com/whdc/connect/usb/default.mspx). In the **bEndpointAddress** field, Bit 7 indicates the direction of the endpoint: 0 for OUT; 1 for IN.

### `Buffer` [in]

A caller-allocated buffer that contains the data to write.

### `BufferLength` [in]

The number of bytes to write. This number must be less than or equal to the size, in bytes, of *Buffer*.

### `LengthTransferred` [out, optional]

A pointer to a ULONG variable that receives the actual number of bytes that were written to the pipe. For more information, see Remarks.

### `Overlapped` [in, optional]

An optional pointer to an OVERLAPPED structure, which is used for asynchronous operations. If this parameter is specified, **WinUsb_WritePipe** immediately returns, and the event is signaled when the operation is complete.

## Return value

**WinUsb_WritePipe** returns **TRUE** if the operation succeeds. Otherwise, this function returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |
| **ERROR_IO_PENDING** | Indicates that an overlapped I/O operation is in progress but has not completed. If the overlapped operation cannot be completed immediately, the function returns **FALSE** and the **GetLastError** function returns ERROR_IO_PENDING, indicating that the operation is executing in the background. Call [WinUsb_GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getoverlappedresult) to check the success or failure of the operation. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that there is insufficient memory to perform the operation. |
| **ERROR_SEM_TIMEOUT** | The write operation initiated by [WinUsb_WritePipe](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_writepipe) in the USB stack timed out before the operation could be completed. |

## Remarks

To create a write request, your the application must allocate a buffer, fill it with the data that you want to write to the device, and send the buffer to the host controller by calling **WinUsb_WritePipe**.

The following restrictions apply to the size of the buffer if RAW_IO is set:

* The buffer length must be a multiple of the maximum endpoint packet size.
* The length must be less than or equal to the value of MAXIMUM_TRANSFER_SIZE retrieved by [WinUsb_GetPipePolicy](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getpipepolicy).

There are no restrictions on the size of the buffer if RAW_IO is not set as the pipe's policy type. If the size of the buffer is greater than the maximum transfer length reported by MAXIMUM_TRANSFER_SIZE, WinUSB divides the request into smaller requests and submits them serially to the host controller.

A write request that contains zero-length data is forwarded down the USB stack.

If an application passes **NULL** in the *Overlapped* parameter (synchronous operation), it must ensure that *LengthTransferred* is not **NULL**, even when an operation produces no output data.

If *Overlapped* is not **NULL** (asynchronous operation), *LengthTransferred* can be set to **NULL**. For an overlapped operation (and if *LengthTransferred* is a non-**NULL** value), the value received in *LengthTransferred* after **WinUsb_WritePipe** returns is meaningless until the overlapped operation has completed. To retrieve the actual number of bytes returned, call [WinUsb_GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getoverlappedresult).

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)