# WinUsb_ReadPipe function

## Description

The **WinUsb_ReadPipe** function reads data from the specified pipe.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to the interface that contains the endpoint with which the pipe is associated.

To read data from the pipe associated with an endpoint in the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `PipeID` [in]

*PipeID* corresponds to the **bEndpointAddress** field in the endpoint descriptor. For information about the layout of this field, see **Table 9-13** in "Universal Serial Bus Specification Revision 2.0" at [USB Technology](https://www.microsoft.com/whdc/connect/usb/default.mspx). In the **bEndpointAddress** field, Bit 7 indicates the direction of the endpoint: 0 for OUT; 1 for IN.

### `Buffer` [out]

A caller-allocated buffer that receives the data that is read.

### `BufferLength` [in]

The maximum number of bytes to read. This number must be less than or equal to the size, in bytes, of *Buffer*.

### `LengthTransferred` [out, optional]

A pointer to a ULONG variable that receives the actual number of bytes that were copied into *Buffer*. For more information, see Remarks.

### `Overlapped` [in, optional]

An optional pointer to an OVERLAPPED structure that is used for asynchronous operations. If this parameter is specified, **WinUsb_ReadPipe** returns immediately rather than waiting synchronously for the operation to complete before returning. An event is signaled when the operation is complete.

## Return value

**WinUsb_ReadPipe** returns **TRUE** if the operation succeeds. Otherwise, this function returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |
| **ERROR_IO_PENDING** | An overlapped I/O operation is in progress but has not completed. If the overlapped operation cannot be completed immediately, the function returns **FALSE** and the **GetLastError** function returns ERROR_IO_PENDING, indicating that the operation is executing in the background. Call [WinUsb_GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getoverlappedresult) to check the success or failure of the operation. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is insufficient memory to perform the operation. |
| **ERROR_SEM_TIMEOUT** | The read operation initiated by [WinUsb_ReadPipe](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_readpipe) in the USB stack timed out before the operation could be completed. |

## Remarks

If the data returned by the device is greater than a maximum transfer length, WinUSB divides the request into smaller requests of maximum transfer length and submits them serially. If the transfer length is not a multiple of the endpoint's maximum packet size (retrievable through the [WINUSB_PIPE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winusbio/ns-winusbio-winusb_pipe_information) structure's **MaximumPacketSize** member), WinUSB increases the size of the transfer to the next multiple of **MaximumPacketSize**.

USB packet size does not factor into the transfer for a read request. If the device responds with a packet that is too large for the client buffer, the behavior of the read request corresponds to the type of policy set on the pipe. If policy type for the pipe is ALLOW_PARTIAL_READS, WinUSB adds the remaining data to the beginning of the next transfer. If ALLOW_PARTIAL_READS is not set, the read request fails. For more information about policy types, see [WinUSB Functions for Pipe Policy Modification](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/).

If an application passes **NULL** in the *Overlapped* parameter (synchronous operation), the application must make sure that *LengthTransferred* is not **NULL**, even when the read operation produces no output data.

If *Overlapped* is not **NULL** (asynchronous operation), *LengthTransferred* can be set to **NULL**. For an overlapped operation (and if *LengthTransferred* is a non-**NULL** value), the value received in *LengthTransferred* after **WinUsb_ReadPipe** returns is meaningless until the overlapped operation has completed. To retrieve the actual number of bytes read from the pipe, call [WinUsb_GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getoverlappedresult).

When no data is available in the endpoint (pipe is empty), **WinUsb_ReadPipe** does not return until there is data in the pipe. If an error condition occurs or the application-specified timeout expires, **WinUsb_ReadPipe** always returns FALSE. To determine the actual reason for that return value, always call **GetLastError**. For example, in these cases the **GetLastError** error value indicates the actual reason:

* If the application specified a timeout value in the pipe policy and that timeout expires, **WinUsb_ReadPipe** returns FALSE and **GetLastError** returns ERROR_SEM_TIMEOUT.
* If an error condition occurs while reading data from the pipe, **WinUsb_ReadPipe** returns FALSE and **GetLastError** returns ERROR_GEN_FAILURE.

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)