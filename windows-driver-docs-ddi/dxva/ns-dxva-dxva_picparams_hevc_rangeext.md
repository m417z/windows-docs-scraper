## Description

The **DXVA_PicParams_HEVC_RangeExt** structure provides the picture-level parameters of a compressed picture for HEVC video decoding.

## Members

### `params`

### `transform_skip_rotation_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `transform_skip_context_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `implicit_rdpcm_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `explicit_rdpcm_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `extended_precision_processing_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `intra_smoothing_disabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `persistent_rice_adaptation_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `high_precision_offsets_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `cabac_bypass_alignment_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `cross_component_prediction_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `chroma_qp_offset_list_enabled_flag`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `ReservedBits8`

Reserved bit field.

### `dwRangeExtensionFlags`

Range extension flags.

### `diff_cu_chroma_qp_offset_depth`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly. When the **chroma_qp_offset_list_enabled_flag** is 0, this value will be 0.

### `log2_sao_offset_scale_luma`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `log2_sao_offset_scale_chroma`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `log2_max_transform_skip_block_size_minus2`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `cb_qp_offset_list[6]`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly. When the **chroma_qp_offset_list_enabled_flag** is 0, this value will be 0.

### `cr_qp_offset_list[6]`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly. When the **chroma_qp_offset_list_enabled_flag** is 0, this value will be 0.

### `chroma_qp_offset_list_len_minus1`

Corresponds to the syntax element of the same name in the HEVC specification and affects the decoding process accordingly.

### `ReservedBits9`

Reserved.

## Remarks

This structure is used when bDXVA_Func is 1 and the buffer type is DXVA2_PictureParametersBufferType (in DXVA 2.0). Note that **DXVA_PicParams_HEVC_RangeExt** is strictly an addition to [**DXVA_PicParams_HEVC**](https://learn.microsoft.com/windows/win32/medfound/dxva-picparams-hevc); the first part of each structure is identical. For the existing profiles **DXVA_ModeHEVC_VLD_Main** and **DXVA_ModeHEVC_VLD_Main10** accelerators are free to ignore the extra bytes in **DXVA_PicParams_HEVC_RangeExt**.

## See also

[**DXVA_PicParams_HEVC**](https://learn.microsoft.com/windows/win32/medfound/dxva-picparams-hevc)