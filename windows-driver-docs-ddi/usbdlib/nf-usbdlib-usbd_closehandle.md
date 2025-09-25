# USBD_CloseHandle function

## Description

The **USBD_CloseHandle** routine is called by a USB client driver to close a USBD handle and release all resources associated with the driver's registration.

## Parameters

### `USBDHandle` [in]

USBD handle to be closed. The handle is retrieved by the client driver in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

## Remarks

A client driver should call **USBD_CloseHandle** in the driver's routine that handles the [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) IRP. The client driver must call the routine before sending the IRP down the USB driver stack.

## See also

[Allocating and Building URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-add-xrb-support-for-client-drivers)

[USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle)