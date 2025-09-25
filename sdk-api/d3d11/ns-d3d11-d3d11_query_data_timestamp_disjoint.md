# D3D11_QUERY_DATA_TIMESTAMP_DISJOINT structure

## Description

Query information about the reliability of a timestamp query.

## Members

### `Frequency`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

How frequently the GPU counter increments in Hz.

### `Disjoint`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this is **TRUE**, something occurred in between the query's [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end) calls that caused the timestamp counter to become discontinuous or disjoint, such as unplugging the AC cord on a laptop, overheating, or throttling up/down due to laptop savings events. The timestamp returned by [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) for a timestamp query is only reliable if **Disjoint** is **FALSE**.

## Remarks

For a list of query types see [D3D11_QUERY](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_query).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)