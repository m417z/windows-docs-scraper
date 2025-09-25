## Description

Gets the minimum feature level.

## Parameters

### `pLevel`

Type: [out] **[D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)***

A pointer to one of the enumerated values in [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level), which represents the minimum feature level.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D11ShaderReflection Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection)