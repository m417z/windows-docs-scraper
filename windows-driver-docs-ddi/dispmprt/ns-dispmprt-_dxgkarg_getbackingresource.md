# _DXGKARG_GETBACKINGRESOURCE structure

## Description

Arguments used to get backing resources for the virtual device MMIO (memory mapped input output) bars.

## Members

### `VirtualFunctionIndex`

The particular Virtual function to query security.

### `ResourceIndex`

The resource index.

### `Resource`

The return resource descriptor, containing the host base address and resource length.

### `pMdl`

Pointer to an MDL (memory descriptor list).

Alternative to returning a Resource, the driver can return an already created MDL to use as a backing resource. Any MDL returned must point to contiguous physical RAM or MMIO space, with no offset into the first page, along with a length divisible by PAGE_SIZE.

## Remarks

Note that the backing resource is currently limited to MAX_FLEXIO_RESOURCES (32) ranges. These resources are then used by the scatter/gather mechanism present in the MMIO mappings to build up full guest bars. If a physical device does not use a resource at a specific Index, the device should set all return values and return STATUS_SUCCESS.

## See also