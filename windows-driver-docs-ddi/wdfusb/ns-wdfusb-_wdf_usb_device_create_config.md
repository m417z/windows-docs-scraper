# _WDF_USB_DEVICE_CREATE_CONFIG structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_CREATE_CONFIG** structure contains information that the framework uses to configure a framework USB device object.

## Members

### `Size`

The size, in bytes, of this structure.

### `USBDClientContractVersion`

The contract version that the client driver supports. **USBDClientContractVersion** must be USBD_CLIENT_CONTRACT_VERSION_602.

## Remarks

The **WDF_USB_DEVICE_CREATE_CONFIG** structure is used as input to the [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters) method. To initialize a **WDF_USB_DEVICE_CREATE_CONFIG** structure, the driver must call [WDF_USB_DEVICE_CREATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_create_config_init).

## See also

[WDF_USB_DEVICE_CREATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_create_config_init)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)