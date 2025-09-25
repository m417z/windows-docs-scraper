## Description

Specifies color space types.

## Constants

### `DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709:0`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 0-255 |
| Gamma | 2.2 |
| Siting | Image |
| Primaries | BT.709 |

This is the standard definition for sRGB.

> [!NOTE]
> This is intended to be implemented with sRGB gamma (linear segment + 2.4 power), which is approximately aligned with a gamma 2.2 curve.

This is usually used with 8 or 10 bit color channels.

### `DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709:1`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 0-255 |
| Gamma | 1.0 |
| Siting | Image |
| Primaries | BT.709 |

This is the standard definition for scRGB, and is usually used with 16 bit integer, 16 bit floating point, or 32 bit floating point color channels.

### `DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P709:2`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 16-235 |
| Gamma | 2.2 |
| Siting | Image |
| Primaries | BT.709 |

This is the standard definition for ITU-R Recommendation BT.709. Note that due to the inclusion of a linear segment, the transfer curve looks similar to a pure exponential gamma of 1.9.

 This is usually used with 8 or 10 bit color channels.

### `DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P2020:3`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 16-235 |
| Gamma | 2.2 |
| Siting | Image |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_RESERVED:4`

Reserved.

### `DXGI_COLOR_SPACE_YCBCR_FULL_G22_NONE_P709_X601:5`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 0-255 |
| Gamma | 2.2 |
| Siting | Image |
| Primaries | BT.709 |
| Transfer Matrix | BT.601 |

This definition is commonly used for JPG, and is usually used with 8, 10, or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P601:6`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 16-235 |
| Gamma | 2.2 |
| Siting | Video |
| Primaries | BT.601 |

This definition is commonly used for MPEG2, and is usually used with 8, 10, or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P601:7`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 0-255 |
| Gamma | 2.2 |
| Siting | Video |
| Primaries | BT.601 |

This is sometimes used for H.264 camera capture, and is usually used with 8, 10, or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P709:8`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 16-235 |
| Gamma | 2.2 |
| Siting | Video |
| Primaries | BT.709 |

This definition is commonly used for H.264 and HEVC, and is usually used with 8, 10, or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P709:9`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 0-255 |
| Gamma | 2.2 |
| Siting | Video |
| Primaries | BT.709 |

This is sometimes used for H.264 camera capture, and is usually used with 8, 10, or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P2020:10`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 16-235 |
| Gamma | 2.2 |
| Siting | Video |
| Primaries | BT.2020 |

This definition may be used by HEVC, and is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P2020:11`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 0-255 |
| Gamma | 2.2 |
| Siting | Video |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020:12`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 0-255 |
| Gamma | 2084 |
| Siting | Image |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_LEFT_P2020:13`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 16-235 |
| Gamma | 2084 |
| Siting | Video |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_RGB_STUDIO_G2084_NONE_P2020:14`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 16-235 |
| Gamma | 2084 |
| Siting | Image |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_TOPLEFT_P2020:15`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 16-235 |
| Gamma | 2.2 |
| Siting | Video |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_TOPLEFT_P2020:16`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCbCr |
| Range | 16-235 |
| Gamma | 2084 |
| Siting | Video |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P2020:17`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 0-255 |
| Gamma | 2.2 |
| Siting | Image |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_GHLG_TOPLEFT_P2020:18`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCBCR |
| Range | 16-235 |
| Gamma | HLG |
| Siting | Video |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_FULL_GHLG_TOPLEFT_P2020:19`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCBCR |
| Range | 0-255 |
| Gamma | HLG |
| Siting | Video |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P709:20`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 16-235 |
| Gamma | 2.4 |
| Siting | Image |
| Primaries | BT.709 |

This is usually used with 8, 10, or 12 bit color channels.

