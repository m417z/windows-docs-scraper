# WdfUsbTargetDeviceSelectConfig function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceSelectConfig** method selects a USB configuration for a device, or it deconfigures the device.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `PipeAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for new framework USB pipe objects that the framework creates for the device's interfaces. For KMDF drivers, this parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES. UMDF drivers must set this parameter to NULL.

### `Params` [in, out]

A pointer to a caller-allocated [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure that the caller and the framework use to specify configuration parameters.

## Return value

**WdfUsbTargetDeviceSelectConfig** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INFO_LENGTH_MISMATCH** | The **Size** member of the [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure that *Params* points to was incorrect. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory buffer could not be allocated. |
| **STATUS_NOT_SUPPORTED** | The framework returns this value if a UMDF driver calls [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig) with *Params*->**Type** set to any of the following:<br><br>* **WdfUsbTargetDeviceSelectConfigTypeDeconfig**<br>* **WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor**<br>* **WdfUsbTargetDeviceSelectConfigTypeUrb**<br><br>For more info, see [WdfUsbTargetDeviceSelectConfigType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdfusbtargetdeviceselectconfigtype). |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can select a device configuration by using a [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure to specify USB descriptors, a URB, or handles to framework USB interface objects.

The framework creates a framework USB pipe object for each pipe that is associated with each interface in the configuration, after deleting any pipe objects that the framework might have previously created for the configuration. The framework uses alternate setting zero for each interface, unless the driver specifies a different alternate setting.

To obtain information about an interface's pipe objects, the driver can call [WdfUsbInterfaceGetNumConfiguredPipes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetnumconfiguredpipes) and [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

For more information about the **WdfUsbTargetDeviceSelectConfig** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

**Caution**

You can use **WdfUsbTargetDeviceSelectConfig** to select only the first USB configuration listed in the descriptor list, but you can select multiple interfaces within this single configuration.

#### Examples

The following code example selects a configuration with a single, specified interface.

```cpp
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS  configParams;
NTSTATUS  status;

WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE(&configParams);

status = WdfUsbTargetDeviceSelectConfig(
                                        UsbDevice,
                                        WDF_NO_OBJECT_ATTRIBUTES,
                                        &configParams
                                        );
```
The following code example selects a configuration with multiple interfaces, using alternate setting zero on all interfaces. This example applies only to KMDF drivers.

```cpp
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS  configParams;
PWDF_USB_INTERFACE_SETTING_PAIR settingPairs;
UCHAR numInterfaces;
NTSTATUS  status;

numInterfaces = WdfUsbTargetDeviceGetNumInterfaces(UsbDevice);

settingPairs = ExAllocatePoolWithTag(
    PagedPool,
    sizeof(WDF_USB_INTERFACE_SETTING_PAIR) * numInterfaces,
    MY_DRIVER_TAG
);

if (settingPairs == NULL){
    return STATUS_INSUFFICIENT_RESOURCES;
}

for (interfaceIndex = 0; interfaceIndex < numInterfaces; interfaceIndex++) {

    settingPairs[interfaceIndex].UsbInterface =
                                    WdfUsbTargetDeviceGetInterface(
                                        UsbDevice,
                                        interfaceIndex);

    // Select alternate setting zero on all interfaces.

    settingPairs[interfaceIndex].SettingIndex = 0;
}

WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES(
    &configParams,
    numInterfaces,
    settingPairs
);

status = WdfUsbTargetDeviceSelectConfig(
    UsbDevice,
    NULL,
    &configParams
);

if (settingPairs != NULL) {
    ExFreePoolWithTag(
        settingPairs,
        MY_DRIVER_TAG
    );
    return status;
}
```

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_multiple_interfaces)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_single_interface)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)

[WdfUsbInterfaceGetNumConfiguredPipes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetnumconfiguredpipes)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)