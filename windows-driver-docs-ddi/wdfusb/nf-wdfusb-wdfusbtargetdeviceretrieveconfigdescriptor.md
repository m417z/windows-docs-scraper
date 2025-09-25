# WdfUsbTargetDeviceRetrieveConfigDescriptor function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceRetrieveConfigDescriptor** method retrieves the USB configuration descriptor for the USB device that is associated with a specified framework USB device object.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `ConfigDescriptor` [out]

A pointer to a caller-allocated buffer that receives a [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure, followed by one or more [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) and [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structures. This parameter is optional and can be **NULL**, in which case **WdfUsbTargetDeviceRetrieveConfigDescriptor** returns the required buffer length. For more information, see the following Remarks section.

### `ConfigDescriptorLength` [in, out]

A pointer to a location that supplies the length of the buffer that *ConfigDescriptor* points to. If the pointer that is supplied for *ConfigDescriptor* is **NULL**, **WdfUsbTargetDeviceRetrieveConfigDescriptor** returns the required buffer length at the location that is pointed to by *ConfigDescriptorLength*.

## Return value

**WdfUsbTargetDeviceRetrieveConfigDescriptor** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | A configuration descriptor was not available for the specified target. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_BUFFER_TOO_SMALL** | The specified buffer size was too small for the data, or the caller supplied **NULL** for the *ConfigDescriptor* parameter. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfUsbTargetDeviceRetrieveConfigDescriptor** method retrieves all of the specified USB device's configuration information (that is, the configuration descriptor plus any interface or endpoint descriptors that might be present). To learn about the format of this information, see the USB specification.

You can use [**WdfUsbTargetDeviceSelectConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig) to select only the first USB configuration listed in the descriptor list, but you can select multiple interfaces within this single configuration.

Drivers should call **WdfUsbTargetDeviceRetrieveConfigDescriptor** twice, as follows:

1. Set the *ConfigDescriptor* pointer to **NULL**, so that **WdfUsbTargetDeviceRetrieveConfigDescriptor** will return the required buffer size in the address that *ConfigDescriptorLength* points to.
2. Allocate buffer space to hold the configuration information. For example, a driver might call [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) to allocate a buffer, or it might call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) to create a framework memory object.
3. Call **WdfUsbTargetDeviceRetrieveConfigDescriptor** again, passing it a pointer to the new buffer and the buffer's size.

After the second call to **WdfUsbTargetDeviceRetrieveConfigDescriptor** returns, the buffer that is pointed to by *ConfigDescriptor* contains a [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure, followed by one or more [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) and [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structures. These latter structures are arranged in the order that is described in the USB specification.

For more information about the **WdfUsbTargetDeviceRetrieveConfigDescriptor** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example calls **WdfUsbTargetDeviceRetrieveConfigDescriptor** to obtain the required buffer size, calls [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) to create a memory object and buffer, and then calls **WdfUsbTargetDeviceRetrieveConfigDescriptor** again to obtain a device's configuration information.

```cpp
USHORT  size;
NTSTATUS  ntStatus;
PMY_DEVICE_CONTEXT  myDeviceContext;
PUSB_CONFIGURATION_DESCRIPTOR  configurationDescriptor = NULL;
WDF_OBJECT_ATTRIBUTES  objectAttribs;
WDFMEMORY  memoryHandle;

myDeviceContext = GetDeviceContext(Device);

ntStatus = WdfUsbTargetDeviceRetrieveConfigDescriptor(
                                            myDeviceContext->WdfUsbTargetDevice,
                                            NULL,
                                            &size
                                            );

if (ntStatus != STATUS_BUFFER_TOO_SMALL) {
    return ntStatus;
}

WDF_OBJECT_ATTRIBUTES_INIT(&objectAttribs);
objectAttribs.ParentObject = myDeviceContext->WdfUsbTargetDevice;

ntStatus = WdfMemoryCreate(
                           &objectAttribs,
                           NonPagedPool,
                           POOL_TAG,
                           size,
                           &memoryHandle,
                           (PVOID)&configurationDescriptor
                           );
if (!NT_SUCCESS(ntStatus)) {
    return ntStatus;
}

ntStatus = WdfUsbTargetDeviceRetrieveConfigDescriptor(
                                            myDeviceContext->WdfUsbTargetDevice,
                                            configurationDescriptor,
                                            &size
                                            );
if (!NT_SUCCESS(ntStatus)) {
    return ntStatus;
}
```

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)

[USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)

[WdfUsbTargetDeviceGetDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetdevicedescriptor)