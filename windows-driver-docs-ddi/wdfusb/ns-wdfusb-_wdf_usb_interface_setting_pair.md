# _WDF_USB_INTERFACE_SETTING_PAIR structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_INTERFACE_SETTING_PAIR** structure specifies an alternate setting for a specified USB interface.

## Members

### `UsbInterface`

A handle to a framework USB interface object.

### `SettingIndex`

A device-specific index value that identifies an alternate setting for the interface. Alternate settings are described in the USB specification.

## Remarks

The **WDF_USB_INTERFACE_SETTING_PAIR** structure is used in the [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure.

## See also

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params)