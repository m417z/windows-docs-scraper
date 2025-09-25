# _WdfUsbTargetDeviceSelectConfigType enumeration

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceSelectConfigType** enumeration defines types of configuration operations for USB devices.

## Constants

### `WdfUsbTargetDeviceSelectConfigTypeInvalid:0`

For internal use only.

### `WdfUsbTargetDeviceSelectConfigTypeDeconfig:1`

Deconfigure the device. This value applies to KMDF only.

### `WdfUsbTargetDeviceSelectConfigTypeSingleInterface:2`

Configure the device to use a single, specified interface. This value applies to KMDF and UMDF.

### `WdfUsbTargetDeviceSelectConfigTypeMultiInterface:3`

Configure the device to use multiple interfaces. This value applies to KMDF and UMDF.

### `WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs:4`

Configure the device to use multiple interfaces, possibly with alternate settings. Alternate settings are described in the USB specification. This value applies to KMDF and UMDF.

### `WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor:5`

Configure the device by using configuration parameters that are contained in USB descriptors. This value applies to KMDF only.

### `WdfUsbTargetDeviceSelectConfigTypeUrb:6`

Configure the device by using configuration parameters that are contained in a driver-supplied URB structure. This value applies to KMDF only.

## Remarks

The **WdfUsbTargetDeviceSelectConfigType** enumeration is used to specify the **Type** member of the [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure. That structure is used as input to the [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig) method.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params)

[WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig)