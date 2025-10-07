# CD3DX12_VIEW_INSTANCING_DESC structure

A helper structure to enable easy initialization of a [**D3DX12_VIEW_INSTANCING_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc) structure.

## Members

`CD3DX12_VIEW_INSTANCING_DESC`

Default constructor. Creates a new, uninitialized, instance of a **CD3DX12_VIEW_INSTANCING_DESC**.

`CD3DX12_VIEW_INSTANCING_DESC(const D3D12_VIEW_INSTANCING_DESC&)`

Constructor that creates a new instance of a **CD3DX12_VIEW_INSTANCING_DESC** initialized with the contents of a [**D3DX12_VIEW_INSTANCING_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc) structure.

`CD3DX12_VIEW_INSTANCING_DESC(CD3DX12_DEFAULT)`

Constructor that creates a new instance of a **CD3DX12_VIEW_INSTANCING_DESC** initialized with these values.

|Data member|value|
|-|-|
|ViewInstanceCount|0|
|pViewInstanceLocations|nullptr|
|Flags|D3D12_VIEW_INSTANCING_FLAG_NONE|

`CD3DX12_VIEW_INSTANCING_DESC(UINT, const D3D12_VIEW_INSTANCE_LOCATION*, D3D12_VIEW_INSTANCING_FLAGS)`

Constructor that creates a new instance of a **CD3DX12_VIEW_INSTANCING_DESC** initialized with the parameters passed to it.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header | [D3dx12.h](https://github.com/microsoft/DirectX-Headers/blob/main/include/directx/d3dx12.h) |

## See also

* [D3DX12_VIEW_INSTANCING_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc)
* [Helper structures for Direct3D 12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)