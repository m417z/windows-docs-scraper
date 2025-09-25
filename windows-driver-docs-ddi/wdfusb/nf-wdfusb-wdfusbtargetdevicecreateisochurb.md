# WdfUsbTargetDeviceCreateIsochUrb function

## Description

[Applies to KMDF only]

 The
**WdfUsbTargetDeviceCreateIsochUrb** method allocates an isochronous USB request block (URB).

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Attributes` [in, optional]

A pointer to a caller-supplied [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new memory object. If the driver provides this parameter, the structure's **ParentObject** member must be a USB device object (WDFUSBDEVICE) or a request object (WDFREQUEST) created by the framework, or any object whose chain of parents leads to one of these types. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `NumberOfIsochPackets` [in]

Specifies the number of isochronous packets for which the system allocates memory in the URB.

### `UrbMemory` [out]

A pointer to a WDFMEMORY-typed location that receives a handle to a framework memory object.

### `Urb` [out, optional]

A pointer to an URB structure that receives the address of the new isochronous URB. The framework initializes contents of the URB structure to zero. This parameter is optional and can be NULL.

## Return value

**WdfUsbTargetDeviceCreateIsochUrb** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INVALID_DEVICE_STATE** | The driver did not specify a client contract version when it called [WDF_USB_DEVICE_CREATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_create_config_init). |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Before calling **WdfUsbTargetDeviceCreateIsochUrb**, a driver must call [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters). If successful, **WdfUsbTargetDeviceCreateIsochUrb** returns a handle to a framework memory object that describes the newly allocated isochronous URB.

A driver can call **WdfUsbTargetDeviceCreateIsochUrb** to allocate a URB structure before calling [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb).

Typically, a driver calls **WdfUsbTargetDeviceCreateIsochUrb** from within a [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

The memory object and its buffer are deleted when the parent object is deleted. A driver can also delete a memory object and its buffer by calling [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete).

For related information, see the Remarks section of [WdfUsbTargetDeviceCreateUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateurb).

#### Examples

The following code example is based on the PerformIsochTransfer routine in the Isorwr sample driver. The example calls **WdfUsbTargetDeviceCreateIsochUrb** to allocate an isochronous USB request block. The example determines the number of bytes required to hold the isochronous transfer request, and then manually configures the URB header and the isochronous packets in the URB. At this point, the driver can call [WdfUsbTargetPipeFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforurb), as shown in the example in [WdfUsbTargetDeviceCreateUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateurb).

```cpp

USBD_PIPE_HANDLE usbdPipeHandle;
ULONG numPackets = UserBufferLength/TransferSizePerFrame;
ULONG urbSize;
PURB urb;
WDFMEMORY memory;

WDF_OBJECT_ATTRIBUTES_INIT(&objectAttribs);
objectAttribs.ParentObject = UsbDevice;

status = WdfUsbTargetDeviceCreateIsochUrb(
                                     pDevContext->WdfUsbTargetDevice,
                                     &objectAttribs,
                                     0,
                                     numPackets,
                                     &memory,
                                     NULL
                                     );

urb = WdfMemoryGetBuffer(urbMemory, &urbSize);
urbSize = GET_ISO_URB_SIZE(numPackets);

usbdPipeHandle = WdfUsbTargetPipeWdmGetPipeHandle(pipe);
urb->UrbIsochronousTransfer.Hdr.Length = GET_ISO_URB_SIZE(numPackets);
urb->UrbIsochronousTransfer.Hdr.Function = URB_FUNCTION_ISOCH_TRANSFER;
urb->UrbIsochronousTransfer.PipeHandle = usbdPipeHandle;

for (packetId = 0; packetId < numberOfPackets; packetId++) {

     Urb-> UrbIsochronousTransfer.IsoPacket[packetId].Offset = xxx;
     Urb-> UrbIsochronousTransfer.IsoPacket[packetId].YYY = yyy;
}

```

## See also

[WdfUsbTargetDeviceCreateUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateurb)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)