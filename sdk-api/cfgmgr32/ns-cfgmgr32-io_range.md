# IO_RANGE structure

## Description

The IO_RANGE structure specifies a resource requirements list that describes I/O port usage for a device instance. For more information about resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `IOR_Align`

Mask used to specify the port address boundary on which the first allocated I/O port address must be aligned.

### `IOR_nPorts`

The number of I/O port addresses required by the device.

### `IOR_Min`

The lowest-numbered of a range of contiguous I/O port addresses that can be allocated to the device.

### `IOR_Max`

The highest-numbered of a range of contiguous I/O port addresses that can be allocated to the device.

### `IOR_RangeFlags`

One bit flag from [IO_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_des) structure. For more information, see the following **Remarks** section.

### `IOR_Alias`

One of the bit flags described in the following table.

| Flag | Definition |
| --- | --- |
| IO_ALIAS_10_BIT_DECODE | The device decodes 10 bits of the port address. |
| IO_ALIAS_12_BIT_DECODE | The device decodes 12 bits of the port address. |
| IO_ALIAS_16_BIT_DECODE | The device decodes 16 bits of the port address. |
| IO_ALIAS_POSITIVE_DECODE | The device uses "positive decode" instead of "subtractive decode." |

For more information, see the following **Remarks** section.

## Remarks

The flags specified for **IOR_Alias** have the same interpretation as the address decoding flags specified for **IOD_DesFlags**. (However, the two sets of flags are not equivalent in assigned values and cannot be used interchangeably.) A resource requirements list can be specified using either set of flags, but using decode flags in **IOD_DesFlags** is recommended. If address decoding flags are specified using *both***IOD_DesFlags** and **IOR_Alias**, contents of the latter overrides the former.

## See also

[IO_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_des)