# D3D11DDI_HANDLESIZE structure

## Description

The D3D11DDI_HANDLESIZE structure describes a handle.

## Members

### `HandleType` [in]

A [D3D11DDI_HANDLETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_handletype)-typed value that identifies the handle type.

### `DriverPrivateSize` [in]

The size, in bytes, of the driver-private memory space that holds the handle data.

## Remarks

The driver's [CheckDeferredContextHandleSizes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_checkdeferredcontexthandlesizes) function verifies the size of the driver-private memory space that holds the handle data of a deferred context handle and returns the size in the **DriverPrivateSize** member of the D3D11DDI_HANDLESIZE structure that the *pHandleSize* parameter points to.

## See also

[CheckDeferredContextHandleSizes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_checkdeferredcontexthandlesizes)

[D3D11DDI_HANDLETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_handletype)