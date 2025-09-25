# _DXGKDDI_GPU_PARTITION_INTERFACE structure

## Description

Used to query how a GPU can be partitioned for use in Virtual Machines and create or destroy a virtual GPU.

A miniport driver must support all functions in this group.

## Members

### `Size` [in]

Size of a virtual GPU.

### `Version` [in]

Version.

### `Context` [out]

The context.

### `InterfaceReference` [out]

### `InterfaceDereference` [out]

### `DxgkDdiGetGpuPartitionInfo` [out]

### `DxgkDdiSetGpuPartitionCount` [out]

### `DxgkDdiGetGpuEngines` [out]

### `DxgkDdiGetVirtualGpuProfile` [out]

### `DxgkDdiCreateVirtualGpu` [out]

### `DxgkDdiGetVirtualGpuInfo` [out]

### `DxgkDdiSetVirtualGpuResources` [out]

### `DxgkDdiDestroyVirtualGpu` [out]

### `DxgkDdiSuspendVirtualGpu` [out]

### `DxgkDdiResumeVirtualGpu` [out]

### `DxgkDdiVirtualGpuDriverEscape` [out]

### `DxgkDdiSetVirtualGpuVmBus` [out]

## Remarks

## See also