# USBD_AssignUrbToIoStackLocation function

## Description

The **USBD_AssignUrbToIoStackLocation** routine is called by a client driver to associate an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) with the IRP's next stack location.

## Parameters

### `USBDHandle` [in]

A USBD handle that is retrieved in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `IoStackLocation` [in]

Pointer to the IRP's next stack location ([IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)). The client driver received a pointer to the stack location in a previous call to [IoGetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation).

### `Urb` [in]

Pointer to the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure that is allocated by [USBD_UrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urballocate), [USBD_IsochUrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isochurballocate), [USBD_SelectConfigUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectconfigurballocateandbuild), or
[USBD_SelectInterfaceUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectinterfaceurballocateandbuild).

## Remarks

If the client driver allocated an URB by calling [USBD_UrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urballocate), [USBD_IsochUrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isochurballocate), [USBD_SelectConfigUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectconfigurballocateandbuild), or
[USBD_SelectInterfaceUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectinterfaceurballocateandbuild), then the driver *must* call **USBD_AssignUrbToIoStackLocation** to associate the URB with [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) associated with the IRP. For URBs that are allocated by those routines, **USBD_AssignUrbToIoStackLocation** replaces setting **Parameters.Others.Argument1** of **IO_STACK_LOCATION** to the URB. (see [IOCTL_INTERNAL_USB_SUBMIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_submit_urb)).

The client driver must *not* call **USBD_AssignUrbToIoStackLocation** for an URB that is allocated by using other mechanisms, such as allocating the URB on the stack. Otherwise, the USB driver stack generates a bugcheck.

The client driver must call **USBD_AssignUrbToIoStackLocation** before calling [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) to send the request. **USBD_AssignUrbToIoStackLocation** populates the IRP's next stack location with the URB. The routine also updates the **FileObject** member of [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location).

For a code example, see [How to Submit an URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[How to Submit an URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[USBD_IsochUrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isochurballocate)

[USBD_SelectConfigUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectconfigurballocateandbuild)

[USBD_SelectInterfaceUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectinterfaceurballocateandbuild)

[USBD_UrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urballocate)