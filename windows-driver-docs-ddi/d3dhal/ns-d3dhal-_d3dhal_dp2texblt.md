# _D3DHAL_DP2TEXBLT structure

## Description

The D3DHAL_DP2TEXBLT structure is used for texture blts when [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) responds to the D3DDP2OP_TEXBLT command token.

## Members

### `dwDDDestSurface`

Specifies the handle to the destination texture.

### `dwDDSrcSurface`

Specifies the handle to the source texture.

### `pDest`

Specifies the destination point where the blt should be performed, that is, the point in the destination surface (**dwDDDestSurface**) to begin the blt. These *x* and *y* members of the POINT structure are specified in screen coordinates.

### `rSrc`

Specifies the rectangle to be blitted in the source texture, that is, the source rectangle in the source surface (**dwDDSrcSurface**) to blt from.

### `dwFlags`

Reserved for system use.

## Remarks

The [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurfaceex) callback creates the small integer handles to the textures that can be used as source and destination textures for texture blts.

The D3DHAL_DP2TEXBLT structure is used with a D3DDP2OP_TEXBLT command stream token to inform the drivers to perform a blt operation from a source texture to a destination texture. A texture can also be cubic environment map. The driver should copy a rectangle specified by **rSrc** in the source texture to the location specified by **pDest** in the destination texture. The destination and source textures are identified by handles that the driver was notified with during texture creation time. If the driver is capable of managing textures, then it is possible that the destination handle is 0. This indicates to the driver that it should preload the texture into video memory (or wherever the hardware efficiently textures from). In this case, the driver can ignore **rSrc** and **pDest**.

Note that for MIP mapped textures, only one D3DDP2OP_TEXBLT instruction is inserted into the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) command stream. In this case, the driver is expected to blt all the MIP map levels present in the texture. The regions to be copied in MIP map sublevels can be obtained by dividing **rSrc** and**pDest** by 2 at each level.

It is possible that the source and destination textures may contain different numbers of MIP map levels. In this case, the driver is expected to blt the common levels. For example, if a 256x256 source texture has 8 MIP map levels, and if the destination is a 64x64 texture with 6 levels, then the driver should blt the 6 corresponding levels from the source. The driver can expect the dimensions of the top MIP level of the destination texture to always be less than or equal to the dimensions of the top MIP level of the source texture.

Note that the source and destination handles always refer to the top level surfaces and never to any MIP map sublevel. Due to an error in the application, it is possible that the destination texture contains extra MIP map levels. For example, a source 256x256 texture may contain five levels, but the destination 256x256 texture may contain eight. The driver is expected to safely handle this case, but it is not expected to produce correct results. Due to legacy application compatibility issues, Direct3D does not prevent such source/destination texture pairs from being passed on to the driver.

The driver can expect the pixel formats of the source and destination textures to be identical and, in general, the specified blt is safe to perform. Other than the single case mentioned above, the driver should not expect to be presented with any situation that makes it impossible to perform a blt.

If the driver wants to perform asynchronous blts from system memory to video memory, then it should implement the DirectDraw HAL call **GetSysmemBltStatus**, otherwise, inconsistencies may arise.

With TexBlt it is not necessary for the driver to perform any synchronization because TexBlts are always issued in the proper order along with rendering commands. Before this, it was necessary for the driver to correctly handle the case when a DirectDraw blt modified any texture that was referenced by rendering commands in any Direct3D context. When multiple contexts are present, Direct3D does not issue TexBlts. This means that the driver writer can omit synchronization code in the TexBlt code path (but still needs synchronizing for blts).

**Sample**

The following pseudocode shows how a subrectangle should be computed for consecutive MIP levels, to go to MIP level i + 1 from MIP level i:

```cpp
rect.left >>= 1;
rect.top >>= 1;
DWORD right = (rect.right + 1) >> 1;
DWORD bottom = (rect.bottom + 1) >> 1;
rect.right = ((right - rect.left) < 1) ?
    (rect.left + 1) : (right);
rect.bottom = ((bottom - rect.top ) < 1) ?
    (rect.top + 1) : (bottom);
```

## See also

D3DDP2OP_TEXBLT

[D3dCreateSurfaceEx](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurfaceex)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)