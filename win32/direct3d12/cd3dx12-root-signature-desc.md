# CD3DX12\_ROOT\_SIGNATURE\_DESC structure

A helper structure to enable easy initialization of a [**D3D12\_ROOT\_SIGNATURE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc) structure.

## Members

**CD3DX12\_ROOT\_SIGNATURE\_DESC()**

Creates a new, uninitialized, instance of a CD3DX12\_ROOT\_SIGNATURE\_DESC.

**explicit CD3DX12\_ROOT\_SIGNATURE\_DESC(const D3D12\_ROOT\_SIGNATURE\_DESC &o)**

Creates a new instance of a CD3DX12\_ROOT\_SIGNATURE\_DESC, initialized with the contents of another [**D3D12\_ROOT\_SIGNATURE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc) structure.

**CD3DX12\_ROOT\_SIGNATURE\_DESC(UINT numParameters, const D3D12\_ROOT\_PARAMETER\* \_pParameters, UINT numStaticSamplers = 0, const D3D12\_STATIC\_SAMPLER\_DESC\* \_pStaticSamplers = NULL, D3D12\_ROOT\_SIGNATURE\_FLAGS flags = D3D12\_ROOT\_SIGNATURE\_FLAG\_NONE)**

Creates a new instance of a CD3DX12\_ROOT\_SIGNATURE\_DESC, initializing the following parameters:

UINT numParameters

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter)\* \_pParameters

(opt) UINT numStaticSamplers = 0

(opt) [**D3D12\_STATIC\_SAMPLER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc)\* \_pStaticSamplers = NULL

(opt) [**D3D12\_ROOT\_SIGNATURE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_signature_flags) flags = D3D12\_ROOT\_SIGNATURE\_FLAG\_NONE

**CD3DX12\_ROOT\_SIGNATURE\_DESC(CD3DX12\_DEFAULT)**

Creates a new instance of a CD3DX12\_ROOT\_SIGNATURE\_DESC, initialized with default parameters.

``` syntax
CD3DX12_ROOT_SIGNATURE_DESC(0,NULL,0,NULL,D3D12_ROOT_SIGNATURE_FLAG_NONE)
```

**inline Init(UINT numParameters, const D3D12\_ROOT\_PARAMETER\* \_pParameters, UINT numStaticSamplers = 0, const D3D12\_STATIC\_SAMPLER\_DESC\* \_pStaticSamplers = NULL, D3D12\_ROOT\_SIGNATURE\_FLAGS flags = D3D12\_ROOT\_SIGNATURE\_FLAG\_NONE)**

Specifies a function that initializes the following parameters:

UINT numParameters

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter)\* \_pParameters

(opt) UINT numStaticSamplers = 0

(opt) [**D3D12\_STATIC\_SAMPLER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc)\* \_pStaticSamplers = NULL

(opt) [**D3D12\_ROOT\_SIGNATURE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_signature_flags) flags = D3D12\_ROOT\_SIGNATURE\_FLAG\_NONE

**static inline Init(D3D12\_ROOT\_SIGNATURE\_DESC &desc, UINT numParameters, const D3D12\_ROOT\_PARAMETER\* \_pParameters, UINT numStaticSamplers = 0, const D3D12\_STATIC\_SAMPLER\_DESC\* \_pStaticSamplers = NULL, D3D12\_ROOT\_SIGNATURE\_FLAGS flags = D3D12\_ROOT\_SIGNATURE\_FLAG\_NONE)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_SIGNATURE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc) &desc

UINT numParameters

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter)\* \_pParameters

(opt) UINT numStaticSamplers = 0

(opt) [**D3D12\_STATIC\_SAMPLER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc)\* \_pStaticSamplers = NULL

(opt) [**D3D12\_ROOT\_SIGNATURE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_signature_flags) flags = D3D12\_ROOT\_SIGNATURE\_FLAG\_NONE

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_ROOT\_SIGNATURE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

