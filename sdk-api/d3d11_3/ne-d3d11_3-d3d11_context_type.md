# D3D11_CONTEXT_TYPE enumeration

## Description

Specifies the context in which a query occurs.

## Constants

### `D3D11_CONTEXT_TYPE_ALL:0`

The query can occur in all contexts.

### `D3D11_CONTEXT_TYPE_3D:1`

The query occurs in the context of a 3D command queue.

### `D3D11_CONTEXT_TYPE_COMPUTE:2`

The query occurs in the context of a 3D compute queue.

### `D3D11_CONTEXT_TYPE_COPY:3`

The query occurs in the context of a 3D copy queue.

### `D3D11_CONTEXT_TYPE_VIDEO:4`

The query occurs in the context of video.

## Remarks

This enum is used by the following:

* [D3D11_QUERY_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_query_desc1) structure
* A CD3D11_QUERY_DESC1 constructor.
* [ID3D11DeviceContext3::Flush1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11devicecontext3-flush1) method

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)

[D3D11_QUERY_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_query_desc1)