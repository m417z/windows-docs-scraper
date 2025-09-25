## Description

The **DXVA_QMatrix_MJPEG** structure provides the quantization table of a compressed picture for MJPEG video decoding.

## Members

### `quantvals[4]`

Array for each quantization table slot *i*, containing an array of 64 entries *j*. Each entry *i* specifies 64 entries *j*, where each is a quantization step parameter for each coefficient. This array is filled directly from the DQT marker of the input MJPEG bitstream. The order of entries is the same as defined in the standard JPEG DQT marker: zig-zag scan order. All values are stored in 16-bit WORDs even if the table only specifies 8-bit values (Pq = 0). If a quantization table is not present all entries will be initialized to zero. The exact quantization table used for a particular component of a picture shall be read from the picture parameters structure field: quantizationTableSelector.

## Remarks

This structure is used for MJPEG video coding when the buffer type is [**D3D12_VIDEO_DECODE_ARGUMENT_TYPE_INVERSE_QUANTIZATION_MATRIX**](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_argument_type) in D3D12 and [**D3D11_VIDEO_DECODER_BUFFER_INVERSE_QUANTIZATION_MATRIX**](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_video_decoder_buffer_type) in D3D11.

If **DXVA_QMatrix_MJPEG** is left unspecified by the host, the accelerator shall use the default quantization table as specified in Annex K of the JPEG specification.

## See also

[**D3D12_VIDEO_DECODE_ARGUMENT_TYPE**](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_argument_type)

[**D3D11_VIDEO_DECODER_BUFFER_TYPE**](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_video_decoder_buffer_type)