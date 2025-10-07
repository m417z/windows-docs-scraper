# CD3DX12\_ROOT\_PARAMETER structure

A helper structure to enable easy initialization of a [**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) structure.

## Members

**CD3DX12\_ROOT\_PARAMETER()**

Creates a new, uninitialized, instance of a CD3DX12\_ROOT\_PARAMETER.

**explicit CD3DX12\_ROOT\_PARAMETER(const D3D12\_ROOT\_PARAMETER &o)**

Creates a new instance of a CD3DX12\_ROOT\_PARAMETER, initialized with the contents of another [**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) structure.

**static inline InitAsDescriptorTable(D3D12\_ROOT\_PARAMETER &rootParam, UINT numDescriptorRanges, const D3D12\_DESCRIPTOR\_RANGE\* pDescriptorRanges, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) &rootParam

UINT numDescriptorRanges

[**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range)\* pDescriptorRanges

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**static inline InitAsConstants(D3D12\_ROOT\_PARAMETER &rootParam, UINT num32BitValues, UINT shaderRegister, UINT registerSpace = 0, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) &rootParam

UINT num32BitValues

UINT shaderRegister

(opt) UINT registerSpace = 0

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**static inline InitAsConstantBufferView(D3D12\_ROOT\_PARAMETER &rootParam, UINT shaderRegister, UINT registerSpace = 0, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) &rootParam

UINT shaderRegister

(opt) UINT registerSpace = 0

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**static inline InitAsShaderResourceView(D3D12\_ROOT\_PARAMETER &rootParam, UINT shaderRegister, UINT registerSpace = 0, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) &rootParam

UINT shaderRegister

(opt) UINT registerSpace = 0

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**static inline InitAsUnorderedAccessView(D3D12\_ROOT\_PARAMETER &rootParam, UINT shaderRegister, UINT registerSpace = 0, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) &rootParam

UINT shaderRegister

(opt) UINT registerSpace = 0

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**inline InitAsDescriptorTable(UINT numDescriptorRanges, const D3D12\_DESCRIPTOR\_RANGE\* pDescriptorRanges, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

UINT numDescriptorRanges

[**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range)\* pDescriptorRanges

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**inline InitAsConstants(UINT num32BitValues, UINT shaderRegister, UINT registerSpace = 0, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

UINT num32BitValues

UINT shaderRegister

(opt) UINT registerSpace = 0

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**inline InitAsConstantBufferView(UINT shaderRegister, UINT registerSpace = 0, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

UINT shaderRegister

(opt) UINT registerSpace = 0

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**inline InitAsShaderResourceView(UINT shaderRegister, UINT registerSpace = 0, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

UINT shaderRegister

(opt) UINT registerSpace = 0

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

**inline InitAsUnorderedAccessView(UINT shaderRegister, UINT registerSpace = 0, D3D12\_SHADER\_VISIBILITY visibility = D3D12\_SHADER\_VISIBILITY\_ALL)**

Specifies a function that initializes the following parameters:

UINT shaderRegister

(opt) UINT registerSpace = 0

(opt) [**D3D12\_SHADER\_VISIBILITY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility) visibility = D3D12\_SHADER\_VISIBILITY\_ALL

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_ROOT\_PARAMETER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

