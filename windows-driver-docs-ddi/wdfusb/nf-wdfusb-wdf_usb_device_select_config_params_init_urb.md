# WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB** function initializes a [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure so that a driver can specify a configuration by using a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb).

## Parameters

### `Params` [out]

A pointer to the driver's [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure.

### `Urb` [in]

A pointer to a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure.

## Remarks

The **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB** function zeros the [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure and sets the **Size** member to the size of the structure. It also sets the **Type** member to **WdfUsbTargetDeviceSelectConfigTypeUrb** and sets the **Types.Urb.Urb** member to the *Urb* pointer.

To initialize a [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure, the driver must call one of the following functions:

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_deconfig)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_single_interface)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_multiple_interfaces)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_interfaces_descriptors)

**WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB**

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params)