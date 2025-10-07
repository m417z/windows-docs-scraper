# D3DXIMAGE\_FILEFORMAT enumeration

Describes the supported image file formats. See Remarks for descriptions of these formats.

## Constants

**D3DXIFF\_BMP**

Windows bitmap (BMP) file format.

**D3DXIFF\_JPG**

Joint Photographics Experts Group (JPEG) compressed file format.

**D3DXIFF\_TGA**

Truevision (Targa, or TGA) image file format.

**D3DXIFF\_PNG**

Portable Network Graphics (PNG) file format.

**D3DXIFF\_DDS**

DirectDraw surface (DDS) file format.

**D3DXIFF\_PPM**

Portable pixmap (PPM) file format.

**D3DXIFF\_DIB**

Windows device-independent bitmap (DIB) file format.

**D3DXIFF\_HDR**

High dynamic range (HDR) file format.

**D3DXIFF\_PFM**

Portable float map file format.

**D3DXIFF\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Functions that begin with D3DXLoadxxx support all of the formats listed. Functions that begin with D3DXSavexxx support all of the formats listed except the Truevision (.tga) and portable pixmap (.ppm) formats.

The following table lists the available input and output formats.

| File Extension | Description |
|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| .bmp | Windows bitmap format. Contains a header that describes the resolution of the device on which the rectangle of pixels was created, the dimensions of the rectangle, the size of the array of bits, a logical palette, and an array of bits that defines the relationship between pixels in the bitmapped image and entries in the logical palette. |
| .dds | DirectDraw Surface file format. Stores textures, volume textures, and cubic environment maps, with or without mipmap levels, and with or without pixel compression. See [DDS](https://learn.microsoft.com/windows/win32/direct3ddds/dx-graphics-dds). |
| .dib | Windows DIB. Contains an array of bits combined with structures that specify width and height of the bitmapped image, color format of the device where the image was created, and resolution of the device used to create that image. |
| .hdr | HDR format. Encodes each pixel as an RGBE 32-bit color, with 8 bits of mantissa for red, green, and blue, and a shared 8-bit exponent. Each channel is separately compressed with run-length encoding (RLE). |
| .jpg | JPEG standard. Specifies variable compression of 24-bit RGB color and 8-bit gray-scale Tagged Image File Format (TIFF) image document files. |
| .pfm | Portable float map format. A raw floating point image format, without any compression. The file header specifies image width, height, monochrome or color, and machine word order. Pixel data is stored as 32-bit floating point values, with 3 values per pixel for color, and one value per pixel for monochrome. |
| .png | PNG format. A non-proprietary bitmap format using lossless compression. |
| .ppm | Portable Pixmap format. A binary or ASCII file format for color images that includes image height and width and the maximum color component value. |
| .tga | Targa or Truevision Graphics Adapter format. Supports depths of 8, 15, 16, 24, and 32 bits, including 8-bit gray scale, and contains optional color palette data, image (x, y) origin and size data, and pixel data. |

See [Types of Bitmaps](https://learn.microsoft.com/windows/win32/gdiplus/-gdiplus-types-of-bitmaps-about) for more information on some of these formats.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

