# D3D12CreateRootSignatureDeserializer function

## Description

Deserializes a root signature so you can determine the layout definition ([D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc)).

## Parameters

### `pSrcData` [in]

Type: **LPCVOID**

A pointer to the source data for the serialized root signature.

### `SrcDataSizeInBytes` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the block of memory that *pSrcData* points to.

### `pRootSignatureDeserializerInterface` [in]

Type: ****REFIID****

The globally unique identifier (**GUID**) for the root signature deserializer interface. See remarks.

### `ppRootSignatureDeserializer` [out]

Type: ****void******

A pointer to a memory block that receives a pointer to the root signature deserializer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This function has been superceded by [D3D12CreateVersionedRootSignatureDeserializer](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-d3d12createversionedrootsignaturedeserializer).

If an application has a serialized root signature already or has a compiled shader that contains a root signature and wants to determine the layout definition, it can call **D3D12CreateRootSignatureDeserializer** to generate a [ID3D12RootSignatureDeserializer](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12rootsignaturedeserializer) interface. [ID3D12RootSignatureDeserializer::GetRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12rootsignaturedeserializer-getrootsignaturedesc) can return the deserialized data structure
([D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc)).
**ID3D12RootSignatureDeserializer** just owns the lifetime of the memory for the deserialized data structure.

The **REFIID**, or **GUID**, of the interface to the root signature deserializer can be obtained by using the __uuidof() macro. For example, __uuidof([ID3D12RootSignatureDeserializer](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12rootsignaturedeserializer)) will get the **GUID** of the interface to a root signature deserializer.

The function signature PFN_D3D12_CREATE_ROOT_SIGNATURE_DESERIALIZER is provided as a typedef, so that you can use dynamic linking techniques ([GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)) instead of statically linking.

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-functions)

[Creating a Root Signature](https://learn.microsoft.com/windows/desktop/direct3d12/creating-a-root-signature)