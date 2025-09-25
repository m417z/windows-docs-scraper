# WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR** function initializes a [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure so that a driver can select a USB interface by specifying an interface descriptor.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure.

### `Interface` [in]

A pointer to a [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure.

## Remarks

The **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR** function zeros the [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure and sets its **Size** member to the size of the structure. It also sets the **Type** member to **WdfUsbInterfaceSelectSettingTypeDescriptor** and sets the **Types.Descriptor.InterfaceDescriptor** member to the value of the *Interface* pointer.

To initialize a [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure, your driver must call one of the following functions:

* **WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR**
* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_setting)
* [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_urb)

#### Examples

The following code example initializes a [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure and then uses the structure as input to [WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting).

```cpp
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS  selectSettingParams;
USB_INTERFACE_DESCRIPTOR  interfaceDescriptor;
NTSTATUS  Status;

//
// Initialize the USB_INTERFACE_DESCRIPTOR structure here.
//
...

//
// Initialize the WDF_USB_INTERFACE_SELECT_SETTING_PARAMS
// structure and call WdfUsbInterfaceSelectSetting.
//
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR(
                                      &selectSettingParams,
                                      &interfaceDescriptor
                                      );

Status = WdfUsbInterfaceSelectSetting(
                                      UsbInterface,
                                      WDF_NO_OBJECT_ATTRIBUTES,
                                      &selectSettingParams
                                      );
```

## See also

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_setting)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_urb)