# WdfUsbTargetDeviceCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceCreate** method creates a framework USB device object for a specified framework device object and opens the USB device for I/O operations.

**Note** If you are building your driver using KMDF 1.11 or UMDF 2.0, or later, we recommend that you call [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters) instead of **WdfUsbTargetDeviceCreate**.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Attributes` [in, optional]

A pointer to a caller-supplied [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new USB device object. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `UsbDevice` [out]

A pointer to a location that receives a handle to the new framework USB device object.

## Return value

**WdfUsbTargetDeviceCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to create a new USB device object. |
| **STATUS_UNSUCCESSFUL** | An attempt to get USB configuration information failed. |

For a list of other return values that the **WdfUsbTargetDeviceCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver that uses a USB I/O target must call **WdfUsbTargetDeviceCreate** after its device enters its working (D0) state. Typically, a driver calls **WdfUsbTargetDeviceCreate** from within its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. (The driver cannot call **WdfUsbTargetDeviceCreate** from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.)

**WdfUsbTargetDeviceCreate** obtains the USB device descriptor and the first USB configuration descriptor from the device and stores them. It also creates a framework USB interface object for each interface in the device's first configuration. To determine the number of interfaces that the configuration supports, the driver can call [WdfUsbTargetDeviceGetNumInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetnuminterfaces).

After calling **WdfUsbTargetDeviceCreate**, your driver can call additional [framework USB device object methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/).

The parent of each USB device object is the driver's framework driver object. The driver cannot change this parent, and the **ParentObject** member or the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**.

For more information about the **WdfUsbTargetDeviceCreate** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example is part of an [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function that calls **WdfUsbTargetDeviceCreate**. The example stores the USB device object's handle in driver-defined context space.

```cpp
NTSTATUS
MyEvtDevicePrepareHardware(
    IN WDFDEVICE  Device,
    IN WDFCMRESLIST  ResourceList,
    IN WDFCMRESLIST  ResourceListTranslated
    )
{
    NTSTATUS  status;
    PMY_DEVICE_CONTEXT  pMyDeviceContext;

    pMyDeviceContext = GetDeviceContext(Device);

    // If object handle is not NULL, MyEvtDevicePrepareHardware
    // was called previously and the handle is still valid.
    if (pMyDeviceContext->UsbDevice != NULL) {
        return STATUS_SUCCESS;
    }
 status = WdfUsbTargetDeviceCreate(
                                      Device,
                                      WDF_NO_OBJECT_ATTRIBUTES,
                                      &pMyDeviceContext->UsbDevice
                                      );
    if (!NT_SUCCESS(status)) {
        return status;
    }
...
}
```

## See also

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfUsbTargetDeviceGetNumInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetnuminterfaces)