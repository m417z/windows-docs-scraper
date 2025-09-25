# WinUsb_SetPipePolicy function

## Description

The **WinUsb_SetPipePolicy** function sets the policy for a specific pipe associated with an endpoint on the device. This is a synchronous operation.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface that contains the endpoint with which the pipe is associated.

To set policy for the pipe associated with the endpoint in the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `PipeID` [in]

An 8-bit value that consists of a 7-bit address and a direction bit. This parameter corresponds to the **bEndpointAddress** field in the endpoint descriptor.

### `PolicyType` [in]

A **ULONG** variable that specifies the policy parameter to change. The *Value* parameter contains the new value for the policy parameter, defined in *winusbio.h*. For information about how to use each of the pipe policies and the resulting behavior, see [WinUSB Functions for Pipe Policy Modification](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/).

### `ValueLength` [in]

The size, in bytes, of the buffer at *Value*.

### `Value` [in]

The new value for the policy parameter that *PolicyType* specifies. The size of this input parameter depends on the policy to change. For information about the size of this parameter, see the description of the *PolicyType* parameter.

## Return value

**WinUsb_SetPipePolicy** returns **TRUE** if the operation succeeds. Otherwise, this function returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |
| **ERROR_INVALID_PARAMETER** | The caller passed an invalid size for the policy parameter buffer in the *ValueLength* parameter. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that there is insufficient memory to perform the operation. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUSB Functions for Pipe Policy Modification](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUsb_GetPipePolicy](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getpipepolicy)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)