# D3D10_QUERY_DATA_TIMESTAMP_DISJOINT structure

## Description

Query information about the reliability of a timestamp query.

## Members

### `Frequency`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

How frequently the GPU counter increments in Hz.

### `Disjoint`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this is **TRUE**, something occurred in between the query's [ID3D10Asynchronous::Begin](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-begin) and [ID3D10Asynchronous::End](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-end) calls that caused the timestamp counter to become discontinuous or disjoint, such as unplugging the AC chord on a laptop, overheating, or throttling up/down due to laptop savings events. The timestamp returned by [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata) for a timestamp query is only reliable if Disjoint is **FALSE**.

## Remarks

For a list of query types see [D3D10_QUERY](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_query).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)