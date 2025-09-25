# D3D12SerializeRootSignature function

## Description

Serializes a root signature version 1.0 that can be passed to [ID3D12Device::CreateRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrootsignature).

## Parameters

### `pRootSignature` [in]

Type: **const [D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc)***

The description of the root signature, as a pointer to a [D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc) structure.

### `Version` [in]

Type: **[D3D_ROOT_SIGNATURE_VERSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d_root_signature_version)**

A [D3D_ROOT_SIGNATURE_VERSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d_root_signature_version)-typed value that specifies the version of root signature.

### `ppBlob` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a memory block that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access the serialized root signature.

### `ppErrorBlob` [out, optional]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a memory block that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access serializer error messages, or **NULL** if there are no errors.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This function has been superceded by [D3D12SerializeVersionedRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-d3d12serializeversionedrootsignature) as of the Windows 10 Anniversary Update (14393).

If an application procedurally generates a [D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc) data structure, it must pass a pointer to this **D3D12_ROOT_SIGNATURE_DESC** in a call to **D3D12SerializeRootSignature** to make the serialized form.
The application then passes the serialized form to which *ppBlob* points into [ID3D12Device::CreateRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrootsignature).

If a shader has been authored with a root signature in it, the compiled shader will contain a serialized root signature in it already. In this case, pass the compiled shader blob to [ID3D12Device::CreateRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrootsignature) to obtain the runtime root signature object.

The function signature PFN_D3D12_SERIALIZE_ROOT_SIGNATURE is provided as a typedef, so that you can use dynamic linking techniques ([GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)) instead of statically linking.

#### Examples

Create an empty root signature.

```cpp
CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
rootSignatureDesc.Init(0, nullptr, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

ComPtr<ID3DBlob> signature;
ComPtr<ID3DBlob> error;
ThrowIfFailed(D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error));
ThrowIfFailed(m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature)));

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-functions)

[Creating a Root Signature](https://learn.microsoft.com/windows/desktop/direct3d12/creating-a-root-signature)