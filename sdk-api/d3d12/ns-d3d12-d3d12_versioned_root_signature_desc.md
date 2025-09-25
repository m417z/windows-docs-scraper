# D3D12_VERSIONED_ROOT_SIGNATURE_DESC structure

## Description

Holds any version of a root signature description, and is designed to be used with serialization/deserialization functions.

## Members

### `Version`

Specifies one member of D3D_ROOT_SIGNATURE_VERSION that determines the contents of the union.

### `Desc_1_0`

Specifies a [D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc) (version 1.0).

### `Desc_1_1`

Specifies a [D3D12_ROOT_SIGNATURE_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc1) (version 1.1).

## Remarks

Use this structure with the following methods.

* [GetRootSignatureDescAtVersion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12versionedrootsignaturedeserializer-getrootsignaturedescatversion)
* [GetUnconvertedRootSignatureDesc](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12versionedrootsignaturedeserializer-getunconvertedrootsignaturedesc)
* [D3D12SerializeVersionedRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-d3d12serializeversionedrootsignature)

Refer to the helper structure [CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-versioned-root-signature-desc).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)