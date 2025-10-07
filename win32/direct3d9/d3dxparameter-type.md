# D3DXPARAMETER\_TYPE enumeration

Describes the data contained by the enumeration.

## Constants

**D3DXPT\_VOID**

Parameter is a void pointer.

**D3DXPT\_BOOL**

Parameter is a Boolean. Any non-zero value passed into [**ID3DXConstantTable::SetBool**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable--setbool), [**ID3DXConstantTable::SetBoolArray**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable--setboolarray), [**ID3DXConstantTable::SetValue**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable--setvalue), [**ID3DXConstantTable::SetVector**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable--setvector), or [**ID3DXConstantTable::SetVectorArray**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable--setvectorarray) will be mapped to 1 (TRUE) before being written into the constant table; otherwise, the value will be set to 0 in the constant table.

**D3DXPT\_INT**

Parameter is an integer. Any floating-point values passed into [**ID3DXConstantTable::SetValue**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable--setvalue), [**ID3DXConstantTable::SetVector**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable--setvector), or [**ID3DXConstantTable::SetVectorArray**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable--setvectorarray) will be rounded off (to zero decimal places) before being written into the constant table.

**D3DXPT\_FLOAT**

Parameter is a floating-point number.

**D3DXPT\_STRING**

Parameter is a string.

**D3DXPT\_TEXTURE**

Parameter is a texture.

**D3DXPT\_TEXTURE1D**

Parameter is a 1D texture.

**D3DXPT\_TEXTURE2D**

Parameter is a 2D texture.

**D3DXPT\_TEXTURE3D**

Parameter is a 3D texture.

**D3DXPT\_TEXTURECUBE**

Parameter is a cube texture.

**D3DXPT\_SAMPLER**

Parameter is a sampler.

**D3DXPT\_SAMPLER1D**

Parameter is a 1D sampler.

**D3DXPT\_SAMPLER2D**

Parameter is a 2D sampler.

**D3DXPT\_SAMPLER3D**

Parameter is a 3D sampler.

**D3DXPT\_SAMPLERCUBE**

Parameter is a cube sampler.

**D3DXPT\_PIXELSHADER**

Parameter is a pixel shader.

**D3DXPT\_VERTEXSHADER**

Parameter is a vertex shader.

**D3DXPT\_PIXELFRAGMENT**

Parameter is a pixel shader fragment.

**D3DXPT\_VERTEXFRAGMENT**

Parameter is a vertex shader fragment.

**D3DXPT\_UNSUPPORTED**

Parameter is not supported.

**D3DXPT\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9shader.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

[**D3DXSHADER\_TYPEINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-typeinfo)

[**D3DXCONSTANT\_DESC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxconstant-desc)

