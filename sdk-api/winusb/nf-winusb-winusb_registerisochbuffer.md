# WinUsb_RegisterIsochBuffer function

## Description

The **WinUsb_RegisterIsochBuffer** function registers a buffer to be used for isochronous transfers.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface in the selected configuration. That handle must be created by a previous call to [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize) or [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `PipeID` [in]

Derived from Bit 3...0 of the **bEndpointAddress** field in the endpoint descriptor.

### `Buffer` [in]

Pointer to the transfer buffer to be registered.

### `BufferLength` [in]

Length, in bytes, of the transfer buffer pointed to by *Buffer*.

### `IsochBufferHandle` [out]

Receives an opaque handle to the registered buffer. This handle is required by other WinUSB functions that perform isochronous transfers. To release the handle, call the [WinUsb_UnregisterIsochBuffer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_unregisterisochbuffer) function.

## Return value

**WinUsb_RegisterIsochBuffer** returns TRUE if the operation succeeds. Otherwise this function returns FALSE, and the caller can retrieve the logged error by calling **GetLastError**.

If the caller sets *ContinueStream* to TRUE, The transfer fails if Winusb.sys is unable to schedule the transfer to continue the stream without dropping one or more frames.

## Remarks

Prior to initiating isochronous transfers to or from a buffer, the caller must register the buffer with **WinUsb_RegisterIsochBuffer**. This call allows the Winusb.sys to pre-map and lock the buffer after for all subsequent transfers using the buffer.

## See also

[Send USB isochronous transfers from a WinUSB desktop app](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_UnregisterIsochBuffer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_unregisterisochbuffer)