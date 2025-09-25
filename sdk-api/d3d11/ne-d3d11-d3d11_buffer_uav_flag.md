# D3D11_BUFFER_UAV_FLAG enumeration

## Description

Identifies unordered-access view options for a buffer resource.

## Constants

### `D3D11_BUFFER_UAV_FLAG_RAW:0x1`

Resource contains raw, unstructured data. Requires the UAV format to be DXGI_FORMAT_R32_TYPELESS.
For more info about raw viewing of buffers, see [Raw Views of Buffers](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

### `D3D11_BUFFER_UAV_FLAG_APPEND:0x2`

Allow data to be appended to the end of the buffer. **D3D11_BUFFER_UAV_FLAG_APPEND** flag must also be used for
any view that will be used as a [AppendStructuredBuffer](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-appendstructuredbuffer) or a [ConsumeStructuredBuffer](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-consumestructuredbuffer).
Requires the UAV format to be DXGI_FORMAT_UNKNOWN.

### `D3D11_BUFFER_UAV_FLAG_COUNTER:0x4`

Adds a counter to the unordered-access-view buffer. **D3D11_BUFFER_UAV_FLAG_COUNTER** can only be used on a UAV that is a
[RWStructuredBuffer](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-rwstructuredbuffer) and it enables the functionality needed for the [IncrementCounter](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-rwstructuredbuffer-incrementcounter) and [DecrementCounter](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-rwstructuredbuffer-decrementcounter) methods in HLSL. Requires the UAV format to be DXGI_FORMAT_UNKNOWN.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)