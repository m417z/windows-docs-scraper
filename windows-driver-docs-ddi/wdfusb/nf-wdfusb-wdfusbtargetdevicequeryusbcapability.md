# WdfUsbTargetDeviceQueryUsbCapability function

## Description

[Applies to KMDF and UMDF]

 The **WdfUsbTargetDeviceQueryUsbCapability** method determines whether the host controller and USB driver stack support a specific capability.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object.

### `CapabilityType` [in]

A pointer to a GUID that represents the capability about which the client driver wants to retrieve information. The possible *PGUID* values are as follows:

* GUID_USB_CAPABILITY_CHAINED_MDLS
* GUID_USB_CAPABILITY_STATIC_STREAMS
* GUID_USB_CAPABILITY_SELECTIVE_SUSPEND
* GUID_USB_CAPABILITY_FUNCTION_SUSPEND
* GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE
* GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE

See more information in Remarks.

### `CapabilityBufferLength` [in]

Length, in bytes, of the buffer pointed to by *CapabilityBuffer*.

### `CapabilityBuffer` [out, optional]

A pointer to a caller-allocated buffer to receive the requested USB capability. This parameter is optional. If
*CapabilityBufferLength* is zero, this parameter must be NULL. Similarly, if *CapabilityBufferLength* is nonzero, this parameter must be supplied. This parameter corresponds to the *OutputBuffer* parameter of the [USBD_QueryUsbCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406230(v=vs.85)) routine.

### `ResultLength` [out, optional]

A pointer to a location containing the size, in bytes, of the returned capability. This parameter is optional.

## Return value

**WdfUsbTargetDeviceQueryUsbCapability** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | The USB device object handle is not valid. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_PARAMETER** | The caller passed an invalid parameter value.<br><br>* *UsbDevice* or *CapabilityType* is NULL.<br>* *CapabilityBuffer* is NULL but *CapabilityBufferLength* contains a nonzero value. Conversely, the caller provided a *CapabilityBuffer* but *CapabilityBufferLength* is zero. |
| **STATUS_NOT_IMPLEMENTED** | The specified capability is not supported by the underlying USB driver stack. |
| **STATUS_NOT_SUPPORTED** | The specified capability is not supported by the host controller hardware. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Before calling **WdfUsbTargetDeviceQueryUsbCapability**, the driver must call [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters) to register with the underlying USB driver stack.

**WdfUsbTargetDeviceQueryUsbCapability** must be called after the driver's [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function has been called.

The following table describes the USB-specific capabilities that a KMDF-based USB client driver can query through a **WdfUsbTargetDeviceQueryUsbCapability** call.

| Capability GUID | Description |
| --- | --- |
| GUID_USB_CAPABILITY_CHAINED_MDLS | The new USB driver stack in Windows 8 is capable of accepting a chained MDL (see [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)) from a KMDF-based USB client driver.<br><br> For more information about the chained MDLs capability in the USB driver stack, see [How to Send Chained MDLs](https://learn.microsoft.com/windows-hardware/drivers/ddi/). <br><br>This GUID applies to KMDF drivers only. |
| GUID_USB_CAPABILITY_STATIC_STREAMS | Whereas USB 2.0 and earlier supports sending only a single data stream through a bulk endpoint, USB 3.0 permits sending and receiving multiple data streams through a bulk endpoint. <br><br>For more information about opening streams, see [How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/).<br><br>This GUID applies to KMDF drivers only. |
| GUID_USB_CAPABILITY_FUNCTION_SUSPEND | The Universal Serial Bus (USB) 3.0 specification defines a new feature called function suspend. The feature enables an individual function of a composite device to enter a low-power state, independently of other functions. <br><br>For more information about function suspend, see [How to Implement Function Suspend in a Composite Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/).<br><br>This GUID applies to KMDF drivers only. |
| GUID_USB_CAPABILITY_SELECTIVE_SUSPEND | For information about selective suspend, see [USB Selective Suspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/).<br><br>This GUID applies to KMDF drivers only. |
| GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE | Determines whether the bus is operating at high-speed or higher. <br><br>This GUID applies to KMDF and UMDF drivers. |
| GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE | Determines whether the bus is operating at SuperSpeed or higher.<br><br>This GUID applies to KMDF and UMDF drivers. |

## See also

[USBD_QueryUsbCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406230(v=vs.85))

[WdfUsbTargetDeviceRetrieveInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceretrieveinformation)