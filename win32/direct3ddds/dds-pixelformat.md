# DDS\_PIXELFORMAT structure

Surface pixel format.

## Members

**dwSize**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Structure size; set to 32 (bytes).

**dwFlags**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Values which indicate what type of data is in the surface.

| Flag | Description | Value |
|-------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------|
| DDPF\_ALPHAPIXELS | Texture contains alpha data; **dwRGBAlphaBitMask** contains valid data. | 0x1 |
| DDPF\_ALPHA | Used in some older DDS files for alpha channel only uncompressed data (dwRGBBitCount contains the alpha channel bitcount; dwABitMask contains valid data) | 0x2 |
| DDPF\_FOURCC | **dwFourCC** contains valid data. | 0x4 |
| DDPF\_RGB | Texture contains uncompressed RGB data; **dwRGBBitCount** and the RGB masks (**dwRBitMask**, **dwGBitMask**, **dwBBitMask**) contain valid data. | 0x40 |
| DDPF\_YUV | Used in some older DDS files for YUV uncompressed data (dwRGBBitCount contains the YUV bit count; dwRBitMask contains the Y mask, dwGBitMask contains the U mask, dwBBitMask contains the V mask) | 0x200 |
| DDPF\_LUMINANCE | Used in some older DDS files for single channel color uncompressed data (dwRGBBitCount contains the luminance channel bit count; dwRBitMask contains the channel mask). Can be combined with DDPF\_ALPHAPIXELS for a two channel DDS file. | 0x20000 |

**dwFourCC**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Four-character codes for specifying compressed or custom formats. Possible values include: *DXT1*, *DXT2*, *DXT3*, *DXT4*, or *DXT5*. A FourCC of DX10 indicates the prescense of the [**DDS\_HEADER\_DXT10**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-header-dxt10) extended header, and the dxgiFormat member of that structure indicates the true format. When using a four-character code, dwFlags must include *DDPF\_FOURCC*.

**dwRGBBitCount**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bits in an RGB (possibly including alpha) format. Valid when **dwFlags** includes *DDPF\_RGB*, *DDPF\_LUMINANCE*, or *DDPF\_YUV*.

**dwRBitMask**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Red (or luminance or Y) mask for reading color data. For instance, given the A8R8G8B8 format, the red mask would be 0x00ff0000.

**dwGBitMask**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Green (or U) mask for reading color data. For instance, given the A8R8G8B8 format, the green mask would be 0x0000ff00.

**dwBBitMask**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Blue (or V) mask for reading color data. For instance, given the A8R8G8B8 format, the blue mask would be 0x000000ff.

**dwABitMask**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Alpha mask for reading alpha data. dwFlags must include *DDPF\_ALPHAPIXELS* or *DDPF\_ALPHA*. For instance, given the A8R8G8B8 format, the alpha mask would be 0xff000000.

## Remarks

To store DXGI formats such as floating-point data, use a **dwFlags** of DDPF\_FOURCC and set **dwFourCC** to 'D','X','1','0'. Use the [**DDS\_HEADER\_DXT10**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-header-dxt10) extension header to store the DXGI format in the **dxgiFormat** member.

Note that there are non-standard variants of DDS files where **dwFlags** has DDPF\_FOURCC and the **dwFourCC** value is set directly to a D3DFORMAT or DXGI\_FORMAT enumeration value. It is not possible to disambiguate the D3DFORMAT versus DXGI\_FORMAT values using this non-standard scheme, so the DX10 extension header is recommended instead.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------|
| Header<br> | Dds.h |

## See also

[Reference for DDS](https://learn.microsoft.com/windows/win32/direct3ddds/dx-graphics-dds-reference)

