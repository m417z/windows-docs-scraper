## Description

The DDSURFACEDESC structure contains a description of a surface to be created by the driver.

## Members

### `dwSize`

Specifies the size in bytes of this DDSURFACEDESC structure. This member must be initialized before the structure is used.

### `dwFlags`

Specifies a set of flags that determine what members of the DDSURFACEDESC structure contain valid data. This member can be one or more of the following flags:

| Flag | Meaning |
| --- | --- |
| DDSD_ALL | All input members contain valid data. |
| DDSD_ALPHABITDEPTH | The **dwAlphaBitDepth** member is valid. |
| DDSD_BACKBUFFERCOUNT | The **dwBackBufferCount** member is valid. |
| DDSD_CAPS | The **ddsCaps** member is valid. |
| DDSD_CKDESTBLT | The **ddckCKDestBlt** member is valid. |
| DDSD_CKDESTOVERLAY | The **ddckCKDestOverlay** member is valid. |
| DDSD_CKSRCBLT | The **ddckCKSrcBlt** member is valid. |
| DDSD_CKSRCOVERLAY | The **ddckCKSrcOverlay** member is valid. |
| DDSD_HEIGHT | The **dwHeight** member is valid. |
| DDSD_LINEARSIZE | The **dwLinearSize** member is valid. |
| DDSD_MIPMAPCOUNT | The **dwMipMapCount** member is valid. |
| DDSD_PITCH | The **lPitch** member is valid. |
| DDSD_PIXELFORMAT | The **ddpfPixelFormat** member is valid. |
| DDSD_REFRESHRATE | The **dwRefreshRate** member is valid. |
| DDSD_WIDTH | The **dwWidth** member is valid. |
| DDSD_ZBUFFERBITDEPTH | The **dwZBufferBitDepth** member is valid. |

### `dwHeight`

Specifies the height of surface, in pixels.

### `dwWidth`

Specifies the width of the surface, in pixels.

### `DUMMYUNIONNAMEN`

N/A

### `DUMMYUNIONNAMEN.lPitch`

Specifies the number of bytes between the beginnings of two adjacent scan lines; that is, the number of bytes to add to the beginning address of one scan line to reach the beginning address of the next scan line below it. The driver's [DdCreateSurface](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurface) callback must return this value.

### `DUMMYUNIONNAMEN.dwLinearSize`

Specifies the size in bytes of a formless, late-allocated, optimized surface.

### `dwBackBufferCount`

Specifies the number of back buffers associated with the surface.

### `DUMMYUNIONNAMEN.dwMipMapCount`

Specifies the number of mipmap levels.

### `DUMMYUNIONNAMEN.dwZBufferBitDepth`

Specifies the depth of z-buffer in bits per pixel.

### `DUMMYUNIONNAMEN.dwRefreshRate`

Specifies the refresh rate in hertz of the monitor (used when the display mode is described).

### `dwAlphaBitDepth`

Specifies the depth of the alpha buffer in bits per pixel.

### `dwReserved`

Reserved, and should be set to zero.

### `lpSurface`

Specifies the address of the associated surface memory.

### `ddckCKDestOverlay`

Specifies the color key for destination overlay use.

### `ddckCKDestBlt`

Specifies the color key for destination blt use.

### `ddckCKSrcOverlay`

Specifies the color key for source overlay use.

### `ddckCKSrcBlt`

Specifies the color key for source blt use.

### `ddpfPixelFormat`

Specifies a [DDPIXELFORMAT](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddpixelformat) structure that describes the pixel format of the surface.

### `ddsCaps`

Specifies a [DDSCAPS](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddscaps) structure that contains the Microsoft DirectDrawMicrosoft surface capabilities.

## Remarks

The relevant members differ for each potential type of surface. This structure is typically created and initialized by an application.

## See also

* [DdCreateSurface](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurface)
* [DDPIXELFORMAT](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddpixelformat)
* [DDSCAPS](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddscaps)