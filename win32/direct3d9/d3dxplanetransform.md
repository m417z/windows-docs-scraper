# D3DXPlaneTransform function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Transforms a plane by a matrix. The input matrix is the inverse transpose of the actual transformation.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to the [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane) structure that contains the resulting transformed plane. See example.

*pP* \[in\]

Type: **const [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to the input [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane) structure, which contains the plane that will be transformed. The vector (a,b,c) that describes the plane must be normalized before this function is called. See example.

*pM* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the source [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure, which contains the transformation values. This matrix must contain the inverse transpose of the transformation values.

## Return value

Type: **[**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to a [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane) structure, representing the transformed plane. This is the same value returned in the pOut parameter so that this function can be used as a parameter for another function.

## Remarks

### Examples

This example transforms a plane by applying a non-uniform scale.

```
D3DXPLANE   planeNew;
D3DXPLANE   plane(0,1,1,0);
D3DXPlaneNormalize(&plane, &plane);

D3DXMATRIX  matrix;
D3DXMatrixScaling(&matrix, 1.0f,2.0f,3.0f);
D3DXMatrixInverse(&matrix, NULL, &matrix);
D3DXMatrixTranspose(&matrix, &matrix);
D3DXPlaneTransform(&planeNew, &plane, &matrix);
```

A plane is described by ax + by + cz + dw = 0. The first plane is created with (a,b,c,d) = (0,1,1,0), which is a plane described by y + z = 0. After scaling, the new plane contains (a,b,c,d) = (0, 0.353f, 0.235f, 0), which shows the new plane to be described by 0.353y + 0.235z = 0.

The parameter pM contains the inverse transpose of the transformation matrix. The inverse transpose is required by this method so that the normal vector of the transformed plane can be correctly transformed as well.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXPlaneNormalize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplanenormalize)

[**D3DXMatrixRotationX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationx)

[**D3DXMatrixRotationY**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationy)

[**D3DXMatrixRotationZ**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationz)

[**D3DXMatrixInverse**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixinverse)

[**D3DXMatrixTranspose**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixtranspose)

