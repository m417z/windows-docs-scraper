# DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS structure

## Description

The DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS structure contains gamma capabilities.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) from which the driver retrieves gamma capabilities. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `pGammaCapabilities` [in/out]

A pointer to a [DXGI_GAMMA_CONTROL_CAPABILIITES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgitype/ns-dxgitype-dxgi_gamma_control_capabilities) structure that describes gamma capabilities.

## See also

[DXGI_GAMMA_CONTROL_CAPABILIITES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgitype/ns-dxgitype-dxgi_gamma_control_capabilities)

[GetGammaCapsDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)