### `DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P2020:21`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | RGB |
| Range | 16-235 |
| Gamma | 2.4 |
| Siting | Image |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P709:22`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCBCR |
| Range | 16-235 |
| Gamma | 2.4 |
| Siting | Video |
| Primaries | BT.709 |

This is usually used with 8, 10, or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P2020:23`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCBCR |
| Range | 16-235 |
| Gamma | 2.4 |
| Siting | Video |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_TOPLEFT_P2020:24`

|  |  |
| --- | --- |
| **Property** | **Value** |
| Colorspace | YCBCR |
| Range | 16-235 |
| Gamma | 2.4 |
| Siting | Video |
| Primaries | BT.2020 |

This is usually used with 10 or 12 bit color channels.

### `DXGI_COLOR_SPACE_CUSTOM:0xFFFFFFFF`

A custom color definition is used.

## Remarks

This enum is used within DXGI in the [CheckColorSpaceSupport](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgiswapchain3-checkcolorspacesupport), [SetColorSpace1](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgiswapchain3-setcolorspace1) and [CheckOverlayColorSpaceSupport](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgioutput4-checkoverlaycolorspacesupport) methods. It is also referenced in D3D11 video methods such as [ID3D11VideoContext1::VideoProcessorSetOutputColorSpace1](https://learn.microsoft.com/windows/win32/api/d3d11_1/nf-d3d11_1-id3d11videocontext1-videoprocessorsetoutputcolorspace1), and D2D methods such as [ID2D1DeviceContext2::CreateImageSourceFromDxgi](https://learn.microsoft.com/windows/win32/api/d2d1_3/nf-d2d1_3-id2d1devicecontext2-createimagesourcefromdxgi).

The following color parameters are defined:

### Colorspace

Defines the color space of the color channel data.

|  |  |  |
| --- | --- | --- |
| **Defined Values** | **Notation in color space enumeration** | **Comments** |
| RGB | _RGB_ | The red/green/blue color space color channel. |
| YCbCr | _YCbCr_ | Three channel color model which splits luma (brightness) from chroma (color). YUV technically refers to analog signals and YCbCr to digital, but they are used interchangeably. |

### Range

Indicates which integer range corresponds to the floating point [0..1] range of the data. For video, integer YCbCr data with ranges of [16..235] or [8..247] are usually mapped to normalized YCbCr with ranges of [0..1] or [-0.5..0.5].

|  |  |  |
| --- | --- | --- |
| **Defined_Values** | **Notation in color space numeration** | **Comments** |
| 8 bit: 0-255<br><br>10 bit: 0-1023<br><br>12 bit: 0-4095 | _FULL_ | PC desktop content and images. |
| 8 bit:16-235<br><br>10 bit: 64-940<br><br>12 bit: 256 - 3760 | _STUDIO_ | Often used in video. Enables the calibration of white and black between displays. |

### Gamma

|  |  |  |
| --- | --- | --- |
| **Defined Values** | **Notation in color space numeration** | **Comments** |
| 1.0 | _G10_ | Linear light levels. |
| 2.2 | _G22_ | Commonly used for sRGB and BT.709 (linear segment + 2.4). |
| 2084 | _G2084_ | See SMPTE ST.2084 (Perceptual Quantization) |

### Siting

"Siting" indicates a horizontal or vertical shift of the chrominance channels relative to the luminance channel.
"Cositing" indicates values are sited between pixels in the vertical or horizontal direction (also known as being "sited interstitially").

|  |  |  |  |
| --- | --- | --- | --- |
| **Defined Values** | **Notation in color space enumeration** | **Comments** | **For Example** |
| Image | _NONE_ | The U and V planes are aligned vertically. | MPEG1, JPG |
| Video | _LEFT_ | Chroma samples are aligned horizontally with the luma samples, or with multiples of the luma samples. The U and V planes are aligned vertically. | MPEG2, MPEG4 |
| Video | _TOPLEFT_ | "Top left" means that the sampling point is the top left pixel (usually of a 2x2 pixel block). Chroma samples are aligned horizontally with the luma samples, or with multiples of the luma samples. Chroma samples are also aligned vertically with the luma samples, or with multiples of the luma samples. | UHD Blu-Ray |

For more information on siting, refer to the [MFVideoChromaSubsampling](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mfvideochromasubsampling) enum.

### Primaries

|  |  |  |
| --- | --- | --- |
| **Defined Values** | **Notation in color space enumeration** | **Comments** |
| BT.601 | _P601 | Standard defining digital encoding of SDTV video. |
| BT.709 | _P709 | Standard defining digital encoding of HDTV video. |
| BT.2020 | _P2020 | Standard defining ultra-high definition television (UHDTV). |

### Transfer Matrix

In most cases, the transfer matrix can be determined from the primaries. For some cases it must be explicitly specified as described below:

|  |  |  |
| --- | --- | --- |
| **Defined Values** | **Notation in color space enumeration** | **Comments** |
| BT.601 | _X601 | Standard defining digital encoding of SDTV video. |
| BT.709 | _X709 | Standard defining digital encoding of HDTV video. |
| BT.2020 | _X2020 | Standard defining ultra-high definition television (UHDTV). |

Subsampling and the layout of the color channels are inferred from the surface format.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)