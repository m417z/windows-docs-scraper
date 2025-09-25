# D3D12_CLEAR_VALUE structure

## Description

Describes a value used to optimize clear operations for a particular resource.

## Members

### `Format`

Specifies one member of the [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enum.

The format of the commonly cleared color follows the same validation rules as a view/ descriptor creation. In general, the format of the clear color can be any format in the same typeless group that the resource format belongs to.

This *Format* must match the format of the view used during the clear operation. It indicates whether the *Color* or the *DepthStencil* member is valid and how to convert the values for usage with the resource.

### `Color`

Specifies a 4-entry array of float values, determining the RGBA value. The order of RGBA matches the order used with [ClearRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearrendertargetview).

### `DepthStencil`

Specifies one member of [D3D12_DEPTH_STENCIL_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_value). These values match the semantics of *Depth* and *Stencil* in [ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-cleardepthstencilview).

## Remarks

This structure is optionally passed into the following methods:

* [ID3D12Device::CreateCommittedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommittedresource)
* [ID3D12Device::CreatePlacedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createplacedresource)
* [ID3D12Device::CreateReservedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createreservedresource)

## See also

[CD3DX12_CLEAR_VALUE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-clear-value)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)