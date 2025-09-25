# _DDIGAMMACAPS structure

## Description

The DDIGAMMACAPS structure describes gamma-ramp capabilities that the user-mode display driver supports.

## Members

### `GammaCaps` [out]

A valid bitwise OR of the following capability bits that the driver supports.

| **Capability bit** | **Meaning** |
|:--|:--|
| GAMMA_CAP_RGB256x3x16 (0x00000001) | Gamma-ramp data is stored as 256 16-bit RGB values. |

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)