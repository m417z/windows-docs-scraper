# _DXVA_MBctrl_P_OffHostIDCT_1 structure

## Description

The DXVA_MBctrl_P_OffHostIDCT_1 structure is sent once per macroblock by the host decoder to the accelerator to specify macroblock control commands for most nonintra pictures using off-host IDCT.

## Members

### `wMBaddress`

Specifies the macroblock address of the current macroblock in raster scan order. For examples of macroblock addresses see [macroblock addresses](https://learn.microsoft.com/windows-hardware/drivers/display/macroblock-addresses).

### `wMBtype`

Specifies the type of macroblock being processed. The following bits define macroblock processing.

| **Bits** | **Description** |
|:--|:--|
| 15 to 12 | MvertFieldSel_3 (bit 15 the most significant bit) through MvertFieldSel_0 (bit 12)<br>Specifies vertical field selection for corresponding motion vectors sent later in the macroblock control command. For frame-based motion with a frame picture structure (for example, for H.261 and H.263), these bits must all be zero. The use of these bits is the same as that specified for the corresponding bits in Section 6.3.17.2 of MPEG-2. |
| 11 | *Reserved Bit* <br>Must be zero. |
| 10 | *HostResidDiff* <br>Specifies whether spatial-domain residual difference decoded blocks are sent or whether transform coefficients are sent for off-host IDCT for the current macroblock.<br>This flag must be zero if bConfigResidDiffHost is zero. This flag must be 1 if bConfigResidDiffAccelerator is zero. This flag is always equal to zero in DXVA_MBctrl_P_OffHostIDCT_1. |
| 9 and 8 | *MotionType*<br>Specifies the motion type in the picture. For example, for frame-based motion with a frame picture structure (as in H.261), bit 9 must be 1 and bit 8 must be zero.<br>The use of these bits corresponds directly to the use of frame_motion_type or field_motion_type bits in MPEG-2 when these bits are present in MPEG-2. The use of these bits are further explained in the following Remarks section. |
| 7 and 6 | *MBscanMethod*<br>Specifies the scan method to be used.<br>This must be equal to bPicScanMethod if bPicScanFixed is 1.<br>If bConfigHostInverseScan is zero, MBscanMethod must be one of the following values:

* Bit 6 is zero and bit 7 is zero for zigzag scan (MPEG-2 Figure 7-2).
* Bit 6 is 1 and bit 7 is zero for alternate-vertical scan.
* Bit 6 is zero and bit 7 is 1 for alternate-horizontal scan.

If bConfigHostInverseScan is 1, MBscanMethod must be equal to the following value:

* Bit 6 is 1 and bit 7 is 1 for arbitrary scan with absolute coefficient address.

Both bPicScanMethod and bPicScanFixed are members of [DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters) . bConfigHostInverseScan is a member of [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode). |
| 5 | *FieldResidual*<br>Indicates whether the residual difference blocks use a field IDCT structure as specified in MPEG-2.<br>This flag must be 1 if the bPicStructure member of DXVA_PictureParameters is 1 or 2.<br>When used for MPEG-2, FieldResidual must be zero if the frame_pred_frame_DCT flag in the MPEG-2 syntax is 1, and must be equal to the dct_type element of the MPEG-2 syntax if dct_type is present for the macroblock. |
| 4 | *H261LoopFilter*<br>Specifies whether the H.261 loop filter (Section 3.2.3 of H.261) is active for the current macroblock prediction. The H.261 loop filter is a separable Â¼, Â½, Â¼ filter applied both horizontally and vertically to all six blocks in an H.261 macroblock, except at block edges where one of the taps would fall outside the block. In such cases, the filter is changed to have coefficients 0, 1, 0. Full arithmetic precision is retained with rounding to 8-bit integers at the output of the 2-D filter process (half-integer or higher values being rounded up). |
| 3 | *Motion4MV*<br>Indicates that forward motion uses a distinct motion vector for each of the four luminance blocks in the macroblock, as used in H.263 Annexes F and J.Motion4MV must be zero if MotionForward is zero or if the bPic4MVallowed member of [DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters) is zero. |
| 2 | *MotionBackward*<br>Used as specified for the corresponding macroblock_motion_backwardparameter in MPEG-2. If the bPicBackwardPrediction member of [DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters) is zero, MotionBackward must be zero. The use of this bit is further explained in the following Remarks section. |
| 1 | *MotionForward*<br>Used as specified for the corresponding macroblock_motion_forward in MPEG-2. The use of this bit is further explained in the following Remarks section. |
| 0 | *IntraMacroblock*<br>Indicates that the macroblock is coded as intra, and no motion vectors are used for the current macroblock. Corresponds to macroblock_intrain MPEG-2. The use of this bit is further explained in the following Remarks section. |

### `dwMB_SNL`

Specifies the number of skipped macroblocks to be generated following the current macroblock and indicates the location of the residual difference data for the blocks of the current macroblock. This member contains two variables: *MBskipsFollowing* in the most significant 8 bits and *MBdataLocation* in the least significant 24 bits. *MBskipsFollowing* indicates the number of skipped macroblocks to be generated following the current macroblock. *MBdataLocation* is an index into the IDCT residual difference block data buffer. This index indicates the location of the residual difference data for the blocks of the current macroblock, expressed as a multiple of 32 bits.

### `wPatternCode`

Indicates whether residual difference data is sent for each block in the macroblock.

Bit (11-*i*) of **wPatternCode** (where *i* is the index of the block within the macroblock and bit 0 represents the least significant bit) indicates whether residual difference data is sent for block *i* (See [Macroblock-Oriented Picture Decoding](https://learn.microsoft.com/windows-hardware/drivers/display/macroblock-oriented-picture-decoding) for more information)*.* The value *i* is the index of the block within the macroblock as specified in MPEG-2 figures 6-10, 6-11, and 6-12 (raster-scan order for Y, followed by 4:2:0 blocks of Cb in raster-scan order, followed by 4:2:0 blocks of Cr, followed by 4:2:2 blocks of Cb, followed by 4:2:2 blocks of Cr, followed by 4:4:4 blocks of Cb, followed by 4:4:4 blocks of Cr). The data for the coded blocks (blocks having bit (11-*i*) equal to 1) is found in the residual coding buffer in the same indexing order (increasing *i*). For 4:2:0 MPEG-2 data, the value of **wPatternCode** corresponds to shifting the decoded value of CBP to the left by six bit positions (those lower bit positions being used for 4:2:2 and 4:4:4 chroma formats).

If the **bConfigSpatialResidInterleaved** member of [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) is 1, host-based residual differences are sent in a chroma-interleaved form matching that of the YUV pixel format in use. In this case, each Cb and spatially corresponding Cr pair of blocks is treated as a single residual difference data structure unit. This does not alter the value or meaning of **wPatternCode**, but it implies that both members of each pair of Cb and Cr data blocks are sent whenever either of these data blocks has the corresponding bit set in **wPatternCode**. If the bit in **wPatternCode** for a particular data block is zero, the corresponding residual difference data values must be sent as zero whenever this pairing requires sending a residual difference data block for a block with a **wPatternCode** bit equal to zero.

### `bNumCoef`

Each value in the **bNumCoef** array indicates the number of coefficients in the residual difference data buffer for each block *i* of the macroblock.

The array subscript *i* is the index of the block within the macroblock as specified in MPEG-2 video Figures 6-10, 6-11, and 6-12 (raster-scan order for Y, followed by Cb, followed by Cr).

This member is used only when the *HostResidDiff* flag (bit 10 in **wMBtype**) is zero and **bChromaFormat** is 1 (4:2:0). If used in 4:2:2 or 4:4:4 formats, it would increase the size of typical macroblock control commands past a critical memory alignment boundary. As a result, the *TCoefEOB* bit within the [DXVA_TCoefSingle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_tcoefsingle) structure is used for determining the number of coefficients in each block in non-4:2:0 cases.

The purpose of **bNumCoef** is to indicate the quantity of data present for each block in the residual difference data buffer, expressed as the number of coefficients present. When the **bConfig4GroupedCoefs** member of the [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) structure is 1, **bNumCoef** may contain either the actual number of coefficients sent for the block or that value rounded up to be a multiple of four. The data for these coefficients is found in the residual difference buffer in the same order.

### `MVector`

An array containing the value of the motion vector(s) for the macroblock, each represented using a [DXVA_MVvalue](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mvvalue) structure.

## Remarks

Each skipped macroblock specified by *MBskipsFollowing* must be generated in a manner mathematically equivalent to incrementing the value of **wMBaddress** and then repeating the same macroblock control command. Any macroblock control command with a nonzero value for *MBskipsFollowing* specifies how motion-compensated prediction is to be performed for each macroblock to be skipped, and is equivalent (except for the value of *MBskipsFollowing*) to an explicit nonskip specification of the generation of the first of the series of skipped macroblocks. Thus, whenever *MBskipsFollowing* is not zero, the following values must all be equal to zero: *Motion4MV*, *IntraMacroblock*, and **bNumCoef**.

*MBdataLocation* is an index into the IDCT residual difference block data buffer, indicating the location of the residual difference data for the blocks of the current macroblock, expressed as a multiple of 32 bits. Must be zero for the first macroblock in the macroblock control command buffer. *MBdataLocation* may contain any value if **wPatternCode** is zero. When **wPatternCode** is zero, decoders are recommended but not required to set this value either to zero or to the same value as in the next macroblock control command.

For more information about how skipped macroblocks are generated, see [Generating Skipped Macroblocks](https://learn.microsoft.com/windows-hardware/drivers/display/generating-skipped-macroblocks).

Valid combinations of *IntraMacroblock*, *MotionForward*, *MotionBackward*, *MotionType*, *MvertFieldSel*, and **MVector** are shown in the tables in [First Part of Macroblock Control Command Structure](https://learn.microsoft.com/windows-hardware/drivers/display/first-part-of-macroblock-control-command-structure).

## See also

[DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode)

[DXVA_MBctrl_P_HostResidDiff_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_hostresiddiff_1)

[DXVA_MVvalue](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mvvalue)

[DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters)

[DXVA_TCoefSingle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_tcoefsingle)