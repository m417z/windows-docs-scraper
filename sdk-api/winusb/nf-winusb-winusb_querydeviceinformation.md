# WinUsb_QueryDeviceInformation function

## Description

The **WinUsb_QueryDeviceInformation** function gets information about the physical device that is associated with a WinUSB interface handle.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to the first interface on the device, which is returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

### `InformationType` [in]

A value that specifies which interface information value to retrieve.

On input, *InformationType* must have the following value: DEVICE_SPEED (0x01).

### `BufferLength` [in, out]

The maximum number of bytes to read. This number must be less than or equal to the size, in bytes, of *Buffer*. On output, *BufferLength* is set to the actual number of bytes that were copied into *Buffer*.

### `Buffer` [out]

A caller-allocated buffer that receives the requested value.

If *InformationType* is DEVICE_SPEED, on successful return, *Buffer* indicates the operating speed of the device. 0x03 indicates high-speed or higher; 0x01 indicates full-speed or lower.

## Return value

**WinUsb_QueryDeviceInformation** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)