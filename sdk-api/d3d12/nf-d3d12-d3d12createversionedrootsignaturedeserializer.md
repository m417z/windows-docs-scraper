# D3D12CreateVersionedRootSignatureDeserializer function

## Description

Generates an interface that can return the deserialized data structure, via [GetUnconvertedRootSignatureDesc](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12versionedrootsignaturedeserializer-getunconvertedrootsignaturedesc).

## Parameters

### `pSrcData` [in]

Type: **LPCVOID**

A pointer to the source data for the serialized root signature.

### `SrcDataSizeInBytes` [in]

Type: **SIZE_T**

The size, in bytes, of the block of memory that *pSrcData* points to.

### `pRootSignatureDeserializerInterface` [in]

Type: **REFIID**

The globally unique identifier (**GUID**) for the root signature deserializer interface. See remarks.

### `ppRootSignatureDeserializer` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the root signature deserializer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

If an application has a serialized root signature already or has a compiled shader that contains a root signature and wants to determine the layout definition, it can call **D3D12CreateVersionedRootSignatureDeserializer** to generate a [ID3D12VersionedRootSignatureDeserializer](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12versionedrootsignaturedeserializer) interface. [ID3D12VersionedRootSignatureDeserializer::GetRootSignatureDescAtVersion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12versionedrootsignaturedeserializer-getrootsignaturedescatversion) can return the deserialized data structure
([D3D12_ROOT_SIGNATURE_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc1)).
**ID3D12VersionedRootSignatureDeserializer** just owns the lifetime of the memory for the deserialized data structure.

The **REFIID**, or **GUID**, of the interface to the root signature deserializer can be obtained by using the __uuidof() macro. For example, __uuidof([ID3D12VersionedRootSignatureDeserializer](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12versionedrootsignaturedeserializer)) will get the **GUID** of the interface to a root signature deserializer.

The function signature PFN_D3D12_CREATE_ROOT_SIGNATURE_DESERIALIZER is provided as a typedef, so that you can use dynamic linking techniques ([GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)) instead of statically linking.

This function supercedes [D3D12CreateRootSignatureDeserializer](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-d3d12createrootsignaturedeserializer).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-functions)

[Creating a Root Signature](https://learn.microsoft.com/windows/desktop/direct3d12/creating-a-root-signature)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)