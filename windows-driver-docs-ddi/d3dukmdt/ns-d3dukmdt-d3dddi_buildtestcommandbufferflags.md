## Description

The **D3DDDI_BUILDTESTCOMMANDBUFFERFLAGS** structure specifies flags for [**DXGKDDI_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildtestcommandbuffer) to use when building a command buffer for kernel-mode testing.

## Members

### `HardwareQueue`

Indicates the type of context handle in [**DXGKARG_BUILDTESTCOMMANDBUFFER::hContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_buildtestcommandbuffer). When **HardwareQueue** is 1, the context handle is a hardware queue handle. When **HardwareQueue** is 0, the context handle is a KMD context handle.

### `Reserved`

Reserved for future use.

### `Value`

Can be used to access the flags as a single value.

## Remarks

For more information, see [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## See also

[**DXGKARG_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_buildtestcommandbuffer)

[**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)

[**DxgkDdiCreatehwqueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue)

[**pfnBuildTestCommandBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_buildtestcommandbuffer)