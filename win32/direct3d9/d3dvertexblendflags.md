# D3DVERTEXBLENDFLAGS enumeration

Defines flags used to control the number or matrices that the system applies when performing multimatrix vertex blending.

## Constants

**D3DVBF\_DISABLE**

Disable vertex blending; apply only the world matrix set by the [**D3DTS\_WORLDMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldmatrix) macro, where the index value for the transformation state is 0.

**D3DVBF\_1WEIGHTS**

Enable vertex blending between the two matrices set by the [**D3DTS\_WORLDMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldmatrix) macro, where the index value for the transformation states are 0 and 1.

**D3DVBF\_2WEIGHTS**

Enable vertex blending between the three matrices set by the [**D3DTS\_WORLDMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldmatrix) macro, where the index value for the transformation states are 0, 1, and 2.

**D3DVBF\_3WEIGHTS**

Enable vertex blending between the four matrices set by the [**D3DTS\_WORLDMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldmatrix) macro, where the index value for the transformation states are 0, 1, 2, and 3.

**D3DVBF\_TWEENING**

Vertex blending is done by using the value assigned to D3DRS\_TWEENFACTOR.

**D3DVBF\_0WEIGHTS**

Use a single matrix with a weight of 1.0.

## Remarks

Members of this type are used with the D3DRS\_VERTEXBLEND render state.

Geometry blending (multimatrix vertex blending) requires that your application use a vertex format that has blending (beta) weights for each vertex.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

[**D3DTS\_WORLD**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-world)

[**D3DTS\_WORLDn**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldn)

[**D3DTS\_WORLDMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldmatrix)

