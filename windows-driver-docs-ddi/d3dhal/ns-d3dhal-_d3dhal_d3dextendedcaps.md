# _D3DHAL_D3DEXTENDEDCAPS structure

## Description

D3DHAL_D3DEXTENDEDCAPS describes additional 3D capabilities of the driver.

## Members

### `dwSize`

Specifies the size in bytes of this D3DHAL_D3DEXTENDEDCAPS structure.

### `dwMinTextureWidth`

Specify the minimum texture width, in pixels, supported by the driver or device. This member is typically a power of 2. These members are provided as hints to the application, and it is the application's responsibility to adjust texture sizes when necessary.

### `dwMaxTextureWidth`

Specify the maximum texture width, in pixels, supported by the driver or device. This member is typically a power of 2. These members are provided as hints to the application, and it is the application's responsibility to adjust texture sizes when necessary.

### `dwMinTextureHeight`

Specify the minimum texture height, in pixels, supported by the driver. This member is typically a power of 2.

### `dwMaxTextureHeight`

Specify the maximum texture height, in pixels, supported by the driver. This member is typically a power of 2.

### `dwMinStippleWidth`

Specify the minimum stipple width, in pixels, supported by the driver.

### `dwMaxStippleWidth`

Specify the maximum stipple width, in pixels, supported by the driver.

### `dwMinStippleHeight`

Specify the minimum stipple height, in pixels, supported by the driver.

### `dwMaxStippleHeight`

Specify the maximum stipple height, in pixels, supported by the driver.

### `dwMaxTextureRepeat`

Specifies the full range of integer (subfractional) bits of the postnormalized texture indexes. If the D3DDEVCAPS_TEXREPEATNOTSCALEDBYSIZE bit is set, then the number of times a texture can be wrapped is specified by this member. If the D3DDEVCAPS_TEXREPEATNOTSCALEDBYSIZE bit is not set, then the number of time a texture can be wrapped is given by the expression: **dwMaxTextureRepeat** * (*texture size*).

### `dwMaxTextureAspectRatio`

Specifies the maximum texture aspect ratio supported by the hardware. This member is typically a power of 2. This maximum aspect ratio is provided as a measure of the texture's height in pixels divided by its width in pixels, or its width divided by height, whichever produces the greater result. For example, a texture that is 8192 pixels wide by 1 pixel high or 1 pixel wide by 8192 high is invalid with a display device that only supports a maximum aspect ratio of 4092. If the hardware is not limited in aspect ratio, **dwMaxTextureAspectRatio** is the larger of **dwMaxTextureWidth** and **dwMaxTextureHeight**.

### `dwMaxAnisotropy`

Specifies the maximum valid value for the D3DRENDERSTATE_ANISOTROPY render state. If the driver's hardware does not support anisotropic filtering, the driver should set this member to 1. Setting this member to 0 represents an invalid value.

### `dvGuardBandLeft`

### `dvGuardBandTop`

### `dvGuardBandRight`

### `dvGuardBandBottom`

Specify the screen-space coordinates, in pixels, of the guard-band clip region. The upper-left corner of this rectangle has coordinates (**dvGuardBandLeft**, **dvGuardBandTop**). The lower-left corner has coordinates (**dvGuardBandRight**, **dvGuardBandBottom**). Coordinates inside this rectangle but outside the viewport rectangle are automatically clipped.

### `dvExtentsAdjust`

Specifies the number of pixels required to adjust the extents rectangle outward to accommodate antialiasing kernels.

### `dwStencilCaps`

Specifies the stencil buffer operations supported by the driver or device. For further descriptions of the stencil buffer operations shown in the following table, see D3DSTENCILOP in the DirectX SDK documentation. Stencil operations are assumed to be valid for all three stencil buffer operation render states (D3DRENDERSTATE_STENCILFAIL, D3DRENDERSTATE_STENCILPASS, and D3DRENDERSTATE_STENCILZFAIL). This member can be a bitwise OR of any of the following values:

