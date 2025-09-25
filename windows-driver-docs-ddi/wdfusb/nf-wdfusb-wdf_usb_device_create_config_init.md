# WDF_USB_DEVICE_CREATE_CONFIG_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_CREATE_CONFIG_INIT** function
initializes a [WDF_USB_DEVICE_CREATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_create_config) structure.

## Parameters

### `Config` [out]

A pointer to a [WDF_USB_DEVICE_CREATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_create_config) structure.

### `USBDClientContractVersion` [in]

The contract version that the client driver supports. **USBDClientContractVersion** must be USBD_CLIENT_CONTRACT_VERSION_602.

## Remarks

The **WDF_USB_DEVICE_CREATE_CONFIG_INIT** function zeros the specified [WDF_USB_DEVICE_CREATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_create_config) structure and sets the **Size** member to the size of the structure. It also sets the structure's **USBDClientContractVersion** member to the specified value.

For a code example that uses **WDF_USB_DEVICE_CREATE_CONFIG_INIT**, see [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

## See also

[WDF_USB_DEVICE_CREATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_create_config)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)