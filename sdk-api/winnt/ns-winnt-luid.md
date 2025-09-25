# LUID structure

## Description

Describes a local identifier for an adapter.

## Members

### `LowPart`

Specifies a DWORD that contains the unsigned lower numbers of the id.

### `HighPart`

Specifies a LONG that contains the signed high numbers of the id.

## Remarks

This structure is used by the [ID3D12Device::GetAdapterLuid](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getadapterluid) and [GetSharedResourceAdapterLuid](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-getsharedresourceadapterluid) methods.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)