|Value|Stencil Buffer Operation|
|--- |--- |
|D3DSTENCILCAPS_DECR|The D3DSTENCILOP_DECR operation is supported.|
|D3DSTENCILCAPS_DECRSAT|The D3DSTENCILOP_DECRSAT operation is supported.|
|D3DSTENCILCAPS_INCR|The D3DSTENCILOP_INCR operation is supported.|
|D3DSTENCILCAPS_INCRSAT|The D3DSTENCILOP_INCRSAT operation is supported.|
|D3DSTENCILCAPS_INVERT|The D3DSTENCILOP_INVERT operation is supported.|
|D3DSTENCILCAPS_KEEP|The D3DSTENCILOP_KEEP operation is supported.|
|D3DSTENCILCAPS_REPLACE|The D3DSTENCILOP_REPLACE operation is supported.|
|D3DSTENCILCAPS_ZERO|The D3DSTENCILOP_ZERO operation is supported.|

### `dwFVFCaps`

Specifies the number of texture coordinates that the driver can process. This value can be an integer in the range 0 through 8, where 0 indicates that the driver does not support texturing, 1 indicates that the driver can process only one set of texture coordinates, 2 indicates that the driver can process two sets of texture coordinates, and so on.

A driver must be able to parse all texture coordinates present in the vertex data regardless of the number of texture coordinates that the driver actually uses. The driver should use the index provided with the D3DTSS_TEXCOORDINDEX value of the D3DTEXTURESTAGESTATETYPE enumeration, described in the DirectX SDK documentation, to determine what texture coordinate set to use when rendering.

### `dwTextureOpCaps`

Specifies the texture operations supported by the device. See D3DTEXTUREOP in the DirectX SDK documentation for descriptions of the texture operations listed in the following table. This member can be a bitwise OR of the following values:

|Value|Texture Operation Supported|
|--- |--- |
|D3DTEXOPCAPS_ADD|The D3DTOP_ADD texture blending operation is supported by this device.|
|D3DTEXOPCAPS_ADDSIGNED|The D3DTOP_ADDSIGNED texture blending operation is supported by this device.|
|D3DTEXOPCAPS_ADDSIGNED2X|The D3DTOP_ADDSIGNED2X texture blending operation is supported by this device.|
|D3DTEXOPCAPS_ADDSMOOTH|The D3DTOP_ADDSMOOTH texture blending operation is supported by this device.|
|D3DTEXOPCAPS_BLENDCURRENTALPHA|The D3DTOP_BLENDCURRENTALPHA texture blending operation is supported by this device.|
|D3DTEXOPCAPS_BLENDDIFFUSEALPHA|The D3DTOP_BLENDDIFFUSEALPHA texture blending operation is supported by this device.|
|D3DTEXOPCAPS_BLENDFACTORALPHA|The D3DTOP_BLENDFACTORALPHA texture blending operation is supported by this device.|
|D3DTEXOPCAPS_BLENDTEXTUREALPHA|The D3DTOP_BLENDTEXTUREALPHA texture blending operation is supported by this device.|
|D3DTEXOPCAPS_BLENDTEXTUREALPHAPM|The D3DTOP_BLENDTEXTUREALPHAPM texture blending operation is supported by this device.|
|D3DTEXOPCAPS_BUMPENVMAP.|The D3DTOP_BUMPENVMAP texture blending operation is supported by this device.|
|D3DTEXOPCAPS_BUMPENVMAPLUMINANCE|The D3DTOP_BUMPENVMAPLUMINANCE texture blending operation is supported by this device.|
|D3DTEXOPCAPS_DISABLE|The D3DTOP_DISABLE texture blending operation is supported by this device.|
|D3DTEXOPCAPS_DOTPRODUCT3|The D3DTOP_DOTPRODUCT3 texture blending operation is supported by this device.|
|D3DTEXOPCAPS_MODULATE|The D3DTOP_MODULATE texture blending operation is supported by this device.|
|D3DTEXOPCAPS_MODULATE2X|The D3DTOP_MODULATE2X texture blending operation is supported by this device.|
|D3DTEXOPCAPS_MODULATE4X|The D3DTOP_MODULATE4X texture blending operation is supported by this device.|
|D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR|The D3DTOP_MODULATEALPHA_ADDCOLOR texture blending operation is supported by this device.|
|D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA|The D3DTOP_MODULATEALPHA_ADDCOLOR texture blending operation is supported by this device.|
|D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR|The D3DTOP_MODULATEINVALPHA_ADDCOLOR texture blending operation is supported by this device.|
|D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA|The D3DTOP_MODULATEINVCOLOR_ADDALPHA texture blending operation is supported by this device.|
|D3DTEXOPCAPS_PREMODULATE|The D3DTOP_PREMODULATE texture blending operation is supported by this device.|
|D3DTEXOPCAPS_SELECTARG1|The D3DTOP_SELECTARG1 texture blending operation is supported by this device.|
|D3DTEXOPCAPS_SELECTARG2|The D3DTOP_SELECTARG2 texture blending operation is supported by this device.|
|D3DTEXOPCAPS_SUBTRACT|The D3DTOP_SUBTRACT texture blending operation is supported by this device.|

