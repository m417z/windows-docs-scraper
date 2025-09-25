# _DXVA_MBctrl_I_HostResidDiff_1 structure

## Description

The DXVA_MBctrl_I_HostResidDiff_1 structure is sent once per macroblock by the host decoder to the accelerator to specify macroblock control commands for an [intra picture](https://learn.microsoft.com/windows-hardware/drivers/).

## Members

### `wMBaddress`

Specifies the macroblock address of the current macroblock in raster scan order. For examples of macroblock addresses, see [macroblock addresses](https://learn.microsoft.com/windows-hardware/drivers/display/macroblock-addresses).

### `wMBtype`

Specifies the type of macroblock being processed. The following bits define macroblock processing.

| **Bits** | **Description** |
|:--|:--|
| 15 to 12 | MvertFieldSel_3 (bit 15, the most significant bit) through MvertFieldSel_0 (bit 12)<br>Specifies vertical field selection for corresponding motion vectors sent later in the macroblock control command. For frame-based motion with a frame picture structure (for example, for H.261 and H.263), these bits must all be zero. The bits in MvertFieldSel_0, *MvertFieldSel_1,* MvertFieldSel_2, and MvertFieldSel_3 correspond to the motion_vertical_field_select[r][s] bits in Section 6.3.17.2 of MPEG-2. |
| 11 | *Reserved Bit*<br>Must be zero. |
| 10 | *HostResidDiff*<br>Specifies whether spatial-domain residual difference decoded blocks are sent or whether transform coefficients are sent for off-host IDCT for the current macroblock.<br>HostResidDiff is always equal to 1 in this structure. This flag must be zero if bConfigResidDiffHost is zero. This flag must be 1 if bConfigResidDiffAccelerator is zero. The bConfigResidDiffHost and bConfigResidDiffAccelerator members are contained in the [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) structure. |
| 9 and 8 | *MotionType*<br>Must be zero. |
| 7 and 6 | *MBscanMethod*<br>These bits have no meaning and should be set to zero. |
| 5 | *FieldResidual*<br>Indicates whether the residual difference blocks use a field IDCT structure as specified in MPEG-2.<br>Must be 1 if the bPicStructure member of DXVA_PictureParameters is 1 or 2. When used for MPEG-2, FieldResidual must be zero if the frame_pred_frame_DCT flag in the MPEG-2 syntax is 1, and must be equal to the dct_type variable of the MPEG-2 syntax if dct_type is present for the macroblock. |
| 4 | *H261LoopFilter*<br>Must be zero. |
| 3 | *Motion4MV*<br>Must be zero. |
| 2 | *MotionBackward*<br>Must be zero. |
| 1 | *MotionForward*<br>Must be zero. |
| 0 | *IntraMacroblock*<br>Must be 1. |

### `dwMB_SNL`

Specifies the number of skipped macroblocks to be generated following the current macroblock, and indicates the location of the residual difference data for the blocks of the current macroblock. This member contains two variables: *MBskipsFollowing* in the most significant 8 bits, and *MBdataLocation* in the least significant 24 bits. *MBskipsFollowing* indicates the number of skipped macroblocks to be generated following the current macroblock. *MBdataLocation* is an index into the residual difference block data buffer. This index indicates the location of the residual difference data for the blocks of the current macroblock, expressed as a multiple of 32 bits.

### `wPatternCode`

Indicates whether residual difference data is sent for each block in the macroblock. In an intra picture, residual difference data is sent for every block in the macroblock. The bits in **wPatternCode** that refer to all blocks of the current macroblock must be 1 in this structure.

Bit (11-*i*) of **wPatternCode** (where bit zero is the least significant bit) indicates whether residual difference data is sent for block *i*, where *i* is the index of the block within the macroblock as specified in MPEG-2 figures 6-10, 6-11, and 6-12 (raster-scan order for Y, followed by 4:2:0 blocks of Cb in raster-scan order, followed by 4:2:0 blocks of Cr, followed by 4:2:2 blocks of Cb, followed by 4:2:2 blocks of Cr, followed by 4:4:4 blocks of Cb, followed by 4:4:4 blocks of Cr). The data for the coded blocks (those blocks having bit (11*i*) equal to 1) is found in the residual coding buffer in the same indexing order (increasing *i*). For 4:2:0 MPEG-2 data, the value of **wPatternCode** corresponds to shifting the decoded value of the CBP (coded block pattern) to the left by six bit positions (those lower bit positions being used for 4:2:2 and 4:4:4 chroma formats).

If the **bConfigSpatialResidInterleaved** member of the [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) structure is 1, host-based residual differences are sent in a chroma-interleaved form matching that of the YUV pixel format in use. In this case, each Cb and spatially corresponding Cr pair of blocks is treated as a single residual difference structure unit. This does not alter the value or meaning of **wPatternCode**, but it implies that both members of each pair of Cb and Cr data blocks are sent whenever either of these data blocks has the corresponding bit set in **wPatternCode**. If the bit in **wPatternCode** for a particular data block is zero, the corresponding residual difference data values must be sent as zero whenever this pairing necessitates sending a residual difference data block for a block with a **wPatternCode** bit equal to zero.

### `wPC_Overflow`

Must be zero.

### `dwReservedBits2`

Reserved bits used for packing and alignment. Must be zero.

## Remarks

Skipped macroblocks are not used by intra pictures, so the *MBskipsFollowing* variable must be zero. The *MBdataLocation* variable must be zero for the first macroblock in the macroblock control command buffer. For more information about how skipped macroblocks are generated, see [Generating Skipped Macroblocks](https://learn.microsoft.com/windows-hardware/drivers/display/generating-skipped-macroblocks).

## See also

[DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode)

[DXVA_MBctrl_I_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_i_offhostidct_1)

[DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters)

[DXVA_TCoefSingle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_tcoefsingle)