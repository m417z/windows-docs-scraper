# CD3DX12\_RESOURCE\_DESC structure

A helper structure to enable easy initialization of a [**D3D12\_RESOURCE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_desc) structure.

## Members

**CD3DX12\_RESOURCE\_DESC()**

Creates a new, uninitialized, instance of a CD3DX12\_RESOURCE\_DESC.

**explicit CD3DX12\_RESOURCE\_DESC(const D3D12\_RESOURCE\_DESC& o)**

Creates a new instance of a CD3DX12\_RESOURCE\_DESC, initialized with the contents of another [**D3D12\_RESOURCE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_desc) structure.

**CD3DX12\_RESOURCE\_DESC(D3D12\_RESOURCE\_DIMENSION dimension, UINT64 alignment, UINT64 width, UINT height, UINT16 depthOrArraySize, UINT16 mipLevels, DXGI\_FORMAT format, UINT sampleCount, UINT sampleQuality, D3D12\_TEXTURE\_LAYOUT layout, D3D12\_RESOURCE\_FLAGS flags)**

Creates a new instance of a CD3DX12\_RESOURCE\_DESC, initializing the following parameters:

[**D3D12\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_dimension) dimension

UINT64 alignment

UINT64 width

UINT height

UINT16 depthOrArraySize

UINT16 mipLevels

[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) format

UINT sampleCount

UINT sampleQuality

[**D3D12\_TEXTURE\_LAYOUT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout) layout

[**D3D12\_RESOURCE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flags

**static inline Buffer(const D3D12\_RESOURCE\_ALLOCATION\_INFO& resAllocInfo, D3D12\_RESOURCE\_FLAGS flags = D3D12\_RESOURCE\_FLAG\_NONE)**

Specifies a function that initializes the following parameters:

[**D3D12\_RESOURCE\_ALLOCATION\_INFO**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_allocation_info)& resAllocInfo

(opt) [**D3D12\_RESOURCE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flags = D3D12\_RESOURCE\_FLAG\_NONE

**static inline Buffer(UINT64 width, D3D12\_RESOURCE\_FLAGS flags = D3D12\_RESOURCE\_FLAG\_NONE, UINT64 alignment = 0)**

Specifies a function that initializes the following parameters:

UINT64 width

(opt) [**D3D12\_RESOURCE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flags = D3D12\_RESOURCE\_FLAG\_NONE

(opt) UINT64 alignment = 0

**static inline Tex1D(DXGI\_FORMAT format, UINT64 width, UINT16 arraySize = 1, UINT16 mipLevels = 0, D3D12\_RESOURCE\_FLAGS flags = D3D12\_RESOURCE\_FLAG\_NONE, D3D12\_TEXTURE\_LAYOUT layout = D3D12\_TEXTURE\_LAYOUT\_UNKNOWN, UINT64 alignment = 0)**

Specifies a function that initializes the following parameters:

[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) format

UINT64 width

(opt) UINT16 arraySize = 1

(opt) UINT16 mipLevels = 0

(opt) [**D3D12\_RESOURCE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flags = D3D12\_RESOURCE\_FLAG\_NONE

(opt) [**D3D12\_TEXTURE\_LAYOUT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout) layout = D3D12\_TEXTURE\_LAYOUT\_UNKNOWN

(opt) UINT64 alignment = 0

**static inline Tex2D(DXGI\_FORMAT format, UINT64 width, UINT height, UINT16 arraySize = 1, UINT16 mipLevels = 0, UINT sampleCount = 1, UINT sampleQuality = 0, D3D12\_RESOURCE\_FLAGS flags = D3D12\_RESOURCE\_FLAG\_NONE, D3D12\_TEXTURE\_LAYOUT layout = D3D12\_TEXTURE\_LAYOUT\_UNKNOWN, UINT64 alignment = 0)**

Specifies a function that initializes the following parameters:

[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) format

UINT64 width

UINT height

(opt) UINT16 arraySize = 1

(opt) UINT16 mipLevels = 0

(opt) UINT sampleCount = 1

(opt) UINT sampleQuality = 0

(opt) [**D3D12\_RESOURCE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flags = D3D12\_RESOURCE\_FLAG\_NONE

(opt) [**D3D12\_TEXTURE\_LAYOUT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout) layout = D3D12\_TEXTURE\_LAYOUT\_UNKNOWN

(opt) UINT64 alignment = 0

**static inline Tex3D(DXGI\_FORMAT format, UINT64 width, UINT height, UINT16 depth, UINT16 mipLevels = 0, D3D12\_RESOURCE\_FLAGS flags = D3D12\_RESOURCE\_FLAG\_NONE, D3D12\_TEXTURE\_LAYOUT layout = D3D12\_TEXTURE\_LAYOUT\_UNKNOWN, UINT64 alignment = 0)**

Specifies a function that initializes the following parameters:

[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) format

UINT64 width

UINT height

UINT16 depth

(opt) UINT16 mipLevels = 0

(opt) [**D3D12\_RESOURCE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flags = D3D12\_RESOURCE\_FLAG\_NONE

(opt) [**D3D12\_TEXTURE\_LAYOUT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout) layout = D3D12\_TEXTURE\_LAYOUT\_UNKNOWN

(opt) UINT64 alignment = 0

**inline Depth() const**

If Dimension == [**D3D12\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_dimension)\_TEXTURE3D, returns DepthOrArraySize. If Dimension != D3D12\_RESOURCE\_DIMENSION\_TEXTURE3D, returns 1.

**inline ArraySize() const**

If Dimension != D3D12\_RESOURCE\_DIMENSION\_TEXTURE3D, returns DepthOrArraySize. If Dimension == D3D12\_RESOURCE\_DIMENSION\_TEXTURE3D, returns 1. See [**D3D12\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_dimension)\_TEXTURE3D.

**inline PlaneCount(ID3D12Device\* pDevice) const**

Returns D3D12GetFormatPlaneCount(pDevice, Format). See [**D3D12GetFormatPlaneCount**](https://learn.microsoft.com/windows/win32/direct3d12/d3d12getformatplanecount) and [**ID3D12Device**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device).

**inline Subresources(ID3D12Device\* pDevice) const**

Returns the number of subresources, calculated as MipLevels \* ArraySize() \* PlaneCount(pDevice).

**inline CalcSubresource(UINT MipSlice, UINT ArraySlice, UINT PlaneSlice)**

Calculates a subresource index, by using [**D3D12CalcSubresource**](https://learn.microsoft.com/windows/win32/direct3d12/d3d12calcsubresource).

**operator const D3D12\_RESOURCE\_DESC&() const**

Defines the & pass-by-reference operator for the parent structure type.

**operator == (const D3D12\_RESOURCE\_DESC& l, const D3D12\_RESOURCE\_DESC& r)**

Returns true if all members of each structure are identical.

**operator != (const D3D12\_RESOURCE\_DESC& l, const D3D12\_RESOURCE\_DESC& r)**

Returns false if all members of each structure are identical.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_RESOURCE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_desc)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

