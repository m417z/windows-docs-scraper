# D3DDECLTYPE enumeration

Defines a vertex declaration data type.

## Constants

**D3DDECLTYPE\_FLOAT1**

One-component float expanded to (float, 0, 0, 1).

**D3DDECLTYPE\_FLOAT2**

Two-component float expanded to (float, float, 0, 1).

**D3DDECLTYPE\_FLOAT3**

Three-component float expanded to (float, float, float, 1).

**D3DDECLTYPE\_FLOAT4**

Four-component float expanded to (float, float, float, float).

**D3DDECLTYPE\_D3DCOLOR**

Four-component, packed, unsigned bytes mapped to 0 to 1 range. Input is a [**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) and is expanded to RGBA order.

**D3DDECLTYPE\_UBYTE4**

Four-component, unsigned byte.

**D3DDECLTYPE\_SHORT2**

Two-component, signed short expanded to (value, value, 0, 1).

**D3DDECLTYPE\_SHORT4**

Four-component, signed short expanded to (value, value, value, value).

**D3DDECLTYPE\_UBYTE4N**

Four-component byte with each byte normalized by dividing with 255.0f.

**D3DDECLTYPE\_SHORT2N**

Normalized, two-component, signed short, expanded to (first short/32767.0, second short/32767.0, 0, 1).

**D3DDECLTYPE\_SHORT4N**

Normalized, four-component, signed short, expanded to (first short/32767.0, second short/32767.0, third short/32767.0, fourth short/32767.0).

**D3DDECLTYPE\_USHORT2N**

Normalized, two-component, unsigned short, expanded to (first short/65535.0, short short/65535.0, 0, 1).

**D3DDECLTYPE\_USHORT4N**

Normalized, four-component, unsigned short, expanded to (first short/65535.0, second short/65535.0, third short/65535.0, fourth short/65535.0).

**D3DDECLTYPE\_UDEC3**

Three-component, unsigned, 10 10 10 format expanded to (value, value, value, 1).

**D3DDECLTYPE\_DEC3N**

Three-component, signed, 10 10 10 format normalized and expanded to (v\[0\]/511.0, v\[1\]/511.0, v\[2\]/511.0, 1).

**D3DDECLTYPE\_FLOAT16\_2**

Two-component, 16-bit, floating point expanded to (value, value, 0, 1).

**D3DDECLTYPE\_FLOAT16\_4**

Four-component, 16-bit, floating point expanded to (value, value, value, value).

**D3DDECLTYPE\_UNUSED**

Type field in the declaration is unused. This is designed for use with D3DDECLMETHOD\_UV and D3DDECLMETHOD\_LOOKUPPRESAMPLED.

## Remarks

Vertex data is declared with an array of [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9) structures. Each element in the array contains a vertex declaration data type.

Use the DirectX Caps Viewer Tool (DXCapsViewer.exe) to see which types are supported on your device. You can get this tool and learn about it from the DirectX SDK. For info about the DirectX SDK, see [Where is the DirectX SDK?](https://learn.microsoft.com/windows/win32/directx-sdk--august-2009-).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DDECLMETHOD**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddeclmethod)

