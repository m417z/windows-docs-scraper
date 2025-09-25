# D3DKM_TRANSPARENTBLTFLAGS structure

## Description

The **D3DKM_TRANSPARENTBLTFLAGS** structure specifies the display adapter's ability to perform a hardware-accelerated bit-block transfer (bitblt) with transparency.

## Members

### `HonorAlpha` [in]

A UINT value that specifies in a hardware-accelerated transparent bit-block transfer whether the alpha channel should be used during comparison. **HonorAlpha** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| 1 | The display adapter does not ignore the alpha channel when it compares the reference color with the source color. |
| 0 | The display adapter ignores the alpha channel when it compares the reference color with the source color. |

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Value` [in]

A member in the union that D3DKM_TRANSPARENTBLTFLAGS contains. This member can hold a 32-bit value that specifies the display adapter's ability to perform hardware-accelerated bit-block transfer with transparency.

## See also

[**DXGK_GDIARG_TRANSPARENTBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_transparentblt)