# DXGK_CREATECONTEXTFLAGS structure

## Description

The **DXGK_CREATECONTEXTFLAGS** structure identifies how to create contexts.

## Members

### `SystemContext`

A UINT value that specifies whether contexts that a driver's [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function creates are system contexts for the engine that the **EngineAffinity** member of the [**DXGKARG_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext) structure specifies. A system context is created for the paging engine only.

### `GdiContext`

A UINT value that specifies whether the contexts that a driver's [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function creates are GDI-specific contexts for the engine that the **EngineAffinity** member of the [**DXGKARG_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext) structure specifies.

This member is available beginning with Windows 7.

### `VirtualAddressing`

Specifies whether the contexts that a driver's [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function creates use virtual addressing.

Supported starting with Windows 10.

### `SystemProtectedContext`

Specifies whether the context being used to modify the VPR will have access to allocations outside the VPR.

Supported starting with Windows 10.

### `HwQueueSupported`

Specifies whether the context supports hardware queues.

### `TestContext`

Specifies whether the context is a test context for [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features). Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

A member in the union that **DXGK_CREATECONTEXTFLAGS** contains that can hold a 32-bit value that identifies how to create contexts.

## See also

[**DXGKARG_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext)

[**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)