# _DXGKARG_CREATECONTEXT structure

## Description

The DXGKARG_CREATECONTEXT structure describes parameters to create a device context.

## Members

### `hContext` [out]

A handle to the context that a display miniport driver returns from a call to its [DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function. This handle represents the context in subsequent calls to the driver's [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present), [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render), and [DxgkDdiDestroyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroycontext) functions.

### `NodeOrdinal` [in]

The node that the context is created for.

### `EngineAffinity` [in]

The engine within the node that **NodeOrdinal** specifies that the context is created for.

### `Flags` [in]

A [DXGK_CREATECONTEXTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createcontextflags) structure that identifies how to create the context.

### `pPrivateDriverData` [in]

A pointer to a block of private data that is passed from the user-mode display driver to the display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the private data that **pPrivateDriverData** points to.

### `ContextInfo` [out]

A [DXGK_CONTEXTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_contextinfo) structure that the display miniport driver populates to describe the device context.

## See also

[DXGK_CONTEXTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_contextinfo)

[DXGK_CREATECONTEXTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createcontextflags)

[DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)

[DxgkDdiDestroyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroycontext)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)