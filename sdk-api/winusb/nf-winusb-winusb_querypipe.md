# WinUsb_QueryPipe function

## Description

The **WinUsb_QueryPipe** function retrieves information about the specified endpoint and the associated pipe for an interface.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface that contains the endpoint with which the pipe is associated.

To query the pipe associated with an endpoint in the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `AlternateInterfaceNumber` [in]

A value that specifies the alternate interface to return the information for.

### `PipeIndex` [in]

A value that specifies the pipe to return information about. This value is not the same as the **bEndpointAddress** field in the endpoint descriptor. A *PipeIndex*  value of 0 signifies the first endpoint that is associated with the interface, a value of 1 signifies the second endpoint, and so on. *PipeIndex* must be less than the value in the **bNumEndpoints** field of the interface descriptor.

### `PipeInformation` [out]

A pointer, on output, to a caller-allocated [WINUSB_PIPE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winusbio/ns-winusbio-winusb_pipe_information) structure that contains pipe information.

## Return value

**WinUsb_QueryPipe** returns **TRUE** if the operation succeeds. Otherwise, this function returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |
| **ERROR_INVALID_PARAMETER** | The caller passed **NULL** in the *PipeInformation*  parameter; interface descriptor could not be found for the handle specified in *InterfaceHandle*. |
| **ERROR_NO_MORE_ITEMS** | The value passed in the *PipeIndex* parameter is greater than the **bNumEndpoints** value of the interface descriptor; endpoint descriptor could not be found for the specified interface. |

## Remarks

The **WinUsb_QueryPipe** function does not retrieve information about the control pipe.

Each interface on the USB device can have multiple endpoints. To communicate with each of these endpoints, the bus driver creates pipes for each endpoint on the interface. The pipe indices are zero-based. Therefore for *n* number of endpoints, the pipes' indices are set from *n*-1. **WinUsb_QueryPipe** parses the configuration descriptor to get the interface specified by the caller. It searches the interface descriptor for the endpoint descriptor associated with the caller-specified pipe. If the endpoint is found, the function populates the caller-allocated [WINUSB_PIPE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winusbio/ns-winusbio-winusb_pipe_information) structure with information from the endpoint descriptor.

## See also

[WINUSB_PIPE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winusbio/ns-winusbio-winusb_pipe_information)

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)