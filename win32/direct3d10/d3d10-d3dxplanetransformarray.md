# D3DXPlaneTransformArray function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Transforms an array of planes by a matrix. The vectors that describe each plane must be normalized.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to the [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxplane) structure that contains the resulting transformed plane. See Example.

*OutStride* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The stride of each transformed plane.

*pP* \[in\]

Type: **const [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to the input D3DXPLANE structure, which contains the array of planes to transform. The vector (a, b, c) that describes the plane must be normalized before this function is called. See Example.

*PStride* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The stride of each non-transformed plane.

*pM* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the source [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix) structure, which contains the inverse transpose of the transformation values.

*n* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of planes to transform.

## Return value

Type: **[**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to a D3DXPLANE structure, representing the transformed plane. This is the same value returned in the pOut parameter so that this function can be used as a parameter for another function.

## Remarks

This example transforms one plane by applying a non-uniform scale.

```
#define ARRAYSIZE 4
D3DXPLANE planeNew[ARRAYSIZE];
D3DXPLANE plane[ARRAYSIZE];

for(int i = 0; i < ARRAYSIZE; i++)
{
    plane = D3DXPLANE( 0.0f, 1.0f, 1.0f, 0.0f );
    D3DXPlaneNormalize( &plane[i], &plane[i] );
}

D3DXMATRIX  matrix;
D3DXMatrixScaling( &matrix, 1.0f, 2.0f, 3.0f );
D3DXMatrixInverse( &matrix, NULL, &matrix );
D3DXMatrixTranspose( &matrix, &matrix );
D3DXPlaneTransformArray( &planeNew, sizeof (D3DXPLANE), &plane,
                         sizeof (D3DXPLANE), &matrix, ARRAYSIZE );
```

A plane is described by ax + by + cz + dw = 0. The first plane is created with (a,b,c,d) = (0,1,1,0), which is a plane described by y + z = 0. After scaling, the new plane contains (a,b,c,d) = (0, 0.353f, 0.235f, 0), which shows the new plane to be described by 0.353y + 0.235z = 0.

The parameter pM, contains the inverse transpose of the transformation matrix. The inverse transpose is required by this method so that the normal vector of the transformed plane can be correctly transformed as well.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

