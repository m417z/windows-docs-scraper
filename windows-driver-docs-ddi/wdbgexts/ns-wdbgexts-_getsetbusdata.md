# _GETSETBUSDATA structure

## Description

The IG_GET_BUS_DATA [Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation reads data from a system bus and the IG_SET_BUS_DATA **Ioctl** operation writes data to a system bus. When calling **Ioctl** with *IoctlType* set to IG_GET_BUS_DATA or IG_SET_BUS_DATA, *IpvData* should contain an instance of the BUSDATA structure.

## Members

### `BusDataType`

Specifies the bus data type to use. For details of allowed values, see the documentation for the BUS_DATA_TYPE enumeration in the Platform SDK.

### `BusNumber`

Specifies the system-assigned number of the bus. This is usually zero, unless the system has more than one bus of the same bus data type.

### `SlotNumber`

Specifies the logical slot number on the bus.

### `Buffer`

Specifies the buffer that contains the memory to write to the bus, or to receive the memory that is read from the bus.

The size of **Buffer** must be at least the value of **Length**.

### `Offset`

Specifies the offset in the bus data to start reading from or writing to.

### `Length`

Specifies the number of bytes to read from or write to the bus when the **Ioctl** operation is called. Upon returning, **Length** is set to the number of bytes actually read or written.

## Remarks

The parameters for the IG_GET_BUS_DATA and IG_SET_BUS_DATA [Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operations are the members of the BUSDATA structure.

This operation is only available in kernel-mode debugging.

The properties of the data in the bus depends on the system, bus, and slot.

## See also

[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine)