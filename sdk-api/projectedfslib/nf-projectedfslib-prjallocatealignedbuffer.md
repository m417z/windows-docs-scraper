# PrjAllocateAlignedBuffer function

## Description

Allocates a buffer that meets the memory alignment requirements of the virtualization instance's storage device.

## Parameters

### `namespaceVirtualizationContext` [in]

Opaque handle for the virtualization instance.

### `size` [in]

The size of the buffer required, in bytes.

## Return value

Returns NULL if the buffer could not be allocated.

## Remarks

Use [PrjFreeAlignedBuffer](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjfreealignedbuffer) to deallocate memory obtained by **PrjAllocateAlignedBuffer**.