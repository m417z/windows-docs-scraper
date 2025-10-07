# D3DXQuaternionInverse function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Conjugates and renormalizes a quaternion.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure that is the result of the operation.

*pQ* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the source [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure.

## Return value

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure that is the inverse quaternion of the quaternion.

## Remarks

```
A unit quaternion, is defined by:
Q == (cos(theta), sin(theta) * v) where |v| = 1
The natural logarithm of Q is, ln(Q) = (0, theta * v)
```

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXQuaternionInverse** function can be used as a parameter for another function.

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionnormalize) for any quaternion input that is not already normalized.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXQuaternionConjugate**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionconjugate)

[**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionnormalize)

