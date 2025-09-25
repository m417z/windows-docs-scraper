# ID3D12ShaderReflectionVariable::GetInterfaceSlot

## Description

Gets the corresponding interface slot for a variable that represents an interface pointer.

## Parameters

### `uArrayIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the array element to get the slot number for.
For a non-array variable this value will be zero.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the index of the interface in the interface array.

## Remarks

GetInterfaceSlot gets the corresponding slot in a dynamic linkage array for an interface instance.
The returned slot number is used to set an interface instance to a particular class instance.
See the HLSL [Interfaces and Classes](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl-dynamic-linking-class) overview for additional information.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflectionVariable](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectionvariable)