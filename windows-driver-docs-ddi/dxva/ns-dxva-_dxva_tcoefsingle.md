# _DXVA_TCoefSingle structure

## Description

The DXVA_TCoefSingle structure is sent by the host decoder to the accelerator to specify [IDCT](https://learn.microsoft.com/windows-hardware/drivers/) coefficient values.

## Members

### `wIndexWithEOB`

This member contains two fields: *TCoefIDX* and *TCoefEOB*.

#### TCoefIDX

Specifies the scan index of the coefficient in the block, as determined from the **bConfigHostInverseScan** member of the [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) structure. This field is in the 15 most significant bits of the **wIndexWithEOB** member.

There are two ways that *TCoefIDX* can be used:

1. Run-length ordering: When **bConfigHostInverseScan** is zero, the *MBscanMethod* element of the macroblock control command indicates a zigzag, alternate-vertical, or alternate-horizontal inverse scan. These macroblock control commands are defined in the following structures: [DXVA_MBctrl_I_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_i_offhostidct_1) or [DXVA_MBctrl_P_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_offhostidct_1). In this case, *TCoefIDX* contains the number of zero-valued coefficients that precede the current coefficient in the specified scan order, subsequent to the last transmitted coefficient for the block (or relative to the start of the block if none precede it). Any remaining coefficients after the last sent coefficient in the inverse-scan order are implied to have the value zero.
2. Arbitrary ordering: When **bConfigHostInverseScan** is 1, the *MBscanMethod* element of the macroblock control command indicates arbitrary ordering. These macroblock control commands are defined in the following structures: [DXVA_MBctrl_I_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_i_offhostidct_1) and [DXVA_MBctrl_P_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_offhostidct_1). In this case, *TCoefIDX* simply contains the raster index of the coefficient within the block (TCoefIDX = u + 8 * v, where u and v are the transform-domain horizontal and vertical frequency coordinates), and any coefficients that are not sent are implied to have the value 0.

*TCoefIDX* must always be less than 64.

#### TCoefEOB

Indicates whether the current coefficient is the last one associated with the current block of transform coefficients. A value of 1 indicates that the current coefficient is the last one for the block and a value of zero indicates that it is not. This field is in the least significant bit of the **wIndexWithEOB** member.

### `TCoefValue`

Indicates the value of the coefficient in the block. **TCoefValue** must be clipped to the appropriate range as specified in [Low-Level IDCT Processing Elements](https://learn.microsoft.com/windows-hardware/drivers/display/low-level-idct-processing-elements) by the host prior to passing the coefficient value to the accelerator for [IDCT](https://learn.microsoft.com/windows-hardware/drivers/) operation. MPEG-2 mismatch control, if necessary, is also the responsibility of the host, not the accelerator. (This might require the creation of extra "phantom" nonzero coefficients.)

## Remarks

The DXVA_TCoefSingle structure is used whenever the *HostResidDiff* flag (bit 10 in the **wMBtype** member of the [DXVA_MBctrl_P_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_offhostidct_1) or [DXVA_MBctrl_I_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_i_offhostidct_1) structure) is 1 and the **bConfig4GroupedCoefs** member of the [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) structure is zero.

## See also

[DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode)

[DXVA_MBctrl_I_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_i_offhostidct_1)

[DXVA_MBctrl_P_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_offhostidct_1)