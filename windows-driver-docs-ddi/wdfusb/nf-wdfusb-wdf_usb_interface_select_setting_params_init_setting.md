# WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING** function initializes a [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure so that a driver can select a USB interface by specifying a handle to an interface object and an alternate setting for the interface.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure.

### `SettingIndex` [in]

An index value that identifies an alternate setting for the interface. (The interface is identified by an interface object handle that the driver passes to [WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting).)

## Remarks

The **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING** function zeros the [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure and sets its **Size** member to the size of the structure. It also sets the **Type** member to **WdfUsbInterfaceSelectSettingTypeSetting** and sets the **Types.Interface.SettingIndex** member to the value that is specified by *SettingIndex*.

To initialize a [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure, your driver must call one of the following functions:

* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_descriptor)
* **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING**
* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_urb)

For a code example that uses **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING**, see [WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting).

## See also

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_descriptor)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_urb)

[WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting)