# _D3DKMDT_MONITOR_DESCRIPTOR structure

## Description

The D3DKMDT_MONITOR_DESCRIPTOR structure contains a pointer to a monitor descriptor along with information about the monitor descriptor.

## Members

### `Id`

An integer that identifies the monitor descriptor.

### `Type`

A value from the [D3DKMDT_MONITOR_DESCRIPTOR_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_descriptor_type) enumeration that indicates the descriptor type.

### `DataSize`

The size, in bytes, of the monitor descriptor.

### `pData`

A pointer to the monitor descriptor.

### `Origin`

A value of type [D3DKMDT_MONITOR_CAPABILITIES_ORIGIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_capabilities_origin) that indicates the source of the mode information for the monitor. For example, the mode information could be from a default monitor profile or it could be from an override in an INF file.

## See also

[D3DKMDT_MONITOR_CAPABILITIES_ORIGIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_capabilities_origin)

[D3DKMDT_MONITOR_DESCRIPTOR_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_descriptor_type)

[Monitor Descriptor Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)