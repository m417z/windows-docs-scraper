# WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES** function initializes a [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure so that a driver can configure a device to use multiple interfaces.

## Parameters

### `Params` [in, out]

A pointer to a driver-allocated [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure.

### `NumberInterfaces` [in, optional]

The number of elements in the *SettingPairs* array. If *SettingPairs* is not **NULL**, this parameter must be greater than zero.

### `SettingPairs` [in, optional]

An array of [WDF_USB_INTERFACE_SETTING_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_setting_pair) structures. This parameter is optional and can be **NULL**.

## Remarks

Your driver can use the **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES** function to select a configuration if the device interfaces are specified by handles to USB interface objects.

Your driver can use this function if your device has one or more USB interfaces.

The **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES** function zeros the [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure and sets the **Size** member to the size of the structure.

If either *numInterfaces* or *SettingPairs* is **NULL**, **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES** sets the **Type** member to **WdfUsbTargetDeviceSelectConfigTypeMultiInterface**. In this case, the framework determines the number of interfaces you have and enables alternate setting zero on each. Use this setting if you would like to default to alternate setting zero on all interfaces.

If the *numInterfaces* parameter and the *SettingPairs* parameter are both not **NULL**, this function sets the **Type** member of the [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure to **WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs**. In this case, you can specify an alternate setting on any of the interfaces.

To initialize a [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure, the driver must call one of the following functions:

* [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_deconfig)
* [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_single_interface)
* **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES**
* [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_interfaces_descriptors)
* [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_urb)

#### Examples

The following code example calls either [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_single_interface) or **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES**, based on the number of interfaces that the device configuration supports. Then, the example calls [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig) to select a configuration.

```cpp
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS params;
PWDF_USB_INTERFACE_SETTING_PAIR settingPairs;
UCHAR numInterfaces;

numInterfaces = WdfUsbTargetDeviceGetNumInterfaces(UsbDevice);

if (numInterfaces == 1){
    WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE(&params);
}
else {
    settingPairs = ExAllocatePoolWithTag(
                        PagedPool,
                        sizeof(WDF_USB_INTERFACE_SETTING_PAIR) * numInterfaces,
                        MEM_TAG
                        );
    if (settingPairs == NULL){
        return STATUS_INSUFFICIENT_RESOURCES;
    }

 //
 // Call driver-defined routine to populate the
    // WDF_USB_INTERFACE_SETTING_PAIR structures
 // that ExAllocatePoolWithTag allocated.
 //
    InitSettingPairs(
                     UsbDevice,
                     settingPairs,
                     numInterfaces
                     );

    WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES(
                    &params,
                    numInterfaces,
                    settingPairs
                    );
}
status = WdfUsbTargetDeviceSelectConfig(
                                        UsbDevice,
                                        NULL,
                                        &params
                                        );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_deconfig)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_interfaces_descriptors)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_multiple_interfaces)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_single_interface)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_urb)

[WDF_USB_INTERFACE_SETTING_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_setting_pair)