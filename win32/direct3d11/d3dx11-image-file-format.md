# D3DX11\_IMAGE\_FILE\_FORMAT enumeration

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

Image file formats supported by D3DX11Createxxx and D3DX11Savexxx functions.

## Constants

**D3DX11\_IFF\_BMP**

Windows bitmap (BMP) file format. Contains a header that describes the resolution of the device on which the rectangle of pixels was created, the dimensions of the rectangle, the size of the array of bits, a logical palette, and an array of bits that defines the relationship between pixels in the bitmapped image and entries in the logical palette. The file extension for this format is .bmp.

**D3DX11\_IFF\_JPG**

Joint Photographic Experts Group (JPEG) compressed file format. Specifies variable compression of 24-bit RGB color and 8-bit gray-scale Tagged Image File Format (TIFF) image document files. The file extension for this format is .jpg.

**D3DX11\_IFF\_PNG**

Portable Network Graphics (PNG) file format. A non-proprietary bitmap format using lossless compression. The file extension for this format is .png.

**D3DX11\_IFF\_DDS**

DirectDraw surface (DDS) file format. Stores textures, volume textures, and cubic environment maps, with or without mipmap levels, and with or without pixel compression. The file extension for this format is .dds.

**D3DX11\_IFF\_TIFF**

Tagged Image File Format (TIFF). The file extensions for this format are .tif and .tiff.

**D3DX11\_IFF\_GIF**

Graphics Interchange Format (GIF). The file extension for this format is .gif.

**D3DX11\_IFF\_WMP**

Windows Media Photo format (WMP). This format is also known as HD Photo and JPEG XR. The file extensions for this format are .hdp, .jxr, and .wdp.

To work properly, **D3DX11\_IFF\_WMP** requires that you initialize COM. Therefore, call [**CoInitialize**](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [**CoInitializeEx**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) in your application before you call D3DX.

**D3DX11\_IFF\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

See [Types of Bitmaps (GDI+)](https://learn.microsoft.com/windows/win32/gdiplus/-gdiplus-types-of-bitmaps-about) for more information on some of these formats.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-enums)

