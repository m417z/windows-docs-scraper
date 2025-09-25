# WdfUsbTargetDeviceCreateWithParameters function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceCreateWithParameters** method creates a framework USB device object for a specified framework device object and opens the USB device for I/O operations.
The method also specifies configuration information for the framework USB device object.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Config` [in]

A pointer to a [WDF_USB_DEVICE_CREATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_create_config) structure that contains configuration information for the framework USB device object.

### `Attributes` [in, optional]

A pointer to a caller-supplied [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new framework USB device object. (The structure's **ParentObject** member must be NULL.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `UsbDevice` [out]

A pointer to a location that receives a handle to the new framework USB device object.

## Return value

**WdfUsbTargetDeviceCreateWithParameters** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The *Config* parameter is not the correct size. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to create a new framework USB device object. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. See the Remarks section for more information. |
| **STATUS_UNSUCCESSFUL** | An attempt to get USB configuration information failed. |

For a list of other return values that the **WdfUsbTargetDeviceCreateWithParameters** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Windows 8 includes a new USB driver stack to support USB 3.0 devices.

Before a framework-based client driver can use the new capabilities of the USB driver stack for Windows 8, the driver must register itself with the underlying USB driver stack that is loaded by Windows for the device. To register the client driver, call **WdfUsbTargetDeviceCreateWithParameters** and specify a contract version in the [WDF_USB_DEVICE_CREATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_create_config) structure.

 If the client driver is intended to build, run, and use the improvements and the new capabilities on Windows 8, the client contract version is USBD_CLIENT_CONTRACT_VERSION_602.

Typically, drivers call **WdfUsbTargetDeviceCreateWithParameters** from within an [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. Drivers can also call **WdfUsbTargetDeviceCreateWithParameters** from within an [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

For information about how WDM USB client drivers interact with the USB 3.0 driver stack, see [Best Practices: Using URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-driver-contract-in-windows-8).

If the driver calls **WdfUsbTargetDeviceCreateWithParameters** to create a framework USB device object, the driver must create URBs only by calling [WdfUsbTargetDeviceCreateUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateurb) or [WdfUsbTargetDeviceCreateIsochUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateisochurb).

If you call this method from a UMDF driver, you must specify the **UmdfDispatcher** directive in the driver's INF file. Otherwise, this method may return **STATUS_INVALID_PARAMETER**. For more information about this directive, see [Specifying WDF Directives in INF Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-wdf-directives-in-inf-files).

#### Examples

The following code example is part of an [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function that calls **WdfUsbTargetDeviceCreateWithParameters**. The example stores the handle to the framework USB device object in driver-defined context space.

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
    WDF_USB_DEVICE_CREATE_CONFIG  Config;

    pMyDeviceContext = GetDeviceContext(Device);

    // If object handle is not NULL, MyEvtDevicePrepareHardware
    // was called previously and the handle is still valid.
    if (pMyDeviceContext->UsbDevice != NULL) {
        return STATUS_SUCCESS;
    }

    WDF_USB_DEVICE_CREATE_CONFIG_INIT(
                                      &Config,
                                      USBD_CLIENT_CONTRACT_VERSION_602
                                      );

    status = WdfUsbTargetDeviceCreateWithParameters(
                                      Device,
                                      &Config,
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

[USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle)

[WDF_USB_DEVICE_CREATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_create_config)

[WDF_USB_DEVICE_CREATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_create_config_init)

[WdfUsbTargetDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreate)