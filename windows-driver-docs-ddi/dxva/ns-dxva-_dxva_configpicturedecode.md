# _DXVA_ConfigPictureDecode structure

## Description

The DXVA_ConfigPictureDecode structure is sent by the host decoder to the accelerator to set the configuration for compressed picture decoding.

## Members

### `dwFunction`

Indicates the type of query or response when using probing and locking commands. The most significant 24 bits of **dwFunction** is the [DXVA_ConfigQueryOrReplyFlag](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-configqueryorreplyflag-and-dxva-configqueryorreplyfunc-variables) variable.

The least significant 4 bits of the *DXVA_ConfigQueryOrReplyFlag* variable contains status indicators for the query or response being performed.

The least significant 8 bits of **dwFunction** is the [bDXVA_Func variable](https://learn.microsoft.com/windows-hardware/drivers/display/bdxva-func-variable) that, in this case, is equal to 1.

### `dwReservedBits`

Reserved bits used for packing and alignment. These bits are zero.

### `guidConfigBitstreamEncryption`

Indicates a GUID associated with the encryption protocol type for bitstream data buffers. The value DXVA_NoEncrypt (a GUID name defined in *dxva.h*) indicates that encryption is not applied. This is DXVA_NoEncrypt if **bConfigBitstreamRaw** is zero.

### `guidConfigMBcontrolEncryption`

Indicates a GUID associated with the encryption protocol type for [macroblock control buffers](https://learn.microsoft.com/windows-hardware/drivers/display/macroblock-oriented-picture-decoding). The value DXVA_NoEncrypt (a GUID name defined in *dxva.h*) indicates that encryption is not applied. This is DXVA_NoEncrypt if **bConfigBitstreamRaw** is 1.

### `guidConfigResidDiffEncryption`

Indicates a GUID associated with the encryption protocol type for residual difference decoding data buffers (buffers containing spatial-domain data or sets of transform-domain coefficients for accelerator-based [IDCT](https://learn.microsoft.com/windows-hardware/drivers/)). This is DXVA_NoEncrypt if **bConfigBitstreamRaw** is 1. (DXVA_NoEncrypt is a GUID defined in *dxva.h* that indicates encryption is not applied.)

### `bConfigBitstreamRaw`

Contains the bitstream processing indicator. A value of 1 specifies that the picture data will be sent in bitstream buffers as raw bitstream content. A value of zero specifies that picture data will be sent using macroblock control command buffers.

This is zero if **bConfigResidDiffHost** is 1 or if **bConfigResidDiffAccelerator** is 1. The value zero is considered the basic level of support. The additional support of level one is preferred.

### `bConfigMBcontrolRasterOrder`

Specifies whether macroblock control commands are in raster scan order or in arbitrary order. A value of 1 specifies that the macroblock control commands within each macroblock control command buffer are in raster scan order, and a value of zero indicates arbitrary order. Currently, a driver is allowed to restrict support to raster scan order; however, a driver should support both arbitrary and raster scan order.

### `bConfigResidDiffHost`

Contains the host residual difference configuration (See [Macroblock-Oriented Picture Decoding](https://learn.microsoft.com/windows-hardware/drivers/display/macroblock-oriented-picture-decoding) for more information). A value of 1 specifies that some residual difference decoding data may be sent as blocks in the spatial domain from the host. A value of zero specifies that spatial domain data will not be sent. This member is zero if **bConfigBitstreamRaw** is 1. It is preferred that an accelerator support both zero and 1.

### `bConfigSpatialResid8`

Indicates the word size used to represent residual difference spatial-domain blocks for predicted (nonintra) pictures when using host-based residual difference decoding (when **bConfigResidDiffHost** is equal to 1).

If **bConfigSpatialResid8** is 1 and **bConfigResidDiffHost** is 1, the host will send residual difference spatial-domain blocks for nonintra macroblocks using 8-bit signed samples, and for intra macroblocks in predicted (nonintra) pictures in a format depending on **bConfigIntraResidUnsigned** as follows:

* If **bConfigIntraResidUnsigned** is zero, spatial-domain blocks for intra macroblocks are sent as 8-bit signed integer values relative to a constant reference value of 128.
* If **bConfigIntraResidUnsigned** is 1, spatial-domain blocks for intra macroblocks are sent as 8-bit unsigned integer values relative to a constant reference value of zero.

If **bConfigSpatialResid8** is zero and **bConfigResidDiffHost** is 1, the host will send residual difference spatial-domain blocks of data for nonintra macroblocks using 16-bit signed samples, and for intra macroblocks in predicted (nonintra) pictures in a format depending on **bConfigIntraResidUnsigned** as follows:

* If **bConfigIntraResidUnsigned** is zero, spatial domain blocks for intra macroblocks are sent as 16-bit signed integer values relative to a constant reference value of 2(BPP-1), where *BPP* is the number of bits per sample for the uncompressed video (generally a value of 8).
* If **bConfigIntraResidUnsigned** is 1, spatial domain blocks for intra macroblocks are sent as 16-bit unsigned integer values relative to a constant reference value of zero.

The **bConfigSpatialResid8** member must be zero if **bConfigResidDiffHost** is zero. There is no preference for one particular value of **bConfigSpatialResid8** when **bConfigResidDiffHost** is 1.

**Note** For [intra pictures](https://learn.microsoft.com/windows-hardware/drivers/) with *BPP* equal to 8, spatial-domain blocks must be sent using 8-bit samples. For intra pictures with *BPP* greater than 8, spatial-domain blocks must be sent using 16-bit samples. (The *BPP* variable is the number of bits per sample for the uncompressed video, generally a value of 8.)

If **bConfigIntraResidUnsigned** is zero, these samples are sent as signed integer values relative to a constant reference value of 2(BPP-1). If **bConfigIntraResidUnsigned** is 1, these samples are sent as unsigned integer values relative to a constant reference value of zero.

### `bConfigResid8Subtraction`

When equal to 1, indicates that 8-bit difference overflow blocks are subtracted rather than added. Must be zero unless **bConfigSpatialResid8** is 1. The preferred value for an accelerator to support is 1 if **bConfigSpatialResid8** is 1. The ability to subtract differences rather than to add them allows 8-bit difference decoding to be fully compliant with the full +/-255 range of values required in video decoder specifications. This is because +255 cannot be represented as the addition of two signed 8-bit numbers but any number in the range +/-255 can be represented as the difference between two signed 8-bit numbers (+255 is equal to +127 minus âˆ’128).

### `bConfigSpatialHost8or9Clipping`

When equal to 1, indicates that spatial-domain blocks for intra macroblocks are clipped to an 8-bit range on the host and that spatial-domain blocks for nonintra macroblocks are clipped to a 9-bit range on the host. A value of zero indicates that no such clipping is performed by the host. Must be zero unless **bConfigSpatialResid8** is equal to zero and **bConfigResidDiffHost** is equal to 1. The preferred value for an accelerator to support is zero.

### `bConfigSpatialResidInterleaved`

When equal to 1, indicates that any spatial-domain residual difference data is sent in a chrominance-interleaved form matching the YUV format chrominance interleaving pattern. Must be zero unless **bConfigResidDiffHost** is 1 and the YUV format is NV12 or NV21. The preferred value for an accelerator to support is zero.

### `bConfigIntraResidUnsigned`

Indicates the method of representation of spatial-domain blocks of residual difference data for intra blocks when using host-based difference decoding (when **bConfigResidDiffHost** is equal to 1).

When **bConfigIntraResidUnsigned** is equal to zero and **bConfigResidDiffHost** is equal to 1, spatial-domain residual difference data blocks for intra macroblocks are sent as follows:

* In a nonintra picture if **bConfigSpatialResid8** is zero, the spatial-domain residual difference data blocks for intra macroblocks are sent as 16-bit signed integer values relative to a constant reference value of 2(BPP-1), where *BPP* is the number of bits per sample for the uncompressed video (generally a value of 8).
* In a nonintra picture if **bConfigSpatialResid8** is 1 and in an intra picture if *BPP* is equal to 8 (regardless of the value of **bConfigSpatialResid8**), the spatial-domain residual difference data blocks for intra macroblocks are sent as 8-bit signed integer values relative to a constant reference value of 128.

When **bConfigIntraResidUnsigned** is equal to 1 and **bConfigResidDiffHost** is equal to 1, spatial-domain residual difference data blocks for intra macroblocks are sent as follows:

* In a nonintra picture if **bConfigSpatialResid8** is zero, the spatial-domain residual difference data blocks for intra macroblocks are sent as 16-bit unsigned integer values relative to a constant reference value of zero.
* In a nonintra picture if **bConfigSpatialResid8** is 1 and in an intra picture if *BPP* is equal to 8 (regardless of the value of **bConfigSpatialResid8**), the spatial-domain residual difference data blocks for intra macroblocks are sent as 8-bit unsigned integer values relative to a constant reference value of zero.

The **bConfigIntraResidUnsigned** member must be zero unless **bConfigResidDiffHost** is 1.

The preferred value for an accelerator to support is zero for **bConfigIntraResidUnsigned**.

### `bConfigResidDiffAccelerator`

Contains the accelerator residual difference configuration. A value of 1 indicates that transform-domain blocks of coefficient data may be sent from the host for accelerator-based IDCT. A value of zero specifies that accelerator-based IDCT will not be used. If both **bConfigResidDiffHost** and **bConfigResidDiffAccelerator** are 1, some residual difference decoding will be done on the host and some on the accelerator, as indicated by macroblock-level control commands. This member must be zero if **bConfigBitstreamRaw** is 1.

The preferred value for an accelerator to support is 1 for **bConfigResidDiffAccelerator**.

When **bConfigResidDiffAccelerator** and **bConfigResidDiffHost** are equal to 1, residual difference decoding can be shared between the host and accelerator on a macroblock basis. This is considered an even higher level of accelerator capability than when **bConfigResidDiffAccelerator** is equal to 1 and **bConfigResidDiffHost** is equal to zero.

### `bConfigHostInverseScan`

Indicates whether the inverse scan for transform-domain block processing is performed on the host or the accelerator. A value of 1 indicates that the inverse scan for transform-domain block processing will be performed on the host, and absolute indices will be sent instead for any transform coefficients. A value of zero indicates that inverse scan will be performed on the accelerator. This member must be zero if **bConfigResidDiffAccelerator** is zero or if **bConfig4GroupedCoefs** is 1.

The preferred value for an accelerator to support is 1 if **bConfigResidDiffAccelerator** is 1.

### `bConfigSpecificIDCT`

Indicates the use of a specific [IDCT](https://learn.microsoft.com/windows-hardware/drivers/) method for off-host IDCT. A value of 1 indicates use of the IDCT specified in Annex W of ITU-T Recommendation H.263. A value of zero indicates that any compliant IDCT can be used for off-host IDCT. (Values other than zero and 1 are reserved for future use.)

This member must be zero if **bConfigResidDiffAccelerator** is zero (simply indicating host-based residual difference decoding).

**Note** Annex W of ITU-T Recommendation H.263 does not comply with the IDCT requirements of MPEG-2 corrigendum 2 and thus **bConfigSpecificIDCT** must not be one for use with MPEG-2 video.

### `bConfig4GroupedCoefs`

A value of 1 indicates that transform coefficients for off-host IDCT will be sent using the [DXVA_TCoef4Group](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_tcoef4group) structure rather than the [DXVA_TCoefSingle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_tcoefsingle) structure. This is zero if **bConfigResidDiffAccelerator** is zero or if **bConfigHostInverseScan** is 1.

The preferred value for an accelerator to support is zero if **bConfigResidDiffAccelerator** is 1.

## Remarks

For some types of bitstreams, forcing macroblock control commands within each macroblock control command buffer to be in raster order either greatly increases the number of required buffers that must be processed or requires host reordering of the control information. Support of arbitrary order can thus be advantageous for the decoding process. For example, H.261 CIF-resolution decoding can require 36 macroblock control buffers per picture if raster scan order is necessary within each buffer (H.263 Annex K's arbitrary slice ordering and rectangular slice modes have more severe repercussions, possibly requiring an extremely large number of buffers.)

## See also

[DXVA_MBctrl_I_HostResidDiff_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_i_hostresiddiff_1)

[DXVA_MBctrl_I_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_i_offhostidct_1)

[DXVA_MBctrl_P_HostResidDiff_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_hostresiddiff_1)

[DXVA_MBctrl_P_OffHostIDCT_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_mbctrl_p_offhostidct_1)

[DXVA_TCoef4Group](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_tcoef4group)

[DXVA_TCoefSingle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_tcoefsingle)