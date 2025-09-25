# DXGKARGCB_INVALIDATEHWCONTEXT structure

## Description

The **DXGKARGCB_INVALIDATEHWCONTEXT** structure contains the arguments used in the [**DXGKCB_INVALIDATEHWCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_invalidatehwcontext) callback function, to invalidate a hardware context.

## Members

### `hAdapter` [in]

Handle to the display adapter.

### `hHwContext` [in]

The *Dxgkrnl*-assigned value for the context that was passed to [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext).

### `Flags` [in]

A [**DXGK_INVALIDATEHWCONTEXTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_invalidatehwcontextflags) structure that contains flag values associated with the context being invalidated.

## See also

[**DXGK_INVALIDATEHWCONTEXTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_invalidatehwcontextflags)

[**DXGKCB_INVALIDATEHWCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_invalidatehwcontext)

[**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)