# D3D11_VIDEO_DECODER_CONFIG structure

## Description

Describes the configuration of a Microsoft Direct3D 11 decoder device for DirectX Video Acceleration (DXVA).

## Members

### `guidConfigBitstreamEncryption`

If the bitstream data buffers are encrypted using the D3D11CryptoSession mechanism, this GUID should be set to zero. If no encryption is applied, the value is **DXVA_NoEncrypt**. If **ConfigBitstreamRaw** is 0, the value must be **DXVA_NoEncrypt**.

### `guidConfigMBcontrolEncryption`

If the macroblock control data buffers are encrypted using the D3D11CryptoSession mechanism, this GUID should be set to zero. If no encryption is applied, the value is **DXVA_NoEncrypt**. If **ConfigBitstreamRaw** is 1, the value must be **DXVA_NoEncrypt**.

### `guidConfigResidDiffEncryption`

If the residual difference decoding data buffers are encrypted using the D3D11CryptoSession mechanism, this GUID should be set to zero. If no encryption is applied, the value is **DXVA_NoEncrypt**. If **ConfigBitstreamRaw** is 1, the value must be **DXVA_NoEncrypt**.

### `ConfigBitstreamRaw`

Indicates whether the host-decoder sends raw bit-stream data. If the value is 1, the data for the pictures will be sent in bit-stream buffers as raw bit-stream content. If the value is 0, picture data will be sent using macroblock control command buffers. If either **ConfigResidDiffHost** or **ConfigResidDiffAccelerator** is 1, the value must be 0.

### `ConfigMBcontrolRasterOrder`

Specifies whether macroblock control commands are in raster scan order or in arbitrary order. If the value is 1, the macroblock control commands within each macroblock control command buffer are in raster-scan order. If the value is 0, the order is arbitrary. For some types of bit streams, forcing raster order either greatly increases the number of required macroblock control buffers that must be processed, or requires host reordering of the control information. Therefore, supporting arbitrary order can be more efficient.

### `ConfigResidDiffHost`

Contains the host residual difference configuration. If the value is 1, some residual difference decoding data may be sent as blocks in the spatial domain from the host. If the value is 0, spatial domain data will not be sent.

### `ConfigSpatialResid8`

Indicates the word size used to represent residual difference spatial-domain blocks for predicted (non-intra) pictures when using host-based residual difference decoding.

If **ConfigResidDiffHost** is 1 and **ConfigSpatialResid8** is 1, the host will send residual difference spatial-domain blocks for non-intra macroblocks using 8-bit signed samples and for intra macroblocks in predicted (non-intra) pictures in a format that depends on the value of **ConfigIntraResidUnsigned**:

* If **ConfigIntraResidUnsigned** is 0, spatial-domain blocks for intra macroblocks are sent as 8-bit signed integer values relative to a constant reference value of 2^(BPP–1).
* If **ConfigIntraResidUnsigned** is 1, spatial-domain blocks for intra macroblocks are sent as 8-bit unsigned integer values relative to a constant reference value of 0.

If **ConfigResidDiffHost** is 1 and **ConfigSpatialResid8** is 0, the host will send residual difference spatial-domain blocks of data for non-intra macroblocks using 16-bit signed samples and for intra macroblocks in predicted (non-intra) pictures in a format that depends on the value of **ConfigIntraResidUnsigned**:

* If **ConfigIntraResidUnsigned** is 0, spatial domain blocks for intra macroblocks are sent as 16-bit signed integer values relative to a constant reference value of 2^(BPP–1).
* If **ConfigIntraResidUnsigned** is 1, spatial domain blocks for intra macroblocks are sent as 16-bit unsigned integer values relative to a constant reference value of 0.

If **ConfigResidDiffHost** is 0, **ConfigSpatialResid8** must be 0.

For intra pictures, spatial-domain blocks must be sent using 8-bit samples if bits-per-pixel (BPP) is 8, and using 16-bit samples if BPP > 8. If **ConfigIntraResidUnsigned** is 0, these samples are sent as signed integer values relative to a constant reference value of 2^(BPP–1), and if **ConfigIntraResidUnsigned** is 1, these samples are sent as unsigned integer values relative to a constant reference value of 0.

### `ConfigResid8Subtraction`

If the value is 1, 8-bit difference overflow blocks are subtracted rather than added. The value must be 0 unless **ConfigSpatialResid8** is 1.

The ability to subtract differences rather than add them enables 8-bit difference decoding to be fully compliant with the full ±255 range of values required in video decoder specifications, because +255 cannot be represented as the addition of two signed 8-bit numbers, but any number in the range ±255 can be represented as the difference between two signed 8-bit numbers (+255 = +127 minus –128).

