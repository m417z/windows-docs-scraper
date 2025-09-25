# _MEMORY_REGION structure

## Description

The MEMORY_REGION structure describes a region of physically contiguous memory.

## Members

### `VirtualBase`

The beginning virtual address of the memory region.

### `PhysicalBase`

The beginning physical address of the memory region.

### `Length`

The size, in bytes, of the memory region.

## Remarks

The **DumpRegion** member of the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure holds a MEMORY_REGION structure that describes a region of physically contiguous memory that a miniport driver can use during a crash dump.

## See also

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)