# WinUsb_UnregisterIsochBuffer function

## Description

The **WinUsb_UnregisterIsochBuffer** function releases all of the resources that [WinUsb_RegisterIsochBuffer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_registerisochbuffer) allocated for isochronous transfers. This is a synchronous operation.

## Parameters

### `IsochBufferHandle` [in]

An opaque handle to the transfer buffer that was registered by a previous call to [WinUsb_RegisterIsochBuffer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_registerisochbuffer).

## Return value

**WinUsb_UnregisterIsochBuffer** returns TRUE if the operation succeeds. Otherwise this function returns FALSE, and the caller can retrieve the logged error by calling **GetLastError**.

## Remarks

The caller must ensure that there are no pending transfers that is currently using the buffer before calling **WinUsb_UnregisterIsochBuffer**. If there are pending transfers, **WinUsb_UnregisterIsochBuffer** blocks until those transfers are complete.

## See also

[Send USB isochronous transfers from a WinUSB desktop app](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_RegisterIsochBuffer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_registerisochbuffer)