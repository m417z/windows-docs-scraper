# _D3DHAL_CALLBACKS structure

## Description

D3DHAL_CALLBACKS is one of several callback structures that describe the Direct3D support provided by the driver.

## Members

### `dwSize`

Specifies the size in bytes of this D3DHAL_CALLBACKS structure.

### `ContextCreate`

Points to the driver-supplied [D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb) callback. A driver must implement the callback that this member points to.

### `ContextDestroy`

Points to the driver-supplied [D3dContextDestroy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextdestroycb) callback. A driver must implement the callback that this member points to.

### `ContextDestroyAll`

Must be set to **NULL** in a Windows 2000 and later driver.

### `SceneCapture`

Must be set to **NULL** in a Windows 2000 and later driver. For DirectX 6.0, this was a pointer to the driver-supplied **D3dSceneCapture** callback. For DirectX 7.0 and later, this callback was replaced by the handling of the D3DRENDERSTATE_SCENECAPTURE render state in the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) function.

### `lpReserved10`

Must be zero.

### `lpReserved11`

Must be zero.

### `RenderState`

Points to the driver-supplied D3DHAL_RENDERSTATEDATA callback. A driver must implement the callback that this member points to.

### `RenderPrimitive`

Points to the driver-supplied D3DHAL_RENDERPRIMITIVEDATA callback. A driver must implement the callback that this member points to.

### `dwReserved`

Specifies reserved fields and must be set to zero.

### `TextureCreate`

Must be set to **NULL** in a Windows 2000 and later driver. For DirectX 6.0, this was a pointer to the driver-supplied **D3dTextureCreate** callback, or **NULL**.

### `TextureDestroy`

Must be set to **NULL** in a Windows 2000 and later driver. For DirectX 6.0, this was a pointer to the driver-supplied **D3dTextureDestroy** callback, or **NULL**.

### `TextureSwap`

Must be set to **NULL** in a Windows 2000 and later driver. For DirectX 6.0, this was a pointer to the driver-supplied **D3dTextureSwap** callback, or **NULL**.

### `TextureGetSurf`

Must be set to **NULL** in a Windows 2000 and later driver. For DirectX 6.0, this was a pointer to the driver-supplied **D3dTextureGetSurf** callback, or **NULL**.

### `lpReserved12`

Must be zero.

### `lpReserved13`

Must be zero.

### `lpReserved14`

Must be zero.

### `lpReserved15`

Must be zero.

### `lpReserved16`

Must be zero.

### `lpReserved17`

Must be zero.

### `lpReserved18`

Must be zero.

### `lpReserved19`

Must be zero.

### `lpReserved20`

Must be zero.

### `lpReserved21`

Must be zero.

### `GetState`

Points to the driver-supplied D3DHAL_GETSTATEDATA callback. A driver must implement the callback that this member points to.

### `dwReserved0`

Must be zero.

### `dwReserved1`

Must be zero.

### `dwReserved2`

Must be zero.

### `dwReserved3`

Must be zero.

### `dwReserved4`

Must be zero.

### `dwReserved5`

Must be zero.

### `dwReserved6`

Must be zero.

### `dwReserved7`

Must be zero.

### `dwReserved8`

Must be zero

### `dwReserved9`

Must be zero.

## Remarks

The driver allocates this structure and sets appropriate values in all members. The driver's [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo) function returns a pointer to this structure in the **lpD3DHALCallbacks** member of the [DD_HALINFO](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo) structure.

Texture management is now handled though opcodes that are managed in the driver's implementation of [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## See also

[D3DHAL_CALLBACKS3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_callbacks3)

[D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb)

[D3dContextDestroy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextdestroycb)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[DdGetDriverInfo](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo)