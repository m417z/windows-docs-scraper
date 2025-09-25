# ID3D11ShaderReflectionVariable::GetInterfaceSlot

## Description

Gets the corresponding interface slot for a variable that represents an interface pointer.

## Parameters

### `uArrayIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the array element to get the slot number for. For a non-array variable this value will be zero.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the index of the interface in the interface array.

## Remarks

GetInterfaceSlot gets the corresponding slot in a dynamic linkage array for an interface instance. The returned slot number is used to set an interface instance to a particular class instance. See the HLSL [Interfaces and Classes](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl-dynamic-linking-class) overview for additional information.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

#### Examples

Retrieving and using an interface slot

```

ID3D11ShaderReflectionVariable* pAmbientLightingVar = pReflector->GetVariableByName("g_abstractAmbientLighting");
g_iAmbientLightingOffset = pAmbientLightingVar->GetInterfaceSlot(0);
g_pPSClassLinkage->GetClassInstance( "g_hemiAmbientLight", 0, &g_pHemiAmbientLightClass );
g_dynamicLinkageArray[g_iAmbientLightingOffset] = g_pHemiAmbientLightClass;
...
pd3dImmediateContext->PSSetShader( g_pPixelShader, g_dynamicLinkageArray, g_iNumPSInterfaces );

```

## See also

[ID3D11ShaderReflectionVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionvariable)