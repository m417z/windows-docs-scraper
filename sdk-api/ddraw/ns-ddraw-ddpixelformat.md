## Description

The **DDPIXELFORMAT** structure describes the pixel format of a DirectDrawSurface object for the [IDirectDrawSurface7::GetPixelFormat](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-getpixelformat) method.

**Note** Rather than use this structure to decode files with the DirectDraw Surface (DDS) file format (.dds), you should use an alternative structure that does not rely on Ddraw.h. For more information about alternative structures for DDS, see [DDS](https://learn.microsoft.com/windows/desktop/direct3ddds/dx-graphics-dds).

## Members

### `dwSize`

Size of the structure, in bytes. This member must be initialized before the structure is used.

### `dwFlags`

The following flags to describe optional controls for this structure.

#### DDPF_ALPHA

The pixel format describes an alpha-only surface.

#### DDPF_ALPHAPIXELS

The surface has alpha channel information in the pixel format.

#### DDPF_ALPHAPREMULT

The surface uses the premultiplied alpha format. That is, the color components in each pixel are premultiplied by the alpha component.

#### DDPF_BUMPLUMINANCE

The luminance data in the pixel format is valid, and the **dwLuminanceBitMask** member describes valid luminance bits for a luminance-only or luminance-alpha surface.

#### DDPF_BUMPDUDV

Bump-map data in the pixel format is valid. Bump-map information is in the **dwBumpBitCount**, **dwBumpDuBitMask**, **dwBumpDvBitMask**, and **dwBumpLuminanceBitMask** members.

#### DDPF_COMPRESSED

The surface accepts pixel data in the specified format and compress it during the write operation.

#### DDPF_D3DFORMAT

Indicates a DirectX 8.0 and later format capability entry in the texture format list. This flag is not exposed to applications and is defined in Ddrawi.h.

#### DDPF_FOURCC

The **dwFourCC** member is valid and contains a FOURCC code that describes a non-RGB pixel format.

#### DDPF_LUMINANCE

The pixel format describes a luminance-only or luminance-alpha surface.

#### DDPF_PALETTEINDEXED1

The surface is 1-bit color-indexed.

#### DDPF_PALETTEINDEXED2

The surface is 2-bit color-indexed.

#### DDPF_PALETTEINDEXED4

The surface is 4-bit color-indexed.

#### DDPF_PALETTEINDEXED8

The surface is 8-bit color-indexed.

#### DDPF_PALETTEINDEXEDTO8

The surface is 1-, 2-, or 4-bit color-indexed to an 8-bit palette.

#### DDPF_RGB

The RGB data in the pixel format structure is valid.

#### DDPF_RGBTOYUV

The surface accepts RGB data and translates it during the write operation to YUV data. The format of the data to be written is contained in the pixel format structure. The DDPF_RGB flag is set.

#### DDPF_STENCILBUFFER

The surface encodes stencil and depth information in each pixel of the z-buffer. This flag can be used only if the DDPF_ZBUFFER flag is also specified.

#### DDPF_YUV

The YUV data in the pixel format structure is valid.

#### DDPF_ZBUFFER

The pixel format describes a z-buffer surface.

#### DDPF_ZPIXELS

The surface contains z information in the pixels.

### `dwFourCC`

A FourCC code.

### `DUMMYUNIONNAMEN.dwRGBBitCount`

RGB bits per pixel (4, 8, 16, 24, or 32).

### `DUMMYUNIONNAMEN.dwYUVBitCount`

YUV bits per pixel (4, 8, 16, 24, or 32).

### `DUMMYUNIONNAMEN.dwZBufferBitDepth`

Z-buffer bit depth (8, 16, 24, or 32).

### `DUMMYUNIONNAMEN.dwAlphaBitDepth`

Alpha channel bit depth (1, 2, 4, or 8) for an alpha-only surface (DDPF_ALPHA). For pixel formats that contain alpha information interleaved with color data (DDPF_ALPHAPIXELS), count the bits in the **dwRGBAlphaBitMask** member to obtain the bit depth of the alpha component. For more information about how to determine alpha bit depth, see Remarks.

### `DUMMYUNIONNAMEN.dwLuminanceBitCount`

Total luminance bits per pixel. This member applies only to luminance-only and luminance-alpha surfaces.

### `DUMMYUNIONNAMEN.dwBumpBitCount`

Total bump-map bits per pixel in a bump-map surface.

### `DUMMYUNIONNAMEN.dwPrivateFormatBitCount`

Bits per pixel of private driver formats. Only valid in texture format list and if DDPF_D3DFORMAT is set.

### `DUMMYUNIONNAMEN.dwRBitMask`

Mask for red bits.

### `DUMMYUNIONNAMEN.dwYBitMask`

Mask for Y bits.

### `DUMMYUNIONNAMEN.dwStencilBitDepth`

Bit depth of the stencil buffer. This member specifies how many bits are reserved within each pixel of the z-buffer for stencil information (the total number of z-bits is equal to **dwZBufferBitDepth** minus **dwStencilBitDepth**).

### `DUMMYUNIONNAMEN.dwLuminanceBitMask`

Mask for luminance bits.

### `DUMMYUNIONNAMEN.dwBumpDuBitMask`

Mask for bump-map U-delta bits.

### `DUMMYUNIONNAMEN.dwOperations`

Flags that specify the operations that can be performed on surfaces with the DDPF_D3DFORMAT pixel format. The flags are defined in Ddrawi.h.

### `DUMMYUNIONNAMEN.dwGBitMask`

Mask for green bits.

### `DUMMYUNIONNAMEN.dwUBitMask`

Mask for U bits.

### `DUMMYUNIONNAMEN.dwZBitMask`

Mask for z bits.

### `DUMMYUNIONNAMEN.dwBumpDvBitMask`

Mask for bump-map V-delta bits.

### `DUMMYUNIONNAMEN.MultiSampleCaps`

A structure that contains the following two members. This structure is used to specify surfaces that can be used when performing multisample rendering. Each bit in the 16-bit masks indicates support of multisampling with a specific number of samples. For example, bit 0 indicates support of multisampling with only a single sample, bit 1 indicates the support of multisampling with two samples, and so on. The driver can indicate more than one supported level by combining the bits by using a bitwise OR.

### `DUMMYUNIONNAMEN.MultiSampleCaps.wFlipMSTypes`

A 16-bit mask for full-screen (flip) mode multisampling.

### `DUMMYUNIONNAMEN.MultiSampleCaps.wBltMSTypes`

A 16-bit mask for windowed (bit-block transfer) mode multisampling.

### `DUMMYUNIONNAMEN.dwBBitMask`

Mask for blue bits.

### `DUMMYUNIONNAMEN.dwVBitMask`

Mask for V bits.

### `DUMMYUNIONNAMEN.dwStencilBitMask`

Mask for stencil bits within each z-buffer pixel.

### `DUMMYUNIONNAMEN.dwBumpLuminanceBitMask`

Mask for luminance in a bump-map pixel.

### `DUMMYUNIONNAMEN.dwRGBAlphaBitMask`

RGB mask for the alpha channel.

### `DUMMYUNIONNAMEN.dwYUVAlphaBitMask`

YUV mask for the alpha channel.

### `DUMMYUNIONNAMEN.dwLuminanceAlphaBitMask`

Luminance mask for the alpha channel.

### `DUMMYUNIONNAMEN.dwRGBZBitMask`

RGB mask for the z channel.

### `DUMMYUNIONNAMEN.dwYUVZBitMask`

YUV mask for the z channel.

## Remarks

The **dwAlphaBitDepth** member reflects the bit depth of an alpha-only pixel format (DDPF_ALPHA). For pixel formats that include the alpha component with color components (DDPF_ALPHAPIXELS), the alpha bit depth is obtained by counting the bits in the various mask members. The following code example returns the number of bits set in a given bitmask.

```cpp
WORD GetNumberOfBits( DWORD dwMask )
{
    WORD wBits = 0;
    while( dwMask )
    {
        dwMask = dwMask & ( dwMask - 1 );
        wBits++;
    }
    return wBits;
}
```

The unions in **DDPIXELFORMAT** have been updated to work with compilers that do not support nameless unions. If your compiler does not support nameless unions, define the NONAMELESSUNION token before including the Ddraw.h header file.