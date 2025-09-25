## Description

Encapsulates the compressed bitstream output for the encoding operation.

## Members

### `pBuffer`

A pointer to a [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) containing the compressed bitstream buffer. Note that the resource buffer size is not the available size for this encoding operation because *FrameStartOffset* needs to be taken into account against this size.

### `FrameStartOffset`

A UINT64 specifying th offset into the compressed bitstream where the encoder may start adding the current frame output.

## Remarks

The output bitstream is expected to contain the subregion headers, but not the picture, sequence, video or other headers. The host is responsible for coding those headers and generating the complete bitstream.

In subregion frame partitioning, all subregions for a given frame encoding operation output must be placed in top/down, left/right order and must be contiguous.

## See also