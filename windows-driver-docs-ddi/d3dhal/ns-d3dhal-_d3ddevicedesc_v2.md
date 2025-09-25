# D3DDeviceDesc_V2 structure

## Description

The **D3DDeviceDesc_V2** structure is obsolete; only [**D3DDeviceDesc_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3ddevicedesc_v1) should be used.

The **D3DDeviceDesc_V2** structure contains fields that are already reported in the [**D3DHAL_D3DEXTENDEDCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_d3dextendedcaps) structure when responding to the GUID_D3DExtendedCaps GUID in [**DdGetDriverInfo**](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo).

## Members

### `dwSize`

### `dwFlags`

### `dcmColorModel`

### `dwDevCaps`

### `dtcTransformCaps`

### `bClipping`

### `dlcLightingCaps`

### `dpcLineCaps`

### `dpcTriCaps`

### `dwDeviceRenderBitDepth`

### `dwDeviceZBufferBitDepth`

### `dwMaxBufferSize`

### `dwMaxVertexCount`

### `dwMinTextureWidth`

### `dwMinTextureHeight`

### `dwMaxTextureWidth`

### `dwMaxTextureHeight`

### `dwMinStippleWidth`

### `dwMaxStippleWidth`

### `dwMinStippleHeight`

### `dwMaxStippleHeight`