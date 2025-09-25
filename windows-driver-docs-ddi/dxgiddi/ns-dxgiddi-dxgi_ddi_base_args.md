# DXGI_DDI_BASE_ARGS structure

## Description

The **DXGI_DDI_BASE_ARGS** structure contains Microsoft DirectX Graphics Infrastructure (DXGI) basic device driver interface (DDI) device creation arguments.

## Members

### `pDXGIBaseCallbacks` [in]

A pointer to a [DXGI_DDI_BASE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_callbacks) structure that contains a table of Microsoft Direct3D runtime callback functions that the driver can use to access kernel services.

### `pDXGIDDIBaseFunctions6_1`

### `pDXGIDDIBaseFunctions6`

### `pDXGIDDIBaseFunctions5`

### `pDXGIDDIBaseFunctions4` [in/out]

A pointer to a [DXGI1_3_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_3_ddi_base_functions) structure that the user-mode display driver fills with a table of its functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver.

 Supported starting with Windows 8.1.

### `pDXGIDDIBaseFunctions3` [in/out]

A pointer to a [DXGI1_2_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions) structure that the user-mode display driver fills with a table of its functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver.

Supported starting with Windows 8.

### `pDXGIDDIBaseFunctions2` [in/out]

A pointer to a [DXGI1_1_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions) structure that the user-mode display driver fills with a table of its functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver.

 Supported starting with Windows 7.

### `pDXGIDDIBaseFunctions` [in/out]

A pointer to a [DXGI_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) structure that the user-mode display driver fills with a table of its functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[DXGI1_1_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions)

[DXGI1_2_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions)

[DXGI1_3_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_3_ddi_base_functions)

[DXGI_DDI_BASE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_callbacks)

[DXGI_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)