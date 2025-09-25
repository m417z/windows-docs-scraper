# _UMDETW_ALLOCATION_USAGE structure

## Description

Indicates the reason for mapping from a Microsoft Direct3D memory allocation to a Microsoft DirectX graphics kernel subsystem (Dxgkrnl.sys) allocation.

## Members

### `Packed`

The allocation is packed into a larger parent allocation.

### `Renamed`

The allocation is a renamed instance of a Direct3D allocation.

### `Reserved`

Reserved for system use. Do not use in your driver.

### `DriverReserved`

The driver can use these bit fields for its own internal purposes.

### `Value`

A 32-bit value that specifies the allocation mapping.

## See also

[UMDEtwLogMapAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwlogmapallocation)