# _WDF_USB_DEVICE_INFORMATION structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_INFORMATION** structure contains version and capability information for a USB device.

## Members

### `Size`

The size, in bytes, of this structure.

### `UsbdVersionInformation`

A [USBD_VERSION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_version_information) structure that provides version information for the host controller driver (HCD) and the USB specification version that the device supports.

### `HcdPortCapabilities`

This member is reserved for system use.

### `Traits`

A set of bit flags that identify device traits. The flags are defined by the [WDF_USB_DEVICE_TRAITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_device_traits) enumeration.

## Remarks

The **WDF_USB_DEVICE_INFORMATION** structure is filled in by the [WdfUsbTargetDeviceRetrieveInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceretrieveinformation) method. Before calling **WdfUsbTargetDeviceRetrieveInformation**, the driver must call [WDF_USB_DEVICE_INFORMATION_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_information_init) to initialize the structure.

## See also

[USBD_VERSION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_version_information)

[WDF_USB_DEVICE_INFORMATION_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_device_information_init)

[WDF_USB_DEVICE_TRAITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_device_traits)

[WdfUsbTargetDeviceRetrieveInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceretrieveinformation)