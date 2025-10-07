# D3DDECLMETHOD enumeration

Defines the vertex declaration method which is a predefined operation performed by the tessellator (or any procedural geometry routine on the vertex data during tessellation).

## Constants

**D3DDECLMETHOD\_DEFAULT**

Default value. The tessellator copies the vertex data (spline data for patches) as is, with no additional calculations. When the tessellator is used, this element is interpolated. Otherwise vertex data is copied into the input register. The input and output type can be any value, but are always the same type.

**D3DDECLMETHOD\_PARTIALU**

Computes the tangent at a point on the rectangle or triangle patch in the U direction. The input type can be one of the following:

- D3DDECLTYPE\_D3DCOLOR
- D3DDECLTYPE\_FLOAT3
- D3DDECLTYPE\_FLOAT4
- D3DDECLTYPE\_SHORT4
- D3DDECLTYPE\_UBYTE4

The output type is always D3DDECLTYPE\_FLOAT3.

**D3DDECLMETHOD\_PARTIALV**

Computes the tangent at a point on the rectangle or triangle patch in the V direction. The input type can be one of the following:

- D3DDECLTYPE\_D3DCOLOR
- D3DDECLTYPE\_FLOAT3
- D3DDECLTYPE\_FLOAT4
- D3DDECLTYPE\_SHORT4
- D3DDECLTYPE\_UBYTE4

The output type is always D3DDECLTYPE\_FLOAT3.

**D3DDECLMETHOD\_CROSSUV**

Computes the normal at a point on the rectangle or triangle patch by taking the cross product of two tangents. The input type can be one of the following:

- D3DDECLTYPE\_D3DCOLOR
- D3DDECLTYPE\_FLOAT3
- D3DDECLTYPE\_FLOAT4
- D3DDECLTYPE\_SHORT4
- D3DDECLTYPE\_UBYTE4

The output type is always D3DDECLTYPE\_FLOAT3.

**D3DDECLMETHOD\_UV**

Copy out the U, V values at a point on the rectangle or triangle patch. This results in a 2D float. The input type must be set to D3DDECLTYPE\_UNUSED. The output data type is always D3DDECLTYPE\_FLOAT2. The input stream and offset are also unused (but must be set to 0).

**D3DDECLMETHOD\_LOOKUP**

Look up a displacement map. The input type can be one of the following:

- D3DDECLTYPE\_FLOAT2
- D3DDECLTYPE\_FLOAT3
- D3DDECLTYPE\_FLOAT4

Only the .x and .y components are used for the texture map lookup. The output type is always D3DDECLTYPE\_FLOAT1. The device must support displacement mapping. For more information about displacement mapping, see [Displacement Mapping (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/displacement-mapping). This constant is supported only by the programmable pipeline on N-patch data, if N-patches are enabled.

**D3DDECLMETHOD\_LOOKUPPRESAMPLED**

Look up a presampled displacement map. The input type must be set to D3DDECLTYPE\_UNUSED; the stream index and the stream offset must be set to 0. The output type for this operation is always D3DDECLTYPE\_FLOAT1. The device must support displacement mapping. For more information about displacement mapping, see [Displacement Mapping (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/displacement-mapping). This constant is supported only by the programmable pipeline on N-patch data, if N-patches are enabled. This method can be used only with D3DDECLUSAGE\_SAMPLE.

## Remarks

The tessellator looks at the method to determine what data to calculate from the vertex data during tessellation. Mesh data should use the default value. Patches can use any of the other implemented types.

Vertex data is declared with an array of [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9) structures. Each element in the array contains a vertex declaration method.

In addition to using D3DDECLMETHOD\_DEFAULT, a normal mesh can use D3DDECLMETHOD\_LOOKUP and D3DDECLMETHOD\_LOOKUPPRESAMPLED methods when N-patches are enabled.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

