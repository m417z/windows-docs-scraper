# D3DX12SerializeVersionedRootSignature function

Helps enable root signature 1.1 features when they are available, and does not require maintaining two code paths for building root signatures. This helper method reconstructs a version 1.0 root signature when version 1.1 is not supported.

## Parameters

*pRootSignatureDesc* \[in\]

Type: **const D3D12\_VERSIONED\_ROOT\_SIGNATURE\_DESC\***

Specifies a [**D3D12\_VERSIONED\_ROOT\_SIGNATURE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc) that contains a description of any version of a root signature.

*MaxVersion*

Type: **D3D\_ROOT\_SIGNATURE\_VERSION**

Specifies the maximum supported [**D3D\_ROOT\_SIGNATURE\_VERSION**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d_root_signature_version).

*ppBlob* \[out\]

Type: **ID3DBlob\*\***

A pointer to a memory block that receives a pointer to the [**ID3DBlob**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access the serialized root signature.

*ppErrorBlob* \[out, optional\]

Type: **ID3DBlob\*\***

A pointer to a memory block that receives a pointer to the [**ID3DBlob**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access serializer error messages, or **NULL** if there are no errors.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

Returns **S\_OK** if successful; otherwise, returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This function was released to coincide with the Windows 10 Anniversary Update (14393). In order to support Windows 10 versions prior to this, use of this function requires d3d12.lib be set up for *delay loading*.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[**D3D12SerializeVersionedRootSignature**](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-d3d12serializeversionedrootsignature)

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

