# ID3D12Device::CreateRootSignature

## Description

Creates a root signature layout.

## Parameters

### `nodeMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

For single GPU operation, set this to zero. If there are multiple GPU nodes, set bits to identify the nodes (the device's physical adapters) to which the root signature is to apply.
Each bit in the mask corresponds to a single node.
Refer to [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `pBlobWithRootSignature` [in]

Type: **const [void](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)***

A pointer to the source data for the serialized signature.

### `blobLengthInBytes` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The size, in bytes, of the block of memory that *pBlobWithRootSignature* points to.

### `riid`

Type: ****REFIID****

The globally unique identifier (**GUID**) for the root signature interface. See Remarks.
An input parameter.

### `ppvRootSignature` [out]

Type: ****void******

A pointer to a memory block that receives a pointer to the root signature.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues).

This method returns **E_INVALIDARG** if the blob that *pBlobWithRootSignature* points to is invalid.

## Remarks

If an application procedurally generates a [D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_root_signature_desc) data structure, it must pass a pointer to this **D3D12_ROOT_SIGNATURE_DESC** in a call to [D3D12SerializeRootSignature](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-d3d12serializerootsignature) to make the serialized form.
The application then passes the serialized form to *pBlobWithRootSignature* in a call to **ID3D12Device::CreateRootSignature**.

The **REFIID**, or **GUID**, of the interface to the root signature layout can be obtained by using the __uuidof() macro.
For example, __uuidof([ID3D12RootSignature](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12rootsignature)) will get the **GUID** of the interface to a root signature.

#### Examples

The [D3D12HelloTriangle](https://learn.microsoft.com/windows/win32/direct3d12/working-samples) sample uses **ID3D12Device::CreateRootSignature** as follows:

Create an empty root signature.

```cpp
CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
rootSignatureDesc.Init(0, nullptr, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

ComPtr<ID3DBlob> signature;
ComPtr<ID3DBlob> error;
ThrowIfFailed(D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error));
ThrowIfFailed(m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature)));

```

## See also

[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)