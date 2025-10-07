# CD3DX12\_STATIC\_SAMPLER\_DESC structure

A helper structure to enable easy initialization of a [**D3D12\_STATIC\_SAMPLER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc) structure.

## Members

**CD3DX12\_STATIC\_SAMPLER\_DESC()**

Creates a new, uninitialized, instance of a CD3DX12\_STATIC\_SAMPLER\_DESC.

**explicit CD3DX12\_STATIC\_SAMPLER\_DESC(const D3D12\_STATIC\_SAMPLER\_DESC &o)**

Creates a new instance of a CD3DX12\_STATIC\_SAMPLER\_DESC, initialized with the contents of another [**D3D12\_STATIC\_SAMPLER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc) structure.

**CD3DX12\_STATIC\_SAMPLER\_DESC(UINT shaderRegister, D3D12\_FILTER filter = D3D12\_FILTER\_ANISOTROPIC, D3D12\_TEXTURE\_ADDRESS\_MODE addressU = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, D3D12\_TEXTURE\_ADDRESS\_MODE addressV = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, D3D12\_TEXTURE\_ADDRESS\_MODE addressW = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, FLOAT mipLODBias = 0, UINT maxAnisotropy = 16, D3D12\_COMPARISON\_FUNC comparisonFunc = D3D12\_COMPARISON\_FUNC\_LESS\_EQUAL, D3D12\_STATIC\_BORDER\_COLOR borderColor = D3D12\_STATIC\_BORDER\_COLOR\_OPAQUE\_WHITE, FLOAT minLOD = 0.f, FLOAT maxLOD = D3D12\_FLOAT32\_MAX, D3D12\_SHADER\_VISIBILITY shaderVisibility = D3D12\_SHADER\_VISIBILITY\_ALL, UINT registerSpace = 0)**

Creates a new instance of a CD3DX12\_STATIC\_SAMPLER\_DESC, initializing the following parameters:

UINT shaderRegister

(opt) [**D3D12\_FILTER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) filter = D3D12\_FILTER\_ANISOTROPIC

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressU = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressV = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressW = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) FLOAT mipLODBias = 0

(opt) UINT maxAnisotropy = 16

(opt) [**D3D12\_COMPARISON\_FUNC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func) comparisonFunc = D3D12\_COMPARISON\_FUNC\_LESS\_EQUAL

(opt) [**D3D12\_STATIC\_BORDER\_COLOR**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_static_border_color) borderColor = D3D12\_STATIC\_BORDER\_COLOR\_OPAQUE\_WHITE

(opt) FLOAT minLOD = 0.f

(opt) FLOAT maxLOD = D3D12\_FLOAT32\_MAX

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) shaderVisibility = D3D12\_SHADER\_VISIBILITY\_ALL

(opt) UINT registerSpace = 0

**static inline Init(D3D12\_STATIC\_SAMPLER\_DESC &samplerDesc, UINT shaderRegister, D3D12\_FILTER filter = D3D12\_FILTER\_ANISOTROPIC, D3D12\_TEXTURE\_ADDRESS\_MODE addressU = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, D3D12\_TEXTURE\_ADDRESS\_MODE addressV = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, D3D12\_TEXTURE\_ADDRESS\_MODE addressW = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, FLOAT mipLODBias = 0, UINT maxAnisotropy = 16, D3D12\_COMPARISON\_FUNC comparisonFunc = D3D12\_COMPARISON\_FUNC\_LESS\_EQUAL, D3D12\_STATIC\_BORDER\_COLOR borderColor = D3D12\_STATIC\_BORDER\_COLOR\_OPAQUE\_WHITE, FLOAT minLOD = 0.f, FLOAT maxLOD = D3D12\_FLOAT32\_MAX, D3D12\_SHADER\_VISIBILITY shaderVisibility = D3D12\_SHADER\_VISIBILITY\_ALL, UINT registerSpace = 0)**

Specifies a function that initializes the following parameters:

[**D3D12\_STATIC\_SAMPLER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc) &samplerDesc

UINT shaderRegister

(opt) [**D3D12\_FILTER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) filter = D3D12\_FILTER\_ANISOTROPIC

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressU = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressV = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressW = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) FLOAT mipLODBias = 0

(opt) UINT maxAnisotropy = 16

(opt) [**D3D12\_COMPARISON\_FUNC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func) comparisonFunc = D3D12\_COMPARISON\_FUNC\_LESS\_EQUAL

(opt) [**D3D12\_STATIC\_BORDER\_COLOR**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_static_border_color) borderColor = D3D12\_STATIC\_BORDER\_COLOR\_OPAQUE\_WHITE

(opt) FLOAT minLOD = 0.f

(opt) FLOAT maxLOD = D3D12\_FLOAT32\_MAX

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) shaderVisibility = D3D12\_SHADER\_VISIBILITY\_ALL

(opt) UINT registerSpace = 0

**inline Init(UINT shaderRegister, D3D12\_FILTER filter = D3D12\_FILTER\_ANISOTROPIC, D3D12\_TEXTURE\_ADDRESS\_MODE addressU = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, D3D12\_TEXTURE\_ADDRESS\_MODE addressV = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, D3D12\_TEXTURE\_ADDRESS\_MODE addressW = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP, FLOAT mipLODBias = 0, UINT maxAnisotropy = 16, D3D12\_COMPARISON\_FUNC comparisonFunc = D3D12\_COMPARISON\_FUNC\_LESS\_EQUAL, D3D12\_STATIC\_BORDER\_COLOR borderColor = D3D12\_STATIC\_BORDER\_COLOR\_OPAQUE\_WHITE, FLOAT minLOD = 0.f, FLOAT maxLOD = D3D12\_FLOAT32\_MAX, D3D12\_SHADER\_VISIBILITY shaderVisibility = D3D12\_SHADER\_VISIBILITY\_ALL, UINT registerSpace = 0)**

Specifies a function that initializes the following parameters:

UINT shaderRegister

(opt) [**D3D12\_FILTER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) filter = D3D12\_FILTER\_ANISOTROPIC

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressU = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressV = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) [**D3D12\_TEXTURE\_ADDRESS\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) addressW = D3D12\_TEXTURE\_ADDRESS\_MODE\_WRAP

(opt) FLOAT mipLODBias = 0

(opt) UINT maxAnisotropy = 16

(opt) [**D3D12\_COMPARISON\_FUNC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func) comparisonFunc = D3D12\_COMPARISON\_FUNC\_LESS\_EQUAL

(opt) [**D3D12\_STATIC\_BORDER\_COLOR**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_static_border_color) borderColor = D3D12\_STATIC\_BORDER\_COLOR\_OPAQUE\_WHITE

(opt) FLOAT minLOD = 0.f

(opt) FLOAT maxLOD = D3D12\_FLOAT32\_MAX

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) shaderVisibility = D3D12\_SHADER\_VISIBILITY\_ALL

(opt) UINT registerSpace = 0

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_STATIC\_SAMPLER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

