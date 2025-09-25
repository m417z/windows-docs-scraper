# ID3D12VersionedRootSignatureDeserializer::GetRootSignatureDescAtVersion

## Description

Converts root signature description structures to a requested version.

## Parameters

### `convertToVersion`

Type: **[D3D_ROOT_SIGNATURE_VERSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d_root_signature_version)**

Specifies the required [D3D_ROOT_SIGNATURE_VERSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d_root_signature_version).

### `ppDesc` [out]

Type: **const [D3D12_VERSIONED_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc)****

Contains the deserialized root signature in a [D3D12_VERSIONED_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc) structure.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. The method can fail with E_OUTOFMEMORY.

## Remarks

This method allocates additional storage if needed for the converted root signature (memory owned by the deserializer interface). If conversion is done, the deserializer interface doesn’t free the original deserialized root signature memory – all versions the interface has been asked to convert to are available until the deserializer is destroyed.

Converting a root signature from 1.1 to 1.0 will drop all [D3D12_DESCRIPTOR_RANGE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_flags) and [D3D12_ROOT_DESCRIPTOR_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_descriptor_flags) can be useful for generating compatible root signatures that need to run on old operating systems, though does lose optimization opportunities. For instance, multiple root signature versions can be serialized and stored with application assets, with the appropriate version used at runtime based on the operating system capabilities.

Converting a root signature from 1.0 to 1.1 just adds the appropriate flags to match 1.0 semantics.

## See also

[ID3D12VersionedRootSignatureDeserializer](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12versionedrootsignaturedeserializer)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)