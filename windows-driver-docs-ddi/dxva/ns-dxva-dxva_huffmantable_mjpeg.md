## Description

The **DXVA_HuffmanTable_MJPEG** structure provides the Huffman table of a compressed picture for MJPEG video decoding.

## Members

### `bits_ac[4]`

The **bits_ac[j][i]** member specifies the number of Huffman codes of length *i* for Huffman table slot *j* for AC class tables. This value is the same as the L*i* parameter of the DHT marker from the specification.

### `table_ac[4]`

The **table_ac[j][i]** member specifies the value associated with each Huffman code *j* for Huffman table slot I for AC class tables. This corresponds to the V*i,j* parameter from the DHT marker of the specification.

### `bits_dc[4]`

The **bits_dc[j][i]** member specifies the number of Huffman codes of length *i* for Huffman table slot *j* for DC class tables. This value is the same as the L*i* parameter of the DHT marker from the specification.

### `table_dc[4]`

The **table_dc[j][i]** member specifies the value associated with each Huffman code *j* for Huffman table slot I for DC class tables. This corresponds to the V*i,j* parameter from the DHT marker of the specification.

## Remarks

This structure is used for MJPEG video coding when the buffer type is [**D3D12_VIDEO_DECODE_ARGUMENT_TYPE_HUFFMAN_TABLE**](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_argument_type) in D3D12 and [**D3D11_VIDEO_DECODER_BUFFER_HUFFMAN_TABLE**](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_video_decoder_buffer_type) in D3D11.

If **DXVA_HuffmanTable_MJPEG** is left unspecified by the host, the accelerator shall use the default quantization table as specified in Annex K of the JPEG specification.

## See also

[**D3D12_VIDEO_DECODE_ARGUMENT_TYPE**](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_argument_type)

[**D3D11_VIDEO_DECODER_BUFFER_TYPE**](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_video_decoder_buffer_type)