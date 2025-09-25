# D3D12SerializeVersionedRootSignature function

## Description

Serializes a root signature of any version that can be passed to [ID3D12Device::CreateRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrootsignature).

## Parameters

### `pRootSignature` [in]

Type: **const [D3D12_VERSIONED_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc)***

Specifies a [D3D12_VERSIONED_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc) that contains a description of any version of a root signature.

### `ppBlob` [out]

Type: **ID3DBlob****

A pointer to a memory block that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access the serialized root signature.

### `ppErrorBlob` [out, optional]

Type: **ID3DBlob****

A pointer to a memory block that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access serializer error messages, or **NULL** if there are no errors.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

If an application procedurally generates a [D3D12_ROOT_SIGNATURE_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc1) data structure, it must pass a pointer to this **D3D12_ROOT_SIGNATURE_DESC1** in a call to **D3D12SerializeVersionedRootSignature** to make the serialized form.
The application then passes the serialized form to which *ppBlob* points into [ID3D12Device::CreateRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrootsignature).

If a shader has been authored with a root signature in it, the compiled shader will contain a serialized root signature in it already. In this case, pass the compiled shader blob to [ID3D12Device::CreateRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrootsignature) to obtain the runtime root signature object.

> Note that for Xbox developers, use of HLSL-authored root signatures is strongly recommended.

The function signature PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE is provided as a typedef, so that you can use dynamic linking techniques ([GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)) instead of statically linking.

This function was released with the Windows 10 Anniversary Update (14393) and supersedes [D3D12SerializeRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-d3d12serializerootsignature).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-functions)

[Creating a Root Signature](https://learn.microsoft.com/windows/desktop/direct3d12/creating-a-root-signature)

[D3DX12SerializeVersionedRootSignature](https://learn.microsoft.com/windows/desktop/direct3d12/d3dx12serializeversionedrootsignature)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)