### `wMaxTextureBlendStages`

Specifies the maximum number of texture blending stages supported by this device.

### `wMaxSimultaneousTextures`

Specifies the maximum number of textures that can be simultaneously bound to the texture blending stages for this device. That is, **wMaxSimultaneousTextures** specifies how many of the texture stages can have textures bound to them through the **lDirect3DDevice7::SetTexture** method. See the Microsoft Windows SDK documentation for more information about this method.

### `dwMaxActiveLights`

Specifies the maximum number of active lights supported by this device. This only needs to be specified in drivers that support hardware transform and lighting (and therefore specify D3DDEVCAPS_HWTRANSFORMANDLIGHT in their device caps).

### `dvMaxVertexW`

Specifies the maximum W range supported by this device. This only needs to be specified in drivers that support W buffering (and therefore specify D3DPRASTERCAPS_WBUFFER in their rasterization caps). The units for W depth values depend on the running application. For example, the application might specify depth in meters.

### `wMaxUserClipPlanes`

Specifies the maximum number of user-defined clip planes supported.

### `wMaxVertexBlendMatrices`

Specifies the number of world matrices supported for vertex blending.

### `dwVertexProcessingCaps`

Specifies the vertex processing caps that are supported by the driver. This member can be a bitwise OR of the following values:

|Value|Meaning|
|--- |--- |
|D3DVTXPCAPS_DIRECTIONALLIGHTS|Device can do directional lights.|
|D3DVTXPCAPS_LOCALVIEWER|Device can do local viewer.|
|D3DVTXPCAPS_MATERIALSOURCE7|Device can do DirectX 7.0 color-material-source operations.|
|D3DVTXPCAPS_NO_TEXGEN_NONLOCALVIEWER|Device does not support texture generation in nonlocal viewer mode.|
|D3DVTXPCAPS_POSITIONALLIGHTS|Device can do positional lights (includes point and spot).|
|D3DVTXPCAPS_TEXGEN|Device can do texgen.|
|D3DVTXPCAPS_TEXGEN_SPHEREMAP|Device supports D3DTSS_TCI_SPHEREMAP.|
|D3DVTXPCAPS_TWEENING|Device can do vertex tweening.|

### `dwReserved1`

Reserved for system use.

### `dwReserved2`

Reserved for system use.

### `dwReserved3`

Reserved for system use.

### `dwReserved4`

Reserved for system use.

## Remarks

The driver allocates and zero-initializes this structure and sets appropriate values in the members it supports. The driver's [DdGetDriverInfo](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function returns a pointer to this structure when that function is called with the GUID_D3DExtendedCaps GUID.

When the driver fills in this structure, it can set values for execute buffer capabilities even when the interface being used to retrieve the capabilities (such as **lDirect3DDevice3**) does not support execute buffers.

## See also

[DdGetDriverInfo](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)