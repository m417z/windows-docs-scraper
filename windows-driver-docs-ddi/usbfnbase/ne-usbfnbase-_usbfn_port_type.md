# _USBFN_PORT_TYPE enumeration

## Description

Defines the possible port types that can be returned by the client driver during port detection.

## Constants

### `UsbfnUnknownPort`

Port detection was unable to determine the port type.

### `UsbfnStandardDownstreamPort`

The upstream port has been detected as a standard downstream port (SDP) (as defined in the Battery Charging Specification, revision 1.2).

### `UsbfnChargingDownstreamPort`

The upstream port has been detected as a charging downstream port (CDP), as defined in the Battery Charging Specification, revision 1.2.

### `UsbfnDedicatedChargingPort`

The upstream port has been detected as a dedicated charging port (DCP) (as defined in the Battery Charging Specification, revision 1.2).

### `UsbfnInvalidDedicatedChargingPort`

The upstream port has been detected as a dedicated charging port that does not comply with the Battery Charging Specification, revision 1.2.

### `UsbfnProprietaryDedicatedChargingPort`

A proprietary charger was attached.

### `UsbfnPortTypeMaximum`

The maximum value of the enumeration.

## See also

[USBFN_GET_ATTACH_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnattach/nc-usbfnattach-usbfn_get_attach_action)