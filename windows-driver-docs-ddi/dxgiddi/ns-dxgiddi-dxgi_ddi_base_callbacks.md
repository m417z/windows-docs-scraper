# DXGI_DDI_BASE_CALLBACKS structure

## Description

The DXGI_DDI_BASE_CALLBACKS structure contains pointers to Microsoft Direct3D 10 runtime callback functions that the user-mode display driver can use.

## Members

### `pfnPresentCb`

A pointer to the [pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb) function.

### `pfnPresentMultiplaneOverlayCb`

A pointer to the [pfnPresentMultiPlaneOverlayCb (DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_present_multiplane_overlaycb) function. Supported starting with Windows 8.1.

### `pfnPresentMultiplaneOverlay1Cb`

A pointer to the PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAY1CB function. Supported starting with WDDM 2.1.

### `pfnSubmitPresentBltToHwQueueCb`

A pointer to the [PFNDDXGIDDI_SUBMITPRESENTBLTTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_submitpresentblttohwqueuecb) function. Supported starting with WDDM 2.4.

### `pfnSubmitPresentToHwQueueCb`

A pointer to the [PFNDDXGIDDI_SUBMITPRESENTTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_submitpresenttohwqueuecb) function. Supported starting with WDDM 2.5.

## See also

[pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb)

[pfnPresentMultiPlaneOverlayCb (DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_present_multiplane_overlaycb)

[DXGI_DDI_BASE_ARGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_args)

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)