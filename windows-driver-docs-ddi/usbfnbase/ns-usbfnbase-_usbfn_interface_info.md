# _USBFN_INTERFACE_INFO structure

## Description

Describes an interface and its endpoints.

## Members

### `InterfaceNumber`

The index number of the interface.

### `Speed`

The operating bus speed indicated by [USBFN_BUS_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_bus_speed)-typed flags.

### `Size`

Specifies the total length, in bytes, of all data for the interface.

### `InterfaceDescriptorSet`

Pointer to the first element in the array of that contains the interface descriptor set.

## See also

[USBFN_BUS_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_bus_speed)