# USBD_UrbFree function

## Description

The **USBD_UrbFree** routine releases the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) that is allocated by [USBD_UrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urballocate), [USBD_IsochUrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isochurballocate), [USBD_SelectConfigUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectconfigurballocateandbuild), or
[USBD_SelectInterfaceUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectinterfaceurballocateandbuild).

## Parameters

### `USBDHandle` [in]

USBD handle that is retrieved by the client driver in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `Urb` [in]

Pointer to the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure to be released.

## Remarks

You must call **USBD_UrbFree** to release the URB allocated by [USBD_UrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urballocate) after the request is complete.

Failure to call **USBD_UrbFree** can cause a memory leak.

For a code example, see [USBD_UrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urballocate).

## See also

[Allocating and Building URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-add-xrb-support-for-client-drivers)

[USBD_UrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urballocate)