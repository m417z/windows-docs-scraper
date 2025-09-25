# ID3D11ClassLinkage::CreateClassInstance

## Description

Initializes a class-instance object that represents an HLSL class instance.

## Parameters

### `pClassTypeName` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The type name of a class to initialize.

### `ConstantBufferOffset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the constant buffer that contains the class data.

### `ConstantVectorOffset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The four-component vector offset from the start of the constant buffer where the class data will begin. Consequently, this is not a byte offset.

### `TextureOffset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The texture slot for the first texture; there may be multiple textures following the offset.

### `SamplerOffset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The sampler slot for the first sampler; there may be multiple samplers following the offset.

### `ppInstance` [out]

Type: **[ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)****

The address of a pointer to an [ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance) interface to initialize.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

Instances can be created (or gotten) before or after a shader is created. Use the same shader linkage object to acquire a class instance and create the shader the instance is going to be used in.

For more information about using the [ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage) interface, see [Dynamic Linking](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl-dynamic-linking).

**Windows Phone 8:** This API is supported.

## See also

[ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)