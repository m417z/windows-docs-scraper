# D3DXQuaternionMultiply function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Multiplies two quaternions.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion)\***

Pointer to the [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion) that is the result of the operation.

*pQ1* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion)\***

Pointer to a source [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion) structure.

*pQ2* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion)\***

Pointer to a source [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion) structure.

## Return value

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion) structure that is the product of two quaternions.

## Remarks

The result represents the rotation Q1 followed by the rotation Q2 (Out = Q2 \* Q1). This is done so that **D3DXQuaternionMultiply** maintain the same semantics as [**D3DXMatrixMultiply**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrixmultiply) because unit quaternions can be considered as another way to represent rotation matrices.

Transformations are concatenated in the same order for both the **D3DXQuaternionMultiply** and [**D3DXMatrixMultiply**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrixmultiply) Functions. For example, assuming mX and mY represent the same rotations as qX and qY, both m and q will represent the same rotations.

```
D3DXMatrixMultiply(&m, &mX, &mY);
D3DXQuaternionMultiply(&q, &qX, &qY);
```

The multiplication of quaternions is not commutative.

The return value for this function is the same value returned in the pOut parameter. In this way, the **D3DXQuaternionMultiply** function can be used as a parameter for another function.

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternionnormalize) for any quaternion input that is not already normalized.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

