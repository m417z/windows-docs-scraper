# WDF_USB_DEVICE_INFORMATION_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_INFORMATION_INIT** function initializes a driver's [WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information) structure.

## Parameters

### `Udi` [out]

A pointer to the driver's [WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information) structure.

## Remarks

The **WDF_USB_DEVICE_INFORMATION_INIT** function zeros the [WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information) structure and sets its **Size** member to the size of the structure.

#### Examples

For a code example that uses**WDF_USB_DEVICE_INFORMATION_INIT**, see [WdfUsbTargetDeviceRetrieveInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceretrieveinformation).

## See also

[WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information)