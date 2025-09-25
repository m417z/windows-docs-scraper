# D3D11DDI_THREADING_CAPS structure

## Description

The D3D11DDI_THREADING_CAPS structure contains display device threading capabilities.

## Members

### `Caps` [in]

A valid bitwise OR of values that describe the threading capabilities of the driver. The Direct3D runtime supports the following values.

|Value|Meaning|
|--- |--- |
|D3D11DDICAPS_FREETHREADED (0x1)|The driver supports free threading.|
|D3D11DDICAPS_COMMANDLISTS (0x2)|This value is deprecated.The driver supports command lists. To support D3D11DDICAPS_COMMANDLISTS, the driver must also support D3D11DDICAPS_FREETHREADED.|
|D3D11DDICAPS_COMMANDLISTS_BUILD_2 (0x4)|The driver supports command lists. To support D3D11DDICAPS_COMMANDLISTS_BUILD_2, the driver must also support D3D11DDICAPS_FREETHREADED.|

## See also

[D3D10_2DDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_2ddicaps_type)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)