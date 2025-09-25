# ID3D11Device::CreateClassLinkage

## Description

Creates class linkage libraries to enable dynamic shader linkage.

## Parameters

### `ppLinkage` [out]

Type: **[ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)****

A pointer to a class-linkage interface pointer (see [ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The [ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage) interface returned in *ppLinkage* is associated with a shader by passing it as a parameter to one of the [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) create shader methods such as [ID3D11Device::CreatePixelShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createpixelshader).

#### Examples

Using CreateClassLinkage

```

ID3D11ClassLinkage * g_pPSClassLinkage = NULL;
pd3dDevice->CreateClassLinkage( &g_pPSClassLinkage );

```

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)