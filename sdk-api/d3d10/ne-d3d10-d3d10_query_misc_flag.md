# D3D10_QUERY_MISC_FLAG enumeration

## Description

Flags that describe miscellaneous query behavior.

## Constants

### `D3D10_QUERY_MISC_PREDICATEHINT:0x1`

Tell the hardware that if it is not yet sure if something is hidden or not to draw it anyway. This is only used with an occlusion predicate. Predication data cannot be returned to your application via [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata) when using this flag.

## Remarks

This flag is part of a query description (see [D3D10_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_query_desc)).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)