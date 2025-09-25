# _HIDD_ATTRIBUTES structure

## Description

The HIDD_ATTRIBUTES structure contains vendor information about a HIDClass device.

## Members

### `Size`

Specifies the size, in bytes, of a HIDD_ATTRIBUTES structure.

### `VendorID`

Specifies a HID device's vendor ID.

### `ProductID`

Specifies a HID device's product ID.

### `VersionNumber`

Specifies the manufacturer's revision number for a HIDClass device.

## Remarks

A caller of [HidD_GetAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getattributes), uses this structure to obtain a device's vendor information.

Before using a HIDD_ATTRIBUTES structure with [HIDClass support routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/), the caller must set the **Size** member.

## See also

[HidD_GetAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getattributes)