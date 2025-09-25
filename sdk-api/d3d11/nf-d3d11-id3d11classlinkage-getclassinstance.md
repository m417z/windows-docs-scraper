# ID3D11ClassLinkage::GetClassInstance

## Description

Gets the class-instance object that represents the specified HLSL class.

## Parameters

### `pClassInstanceName` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of a class for which to get the class instance.

### `InstanceIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the class instance.

### `ppInstance` [out]

Type: **[ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)****

The address of a pointer to an [ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance) interface to initialize.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

For more information about using the [ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage) interface, see
[Dynamic Linking](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl-dynamic-linking).

A class instance must have at least 1 data member in order to be available for the runtime to use with
**ID3D11ClassLinkage::GetClassInstance**.
Any instance with no members will be optimized out of a compiled shader blob as a zero-sized object.
If you have a class with no data members, use
[ID3D11ClassLinkage::CreateClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11classlinkage-createclassinstance) instead.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)

[ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)