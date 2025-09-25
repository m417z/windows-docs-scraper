# WinUsb_GetPipePolicy function

## Description

The **WinUsb_GetPipePolicy** function retrieves the policy for a specific pipe associated with an endpoint on the device. This is a synchronous operation.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface that contains the endpoint with which the pipe is associated.

To query the pipe associated with the endpoint in the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `PipeID` [in]

An 8-bit value that consists of a 7-bit address and a direction bit. This parameter corresponds to the **bEndpointAddress** field in the endpoint descriptor.

### `PolicyType` [in]

A **ULONG** variable that specifies the policy parameter to retrieve. The current value for the policy parameter is retrieved the *Value* parameter. For information about the behavior of the pipe policies, see [WinUSB Functions for Pipe Policy Modification](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/).

### `ValueLength` [in, out]

A pointer to the size, in bytes, of the buffer that *Value* points to. On output, *ValueLength* receives the size, in bytes, of the data that was copied into the *Value*  buffer.

### `Value` [out]

A pointer to a buffer that receives the specified pipe policy value.

## Return value

**WinUsb_GetPipePolicy** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUSB Functions for Pipe Policy Modification](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)

[WinUsb_ReadPipe](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_readpipe)

[WinUsb_WritePipe](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_writepipe)