### `ConfigSpatialHost8or9Clipping`

If the value is 1, spatial-domain blocks for intra macroblocks must be clipped to an 8-bit range on the host and spatial-domain blocks for non-intra macroblocks must be clipped to a 9-bit range on the host. If the value is 0, no such clipping is necessary by the host.

The value must be 0 unless **ConfigSpatialResid8** is 0 and **ConfigResidDiffHost** is 1.

### `ConfigSpatialResidInterleaved`

If the value is 1, any spatial-domain residual difference data must be sent in a chrominance-interleaved form matching the YUV format chrominance interleaving pattern. The value must be 0 unless **ConfigResidDiffHost** is 1 and the YUV format is NV12 or NV21.

### `ConfigIntraResidUnsigned`

Indicates the method of representation of spatial-domain blocks of residual difference data for intra blocks when using host-based difference decoding.

If **ConfigResidDiffHost** is 1 and **ConfigIntraResidUnsigned** is 0, spatial-domain residual difference data blocks for intra macroblocks must be sent as follows:

* In a non-intra picture, if **ConfigSpatialResid8** is 0, the spatial-domain residual difference data blocks for intra macroblocks are sent as 16-bit signed integer values relative to a constant reference value of 2^(BPP–1).
* In a non-intra picture, if **ConfigSpatialResid8** is 1, the spatial-domain residual difference data blocks for intra macroblocks are sent as 8-bit signed integer values relative to a constant reference value of 2^(BPP–1).
* In an intra picture, if BPP is 8, the spatial-domain residual difference data blocks for intra macroblocks are sent as 8-bit signed integer values relative to a constant reference value of 2^(BPP–1), regardless of the value of **ConfigSpatialResid8**.

If **ConfigResidDiffHost** is 1 and **ConfigIntraResidUnsigned** is 1, spatial-domain residual difference data blocks for intra macroblocks must be sent as follows:

* In a non-intra picture, if **ConfigSpatialResid8** is 0, the spatial-domain residual difference data blocks for intra macroblocks must be sent as 16-bit unsigned integer values relative to a constant reference value of 0.
* In a non-intra picture, if **ConfigSpatialResid8** is 1, the spatial-domain residual difference data blocks for intra macroblocks are sent as 8-bit unsigned integer values relative to a constant reference value of 0.
* In an intra picture, if BPP is 8, the spatial-domain residual difference data blocks for intra macroblocks are sent as 8-bit unsigned integer values relative to a constant reference value of 0, regardless of the value of **ConfigSpatialResid8**.

The value of the member must be 0 unless **ConfigResidDiffHost** is 1.

### `ConfigResidDiffAccelerator`

If the value is 1, transform-domain blocks of coefficient data may be sent from the host for accelerator-based IDCT. If the value is 0, accelerator-based IDCT will not be used. If both **ConfigResidDiffHost** and **ConfigResidDiffAccelerator** are 1, this indicates that some residual difference decoding will be done on the host and some on the accelerator, as indicated by macroblock-level control commands.

The value must be 0 if **ConfigBitstreamRaw** is 1.

### `ConfigHostInverseScan`

If the value is 1, the inverse scan for transform-domain block processing will be performed on the host, and absolute indices will be sent instead for any transform coefficients. If the value is 0, the inverse scan will be performed on the accelerator.

The value must be 0 if **ConfigResidDiffAccelerator** is 0 or if **Config4GroupedCoefs** is 1.

### `ConfigSpecificIDCT`

If the value is 1, the IDCT specified in Annex W of ITU-T Recommendation H.263 is used. If the value is 0, any compliant IDCT can be used for off-host IDCT.

The H.263 annex does not comply with the IDCT requirements of MPEG-2 corrigendum 2, so the value must not be 1 for use with MPEG-2 video.

The value must be 0 if **ConfigResidDiffAccelerator** is 0, indicating purely host-based residual difference decoding.

### `Config4GroupedCoefs`

If the value is 1, transform coefficients for off-host IDCT will be sent using the [DXVA_TCoef4Group](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/dxva/ns-dxva-_dxva_tcoef4group) structure. If the value is 0, the [DXVA_TCoefSingle](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/dxva/ns-dxva-_dxva_tcoefsingle) structure is used. The value must be 0 if **ConfigResidDiffAccelerator** is 0 or if **ConfigHostInverseScan** is 1.

### `ConfigMinRenderTargetBuffCount`

Specifies how many frames the decoder device processes at any one time.

### `ConfigDecoderSpecific`

Contains decoder-specific configuration information.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)