# D3DXQuaternionExp function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Calculates the exponential.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure that is the result of the operation.

*pQ* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the source [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure.

## Return value

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure that is the exponential.

## Remarks

This method converts a pure quaternion to a unit quaternion. **D3DXQuaternionExp** expects a pure quaternion, where w is ignored in the calculation (w == 0).

```
Given a pure quaternion defined by:
q = (0, theta * v);

This method calculates the exponential result.
exp(Q) = (cos(theta), sin(theta) * v)
```

where v is the vector portion of a quaternion.

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXQuaternionExp** function can be used as a parameter for another function.

The [**D3DXQuaternionSquadSetup**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionsquadsetup) method can also be used to set up the control points of a quaternion.

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionnormalize) for any quaternion input that is not already normalized.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXQuaternionLn**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionln)

[**D3DXQuaternionSquad**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionsquad)

