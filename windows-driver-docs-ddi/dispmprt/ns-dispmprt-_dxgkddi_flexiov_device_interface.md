# _DXGKDDI_FLEXIOV_DEVICE_INTERFACE structure

## Description

Describes the Flexible IOV (input/output virtualization) kernel mode driver interface.

## Members

### `Size`

The size of the structure.

### `Version`

Interface version.

### `Context`

Context to associate with the interface.

### `InterfaceReference`

Interface reference function to be called when adding references.

### `InterfaceDereference`

Interface reference function to be called when deallocating references.

### `DxgkDdiGetBackingResource`

Points to a get backing resource function.

### `DxgkDdiGetMmioRangeCount`

Points to a get memory range count function.

### `DxgkDdiGetMmioRanges`

Points to a get memory range function.

## Remarks

## See also