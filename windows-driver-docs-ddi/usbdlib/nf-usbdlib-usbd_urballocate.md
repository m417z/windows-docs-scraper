# USBD_UrbAllocate function

## Description

The **USBD_UrbAllocate** routine allocates a USB Request Block (URB).

## Parameters

### `USBDHandle` [in]

USBD handle that is retrieved by the client driver in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `Urb` [out]

Pointer to the newly allocated [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure. All members of the structure are set to zero. The client driver must free the URB when the driver has finished using it by calling [USBD_UrbFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urbfree).

## Return value

The **USBD_UrbAllocate** routine returns STATUS_SUCCESS if the request is successful. Otherwise, **USBD_UrbAllocate** sets *Urb* to NULL and returns a failure code.

Possible values include, but are not limited to, STATUS_INVALID_PARAMETER, which indicates the caller passed in NULL to *USBDHandle* or *Urb*.

## Remarks

The **USBD_UrbAllocate** routine enables the underlying USB driver stack to allocate an opaque URB context for the URB. By using the URB context, the USB driver stack can process requests more efficiently and reliably. Those optimizations are provided by the USB 3.0 driver stack that is included in Windows 8. The client driver cannot access the URB context; the context is used internally by the bus driver.

Regardless of the USB protocol version of the host controller, the underlying USB driver stack, the target operating system, the client driver must always call **USBD_UrbAllocate** to allocate an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure. **USBD_UrbAllocate** replaces earlier allocation mechanisms, such as [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag), or allocating them on the stack.

The client driver must *not* use **USBD_UrbAllocate**,

* To allocate an URB that has variable length, such as an URB for an isochronous transfer. Instead the client driver must call [USBD_IsochUrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isochurballocate).
* If the target operating system is Windows XP with Service Pack 2 (SP2) or an earlier version of Windows.

For more information about replacement routines, see [Allocating and Building URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-add-xrb-support-for-client-drivers).

You must call [USBD_UrbFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urbfree) to release the URB allocated by **USBD_UrbAllocate**.

#### Examples

The following code example shows how to allocate, submit, and release a URB. The example submits the URB synchronously. For the implementation of the SubmitUrbSync function, see the example section in [How to Submit an URB](https://learn.microsoft.com/windows-hardware/drivers/usbcon/send-requests-to-the-usb-driver-stack).

```cpp
NTSTATUS CreateandSubmitURBSynchronously (
    _In_ USBD_HANDLE USBDHandle
{
    PURB    Urb = NULL;

    NTSTATUS status;

    status = USBD_UrbAllocate(USBDHandle, &Urb);

    if (!NT_SUCCESS(status))
    {
        goto CreateandSubmitURBExit;
    }

    //Format the URB for the request. Not Shown.
    status = BuildURBForBulkTransfer (Urb);

    if (!NT_SUCCESS(status))
    {
        goto CreateandSubmitURBExit;
    }

    status = SubmitUrbSync( TargetDeviceObject,
        Urb)

    if (!NT_SUCCESS(status))
    {
        goto CreateandSubmitURBExit;
    }

CreateandSubmitURBExit:

    if (Urb)
    {
        USBD_UrbFree( USBDHandle, Urb);
    }

    return status;

}

```

## See also

[Allocating and Building URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-add-xrb-support-for-client-drivers)

[Sending Requests to a USB Device](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[USBD_UrbFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urbfree)