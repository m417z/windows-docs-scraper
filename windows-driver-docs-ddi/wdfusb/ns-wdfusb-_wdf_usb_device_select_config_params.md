# _WDF_USB_DEVICE_SELECT_CONFIG_PARAMS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS** structure specifies USB device configuration parameters.

## Members

### `Size`

The size, in bytes, of this structure.

### `Type`

A [WdfUsbTargetDeviceSelectConfigType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdfusbtargetdeviceselectconfigtype)-typed value that either specifies the type of configuration that is being selected or indicates that the current configuration is being deconfigured.

### `Types`

### `Types.Descriptor`

### `Types.Descriptor.ConfigurationDescriptor`

If the driver sets the **Type** member to **WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor**, this member contains a driver-supplied pointer to a [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure that specifies a configuration descriptor. If this pointer is **NULL**, the framework uses the device's first configuration. For more information about selecting a USB configuration, see the Remarks section of [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig).

### `Types.Descriptor.InterfaceDescriptors`

If the driver sets **Type** to **WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor**, this member contains a driver-supplied pointer to an array of [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structures that represent the interfaces to select for the configuration.

### `Types.Descriptor.NumInterfaceDescriptors`

If the driver sets **Type** to **WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor**, this member contains the number of elements that are in the interface array that **Types.Descriptor.InterfaceDescriptors** points to.

### `Types.Urb`

### `Types.Urb.Urb`

If the driver sets **Type** to **WdfUsbTargetDeviceSelectConfigTypeUrb**, this member specifies a driver-initialized [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure that the framework uses to configure the device.

### `Types.SingleInterface`

### `Types.SingleInterface.NumberConfiguredPipes`

If the driver sets **Type** to **WdfUsbTargetDeviceSelectConfigTypeSingleInterface**, the framework provides the number of pipes that are configured for the interface.

### `Types.SingleInterface.ConfiguredUsbInterface`

If the driver sets **Type** to **WdfUsbTargetDeviceSelectConfigTypeSingleInterface**, the framework provides a handle to a USB interface object that represents the configured interface.

### `Types.MultiInterface`

### `Types.MultiInterface.NumberInterfaces`

If the driver sets **Type** to **WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs**, this member specifies the number of elements that are in the **Types.MultiInterface.Pairs** array.

### `Types.MultiInterface.Pairs`

If the driver sets **Type** to **WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs**, this member specifies a pointer to an array of [WDF_USB_INTERFACE_SETTING_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_setting_pair) structures that identify the interfaces to select.

### `Types.MultiInterface.NumberOfConfiguredInterfaces`

If the driver sets **Type** to **WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs** or **WdfUsbTargetDeviceSelectConfigTypeMultiInterface**, the framework provides the number of interfaces that are configured for the device.

## Remarks

The **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS** structure is used as input to [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig).

To initialize a **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS** structure, use one of the following functions:

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_deconfig)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_single_interface)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_multiple_interfaces)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_interfaces_descriptors)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_urb)

If the driver sets the **Type** member to **WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor**, it can change the USB device configuration. All other values use the current USB device configuration.

## See also

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[WDF_USB_INTERFACE_SETTING_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_setting_pair)

[WdfUsbTargetDeviceSelectConfigType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdfusbtargetdeviceselectconfigtype)