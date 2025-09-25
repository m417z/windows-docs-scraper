# D3D11_QUERY_MISC_FLAG enumeration

## Description

Flags that describe miscellaneous query behavior.

## Constants

### `D3D11_QUERY_MISC_PREDICATEHINT:0x1`

Tell the hardware that if it is not yet sure if something is hidden or not to draw it anyway. This is only used with an occlusion predicate. Predication data cannot be returned to your application via [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) when using this flag.

## Remarks

This flag is part of a query description (see [D3D11_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_desc)).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)