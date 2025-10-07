# D3DX11\_EFFECT\_TYPE\_DESC structure

Describes an effect-variable type.

## Members

**TypeName**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the type, for example "float4" or "MyStruct".

**Class**

Type: **[**D3D10\_SHADER\_VARIABLE\_CLASS**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)**

The variable class (see [**D3D10\_SHADER\_VARIABLE\_CLASS**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)).

**Type**

Type: **[**D3D10\_SHADER\_VARIABLE\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)**

The variable type (see [**D3D10\_SHADER\_VARIABLE\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)).

**Elements**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of elements in this type (0 if not an array).

**Members**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of members (0 if not a structure).

**Rows**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of rows in this type (0 if not a numeric primitive).

**Columns**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of columns in this type (0 if not a numeric primitive).

**PackedSize**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bytes required to represent this data type, when tightly packed.

**UnpackedSize**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bytes occupied by this data type, when laid out in a constant buffer.

**Stride**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bytes to seek between elements, when laid out in a constant buffer.

## Remarks

D3DX11\_EFFECT\_TYPE\_DESC is used with [**ID3DX11EffectType::GetDesc**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effecttype-getdesc)

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-structures)

