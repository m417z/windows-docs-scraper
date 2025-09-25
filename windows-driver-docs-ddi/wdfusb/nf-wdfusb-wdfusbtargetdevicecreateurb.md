# WdfUsbTargetDeviceCreateUrb function

## Description

[Applies to KMDF only]

 The
**WdfUsbTargetDeviceCreateUrb** method allocates a USB request block (URB).

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Attributes` [in, optional]

A pointer to a caller-supplied [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new memory object. If the driver provides this parameter, the structure's **ParentObject** member must be a USB device object (WDFUSBDEVICE) or a request object (WDFREQUEST) created by the framework, or any object whose chain of parents leads to one of these types. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `UrbMemory` [out]

A pointer to a WDFMEMORY-typed location that receives a handle to a framework memory object.

### `Urb` [out, optional]

A pointer to an URB structure that receives the address of the newly allocated URB. This parameter is optional and can be NULL.

## Return value

**WdfUsbTargetDeviceCreateUrb** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INVALID_DEVICE_STATE** | The driver did not specify a client contract version when it called [WDF_USB_DEVICE_CREATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_create_config_init). |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to create a new URB. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Before calling **WdfUsbTargetDeviceCreateUrb**, a driver must call [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters). If successful, **WdfUsbTargetDeviceCreateUrb** returns a handle to a framework memory object that describes the newly allocated URB. Typically, a driver calls **WdfUsbTargetDeviceCreateUrb** from within a [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

A driver can call **WdfUsbTargetDeviceCreateUrb** to allocate an URB structure before calling [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb).

**WdfUsbTargetDeviceCreateUrb** is similar in operation to [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate). Both methods allocate a framework memory object, and both methods also provide the option of receiving the buffer (in this case, the URB) associated with the memory object. In both cases, the caller can also retrieve the buffer later by calling [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

If the driver provides an *Urb* parameter when it calls **WdfUsbTargetDeviceCreateUrb**, you can format the URB manually or by calling the UsbBuildXxx routines.

The memory object and its buffer are deleted when the parent object is deleted. A driver can also delete a memory object and its buffer by calling [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete).

#### Examples

The following code example declares a framework memory object. The example calls **WdfUsbTargetDeviceCreateUrb** to allocate a USB request block, and then calls [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb) to format a request that uses the URB structure's contents. Finally, the example registers a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function and sends the request to an I/O target.

```cpp
WDFMEMORY memory;
PURB urb = NULL;

WDF_OBJECT_ATTRIBUTES_INIT(&objectAttribs);
objectAttribs.ParentObject = UsbDevice;

status = WdfUsbTargetDeviceCreateUrb(
    pDevContext->WdfUsbTargetDevice,
    &objectAttribs,
    &memory,
    &urb);

status = WdfUsbTargetDeviceFormatRequestForUrb(
    deviceContext->WdfUsbTargetDevice,
    request,
    memory,
    NULL);

WdfRequestSetCompletionRoutine(
    request,
    MyCompletionRoutine,
    NULL);

if (!WdfRequestSend(
        request,
        WdfUsbTargetDeviceGetIoTarget(UsbDevice),
        NULL)) {
    status = WdfRequestGetStatus(request);
}

```

## See also

[WDF_USB_DEVICE_CREATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_create_config_init)

[WdfUsbTargetDeviceCreateIsochUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateisochurb)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)

[WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb)