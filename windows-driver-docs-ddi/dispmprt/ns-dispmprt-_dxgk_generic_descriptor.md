# _DXGK_GENERIC_DESCRIPTOR structure

## Description

The DXGK_GENERIC_DESCRIPTOR structure contains descriptive information about a child device of the display adapter.

## Members

### `HardwareId`

A single wide-character string, terminated by two wide NULL characters, that holds the hardware ID of the child device.

### `InstanceId`

A single wide-character string, terminated by two wide NULL characters, that holds the instance ID of the child device.

### `CompatibleId`

A sequence of wide-character strings, each of which is terminated by a single wide NULL character. The last string in the sequence is terminated by two wide NULL characters.

### `DeviceText`

A single wide-character string, terminated by two wide NULL characters, that holds the device text of the child device.

## Remarks

The display adapter has two types of child devices: **TypeVideoOutput** and **TypeOther**. For child devices of type **TypeOther**, the display port driver passes a DXGK_GENERIC_DESCRIPTOR structure to the display miniport driver's [DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor) function. *DxgkDdiQueryDeviceDescriptor* must fill in the members of the structure.

## See also

[DXGK_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_device_descriptor)