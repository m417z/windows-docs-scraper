# WinUsb_FlushPipe function

## Description

The **WinUsb_FlushPipe** function discards any data that is cached in a pipe. This is a synchronous operation.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to the interface with which the specified pipe's endpoint is associated. To clear data in a pipe that is associated with the endpoint on the first (default) interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `PipeID` [in]

The identifier (ID) of the control pipe. The *PipeID* parameter is an 8-bit value that consists of a 7-bit address and a direction bit. This parameter corresponds to the **bEndpointAddress** field in the endpoint descriptor.

## Return value

**WinUsb_FlushPipe** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)