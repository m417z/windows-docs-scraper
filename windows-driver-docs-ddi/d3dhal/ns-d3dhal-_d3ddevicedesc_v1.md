# D3DDeviceDesc_V1 structure

## Description

**D3DDeviceDesc_V1** is obsolete in DirectX 8.0 and later versions; see Remarks. This structure describes the 3D capabilities of a device.

## Members

### `dwSize`

Specifies the size in bytes of this D3DDEVICEDESC_V1 structure.

### `dwFlags`

Identifies the members of this structure that contain valid data. This member can be a bitwise OR of any of the following values:

| **Value** | **Meaning** |
|:--|:--|
| D3DDD_BCLIPPING | The bClipping member contains valid data. |
| D3DDD_COLORMODEL | The dcmColorModel member contains valid data. |
| D3DDD_DEVCAPS | The dwDevCaps member contains valid data. |
| D3DDD_DEVICERENDERBITDEPTH | The dwDeviceRenderBitDepthmember contains valid data. |
| D3DDD_DEVICEZBUFFERBITDEPTH | The dwDeviceZBufferBitDepthmember contains valid data. |
| D3DDD_LIGHTINGCAPS | The dlcLightingCaps member contains valid data. |
| D3DDD_LINECAPS | The dpcLineCaps member contains valid data. |
| D3DDD_MAXBUFFERSIZE | The dwMaxBufferSize member contains valid data. |
| D3DDD_MAXVERTEXCOUNT | The dwMaxVertexCount member contains valid data. |
| D3DDD_TRANSFORMCAPS | The dtcTransformCaps member contains valid data. |
| D3DDD_TRICAPS | The dpcTriCaps member contains valid data. |

### `dcmColorModel`

Specifies the device's color model.

### `dwDevCaps`

Identifies the capabilities of the device. This member can be a bitwise OR of any of the following values:

| **Value** | **Meaning** |
|:--|:--|
| D3DDEVCAPS_CANBLTSYSTONONLOCAL | The device supports a TexBlt from system memory to sublocal video memory. |
| D3DDEVCAPS_CANRENDERAFTERFLIP | The device can queue rendering commands after a page flip. Devices must support this capability on Windows 2000 and later, meaning that the driver would always set this flag. |
| D3DDEVCAPS_DRAWPRIMITIVES2 | The device can support [**D3dDrawPrimitives2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) . |
| D3DDEVCAPS_DRAWPRIMITIVES2EX | The device can support Extended [**D3dDrawPrimitives2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) ; i.e. a DX7-compliant driver. |
| D3DDEVCAPS_DRAWPRIMTLVERTEX | The device can draw TLVERTEX primitives. This flag is obsolete but must be set by the driver. |
| D3DDEVCAPS_EXECUTESYSTEMMEMORY | The device can use execute buffers from system memory. The driver must always set this bit. |
| D3DDEVCAPS_EXECUTEVIDEOMEMORY | The device can use execute buffers from display memory. The driver must never set this bit. |
| D3DDEVCAPS_FLOATTLVERTEX | The device accepts floating-point for posttransform vertex data. This flag is obsolete but must be set by the driver. |
| D3DDEVCAPS_HWRASTERIZATION | The device has hardware acceleration for rasterization. |
| D3DDEVCAPS_HWTRANSFORMANDLIGHT | The device can support transformation and lighting in hardware. D3DDEVCAPS_DRAWPRIMITIVES2EX must also be set. |
| D3DDEVCAPS_SEPARATETEXTUREMEMORIES | The device is texturing from separate memory pools. Setting this capability bit indicates to DirectX 8.0 and later versions of applications that they are disabled from simultaneously using multiple textures. |
| D3DDEVCAPS_SORTDECREASINGZ | The device needs data sorted for decreasing depth. |
| D3DDEVCAPS_SORTEXACT | The device needs data sorted exactly. |
| D3DDEVCAPS_SORTINCREASINGZ | The device needs data sorted for increasing depth. |
| D3DDEVCAPS_TEXTURENONLOCALVIDEOMEMORY | The device can texture from nonlocal video memory. |
| D3DDEVCAPS_TLVERTEXSYSTEMMEMORY | The device can use buffers from system memory for transformed and lit vertices. This flag is obsolete but must be set by the driver. |
| D3DDEVCAPS_TLVERTEXVIDEOMEMORY | The device can use buffers from display memory for transformed and lit vertices. This flag is obsolete and must not be set by the driver. |
| D3DDEVCAPS_TEXTURESYSTEMMEMORY | The device can retrieve textures from system memory. |
| D3DDEVCAPS_TEXTUREVIDEOMEMORY | The device can retrieve textures from device memory. |

### `dtcTransformCaps`

Specifies a D3DTRANSFORMCAPS structure that specifies the transformation capabilities of the device. The driver must set the **dwCaps** member of that structure to zero.

### `bClipping`

Set to TRUE by the driver if the device can perform 3D clipping.

### `dlcLightingCaps`

Specifies the lighting capabilities of the device. This is a [**D3DLIGHTINGCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dcaps/ns-d3dcaps-_d3dlightingcaps) structure. The driver must set the **dwCaps**, **dwLightingModel**, and **dwNumLights** members of that structure to zero.

### `dpcLineCaps`

Specifies a [**D3DPRIMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dcaps/ns-d3dcaps-_d3dprimcaps) structure that defines the drawing capabilities of the device for line primitives.

### `dpcTriCaps`

Specifies a [**D3DPRIMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dcaps/ns-d3dcaps-_d3dprimcaps) structure that defines the drawing capabilities of the device for triangle primitives.

### `dwDeviceRenderBitDepth`

Specifies the device's rendering bit-depth. This member can be a bitwise OR of the following DirectDraw bit-depth constants: DDBD_8, DDBD_16, DDBD_24, or DDBD_32.

### `dwDeviceZBufferBitDepth`

Specifies the device's z-buffer bit-depth. This member can be a bitwise OR of the following DirectDraw bit-depth constants: DDBD_8, DDBD_16, DDBD_24, or DDBD_32.

### `dwMaxBufferSize`

Must be set to zero.

### `dwMaxVertexCount`

DirectX 7 and later versions

DirectX 6

## Remarks

This structure has been replaced by D3DCAPS8 (see the DirectX 8.0 SDK documentation) for DirectX 8.0 and later runtimes, but is required for legacy runtime (DirectX 7.0 and earlier) compatibility. See [Reporting DirectX 8.0 Style Direct3D Capabilities](https://learn.microsoft.com/windows-hardware/drivers/display/reporting-directx-8-0-style-direct3d-capabilities) for details.

The driver's [**DrvGetDirectDrawInfo**](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo) function returns this information in the [**D3DHAL_GLOBALDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata) structure that the **lpD3DGlobalDriverData** member of the [**DD_HALINFO**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo) structure points to.

The Direct3D runtime constructs the application-level D3DDEVICEDESC7 structure (documented in the Microsoft Windows SDK documentation) from the information returned in the D3DDEVICEDESC_V1 structure and the extended capabilities queried through the driver's [**DdGetDriverInfo**](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function. While some of the **dwDevCaps** flags are obsolete at the driver level, the driver must set them appropriately in order for applications to work correctly.

## See also

[**D3DHAL_GLOBALDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata)

[**D3DLIGHTINGCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dcaps/ns-d3dcaps-_d3dlightingcaps)

[**D3DPRIMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dcaps/ns-d3dcaps-_d3dprimcaps)

[**D3dDrawPrimitives2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[**DD_HALINFO**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo)

[DdGetDriverInfo**](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo)