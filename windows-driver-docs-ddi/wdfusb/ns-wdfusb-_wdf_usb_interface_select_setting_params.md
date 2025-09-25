# _WDF_USB_INTERFACE_SELECT_SETTING_PARAMS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS** structure contains selection information for a USB interface.

## Members

### `Size`

The size, in bytes, of this structure.

### `Type`

A [WdfUsbTargetDeviceSelectSettingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdfusbtargetdeviceselectsettingtype)-typed value that identifies a technique for specifying a device interface.

### `Types`

### `Types.Descriptor`

### `Types.Descriptor.InterfaceDescriptor`

If the **Type** member is **WdfUsbInterfaceSelectSettingTypeDescriptor**, this member contains a pointer to a [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure that identifies a device interface.

### `Types.Interface`

### `Types.Interface.SettingIndex`

If the **Type** member is **WdfUsbInterfaceSelectSettingTypeSetting**, this member contains an index value that identifies an alternate setting for the interface. (The interface is identified by an interface object handle that the driver passes to [WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting).)

### `Types.Urb`

### `Types.Urb.Urb`

If the **Type** member is **WdfUsbInterfaceSelectSettingTypeUrb**, this member contains a pointer to a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure that describes a device interface. The URB structure's **Function** member must be URB_FUNCTION_SELECT_INTERFACE, and other members must be initialized as appropriate for the interface.

## Remarks

The **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS** structure is used as input to the [WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting) method.

To initialize a **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS** structure, your driver must call one of the following functions:

* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_descriptor)
* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_setting)
* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_urb)

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting)

[WdfUsbTargetDeviceSelectSettingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdfusbtargetdeviceselectsettingtype)