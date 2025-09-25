# WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG** function initializes a [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure so that a driver can deconfigure a USB device.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure.

## Remarks

The **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG** function zeros the [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure and sets the **Size** member to the size of the structure. It also sets the **Type** member to **WdfUsbTargetDeviceSelectConfigTypeDeconfig**.

To initialize a [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure, the driver must call one of the following functions:

* **WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG**
* [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_single_interface)
* [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_multiple_interfaces)
* [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_interfaces_descriptors)
* [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_urb)

#### Examples

The following code example initializes a [WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params) structure and then calls [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig) to deconfigure a device.

```cpp
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS configParams;
NTSTATUS status;

WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG(&configParams);
Status = WdfUsbTargetDeviceSelectConfig(
                                        UsbDevice,
                                        WDF_NO_OBJECT_ATTRIBUTES,
                                        &configParams
                                        );
```

## See also

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_select_config_params)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_deconfig)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_interfaces_descriptors)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_multiple_interfaces)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_single_interface)

[WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_select_config_params_init_urb)