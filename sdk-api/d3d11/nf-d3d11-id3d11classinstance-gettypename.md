# ID3D11ClassInstance::GetTypeName

## Description

Gets the type of the current HLSL class.

## Parameters

### `pTypeName` [out, optional]

Type: **[LPSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of the current HLSL class.

### `pBufferLength` [in, out]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The length of the *pTypeName* parameter.

## Remarks

GetTypeName will return a valid name only for instances acquired using [ID3D11ClassLinkage::GetClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11classlinkage-getclassinstance).

For more information about using the [ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance) interface, see [Dynamic Linking](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl-dynamic-linking).

**Windows Phone 8:** This API is supported.

## See also

[ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)