# _DXVA_TCoef4Group structure

## Description

The DXVA_TCoef4Group structure is sent by the host decoder to the accelerator to specify the IDCT coefficient values.

## Members

### `TCoefIDX`

Specifies the scan index of the coefficient in the block. Expressed as the number of zero-valued coefficients that precede the current coefficient in the scan order specified by the *MBscanMethod* variable (bits 6 and 7 of the **wMBtype** member of the macroblock control command). These commands are defined in the following structures: [DXVA_MBctrl_I_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_i_offhostidct_1) or [DXVA_MBctrl_P_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_offhostidct_1). **TCoefIDX** contains the number of zero-valued coefficients that precede the current coefficient in the specified scan order, subsequent to the last transmitted coefficient for the block (or relative to the start of the block if none precede it). Any remaining coefficients after the last sent coefficient in the inverse-scan order are implied to have the value 0.

**TCoefIDX** must always be less than 64.

### `TCoefValue`

Specifies the value of the coefficient in the block. **TCoefValue** must be clipped to the appropriate range as specified in [Low-Level IDCT Processing Elements](https://learn.microsoft.com/windows-hardware/drivers/display/low-level-idct-processing-elements) by the host prior to passing the coefficient value to the accelerator for IDCT operation. MPEG-2 mismatch control, if necessary, is also the responsibility of the host, not the accelerator (this may require the creation of extra "phantom" nonzero coefficients).

## Remarks

The DXVA_TCoef4Group structure is used only when these two members of [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) structure are set to the following values: **bConfig4GroupedCoefs** is 1 and **bConfigHostInverseScan** is zero.

In the DXVA_TCoef4Group structure, groups of four transform coefficients are sent together with associated run-length values. The *i*th element of each array in DXVA_TCoef4Group contains element 3-*i* of the actual coefficient or run-length list (so the first coefficient or index goes into element 3, the next in element 2, and so forth). If only NC < 4 nonzero coefficients remain that need to be sent for a block, then **TCoefIDX**[*i*] must be 63 (hexadecimal 0x3F), and **TCoefValue**[*i*] must be equal to **TCoefValue**[4-NC] for *i* = 0 to 3-NC.

## See also

[DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode)