# KSPIN_PHYSICALCONNECTION structure

## Description

A structure of type KSPIN_PHYSICALCONNECTION is returned in response to a [KSPROPERTY_PIN_PHYSICALCONNECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-physicalconnection) request.

## Members

### `Size`

Specifies the size of the structure. Note that the structure contains a dynamic array.

### `Pin`

Specifies the PinId of the connected pin on the other filter. (Pin 2 of Wave is connected to Pin 1 of Topology.)

### `SymbolicLinkName`

Specifies a string containing the symbolic link name of the connected filter

## Remarks

This structure is used with port class only.

## See also

[KSPROPERTY_PIN_PHYSICALCONNECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-physicalconnection)