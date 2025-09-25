# D3D11_QUERY_DATA_SO_STATISTICS structure

## Description

Query information about the amount of data streamed out to the stream-output buffers in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end).

## Members

### `NumPrimitivesWritten`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives (that is, points, lines, and triangles) written to the stream-output buffers.

### `PrimitivesStorageNeeded`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives that would have been written to the stream-output buffers if there had been enough space for them all.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)