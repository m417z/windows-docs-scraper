# _DDRAW_CAPS structure

## Description

The DDRAW_CAPS structure describes general Microsoft DirectDraw capabilities that the user-mode display driver supports.

## Members

### `Caps` [out]

A valid bitwise OR of the following general capability bits that the driver supports.

| **Capability bit** | **Meaning** |
|:--|:--|
| DDRAW_CAPS_ZBLTS | Z-buffers can be used in bit-block transfer (bitblt) operations. |
| DDRAW_CAPS_COLORKEY | Some form of color key can be used in either overlay or bitblt operations. For more specific color key capability information, see the CKeyCaps member. |
| DDRAW_CAPS_BLTDEPTHFILL | Z-buffers can be depth-filled in bitblt operations. |

### `Caps2` [out]

A valid bitwise OR of more of the following general capability bits that the driver supports.

| **Capability bit** | **Meaning** |
|:--|:--|
| DDRAW_CAPS2_VIDEOPORT | A hardware video port can be used. |
| DDRAW_CAPS2_CANDROPZ16BIT | Sixteen-bit RGBZ values can be converted into 16-bit RGB values. (The system does not support 8-bit conversions.) |
| DDRAW_CAPS2_FLIPINTERVAL | The driver responds to the Flip bit-field flag. |
| DDRAW_CAPS2_FLIPNOVSYNC | The driver responds to the FlipWithNoWait bit-field flag. |
| DDRAW_CAPS2_DYNAMICTEXTURES | The driver supports dynamic textures. |

### `CKeyCaps` [out]

A valid bitwise OR of the following color key capability bits that the driver supports.

| **Capability bit** | **Meaning** |
|:--|:--|
| DDRAW_CKEYCAPS_SRCBLT | Transparent bit-block transfers can be performed with a color key that identifies bits of the source surface that are copied to the destination surface. |
| DDRAW_CKEYCAPS_DESTBLT | Transparent bit-block transfers (bitblts) can be performed with a color key that identifies the replaceable bits of the destination surface. |

### `FxCaps` [out]

A valid bitwise OR of the following stretching and effects capability bits that the driver supports.

| **Capability bit** | **Meaning** |
|:--|:--|
| DDRAW_FXCAPS_BLTMIRRORLEFTRIGHT | Bit-block transfers (bitblts) that flip the contents of the source surface to the destination surface horizontally along the center axis can be performed. |
| DDRAW_FXCAPS_BLTMIRRORUPDOWN | Bit-block transfers (bitblts) that flip the contents of the source surface to the destination surface vertically along the center axis can be performed. |

### `MaxVideoPorts` [out]

The maximum number of video ports that the device supports.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)