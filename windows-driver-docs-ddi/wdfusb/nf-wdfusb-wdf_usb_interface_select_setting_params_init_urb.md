# WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB** function initializes a [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure so that a driver can select a USB interface by specifying a URB.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure.

### `Urb` [in]

A pointer to a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure.

## Remarks

The **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB** function zeros the [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure and sets its **Size** member to the size of the structure. It also sets the **Type** member to **WdfUsbInterfaceSelectSettingTypeUrb** and sets the **Types.Urb.Urb** member to the value that is specified by *Urb* pointer.

To initialize a [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure, your driver must call one of the following functions:

* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_descriptor)
* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_setting)
* **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB**

#### Examples

The following code example initializes a URB structure and then uses the structure as input to [WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting).

```cpp
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS  selectSettingParams;
URB  urb;
NTSTATUS  Status;

//
// Initialize the URB structure here.
//
...

//
// Initialize the WDF_USB_INTERFACE_SELECT_SETTING_PARAMS
// structure and call WdfUsbInterfaceSelectSetting.
//
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB(
                                      &selectSettingParams,
                                      &urb
                                      );

Status = WdfUsbInterfaceSelectSetting(
                                      UsbInterface,
                                      WDF_NO_OBJECT_ATTRIBUTES,
                                      &selectSettingParams
                                      );
```

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_descriptor)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_setting)