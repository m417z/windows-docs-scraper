# D3D10_QUERY_DATA_SO_STATISTICS structure

## Description

Query information about the amount of data streamed out to the stream-output buffers in between [ID3D10Asynchronous::Begin](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-begin) and [ID3D10Asynchronous::End](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-end).

## Members

### `NumPrimitivesWritten`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives (that is, points, lines, and triangles) written to the stream-output buffers.

### `PrimitivesStorageNeeded`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives that would have been written to the stream-output buffers if there had been enough space for them all.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)