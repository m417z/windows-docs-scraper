# _USBFN_ATTACH_ACTION enumeration

## Description

Defines the actions that the Universal Serial Bus (USB) function stack takes when a device is attached to a USB port.

## Constants

### `UsbfnPortDetected`

The USB function stack uses the returned port type to determine charging current and notify the Charging Aggregation Driver (CAD) of the power source change. If the detected port type is **UsbFnStandardDownstreamPort** or **UsbfnChargingDownstreamPort**, the USB function stack will attempt to connect to the host (see [USBFN_PORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_port_type) for more information).

### `UsbfnPortDetectedNoCad`

The USB function stack does not notify the CAD of the power source change. If the detected port type is **UsbFnStandardDownstreamPort** or **UsbfnChargingDownstreamPort**, the USB function stack attempts to connect to the host (see [USBFN_PORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_port_type) for more information).

### `UsbfnProceedWithAttach`

The USB function stack continues with the legacy software-based detection that exists in the client drivers, and issues the CAD notifications about power source notifications.

### `UsbfnIgnoreAttach`

The USB function stack discontinues further port detection operations and does not notify CAD of a power source update.

### `UsbfnDetectProprietaryCharger`

The USB function stack calls the [UFX_PROPRIETARY_CHARGER_DETECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxproprietarycharger/nc-ufxproprietarycharger-ufx_proprietary_charger_detect) event callback function implemented by the USB lower filter driver, to perform proprietary charger detection.

### `UsbfnHwBasedChargerDetection`

## See also

[USBFN_GET_ATTACH_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnattach/nc-usbfnattach-usbfn_get_attach_action)