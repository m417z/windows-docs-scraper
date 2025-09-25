# _D3DKMT_PRESENT_DISPLAY_ONLY_FLAGS structure

## Description

Indicates how a kernel mode display-only driver (KMDOD) is to perform a present operation.

## Members

### `Rotate` [in]

A UINT value that specifies whether to rotate the presentation data to match the current orientation of the screen during the presentation bit-block transfer (bitblt). The current orientation of the screen is set in the **Rotation** member of a [D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation) structure, which is set in the **ContentTransformation** member of the [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure for the video present path.

The KMDOD should rotate the data only if the **Rotate** bit-field flag is set. Even if the KMDOD determines that the current orientation of the screen is rotated from the presentation data and **Rotate** is not set, the KMDOD should not rotate the data.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved` [in]

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFF) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that **D3DKMT_PRESENT_DISPLAY_ONLY_FLAGS** contains that can hold a 32-bit value that identifies the type of present operation to perform.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation)