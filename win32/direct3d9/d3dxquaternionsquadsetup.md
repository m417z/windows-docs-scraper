# D3DXQuaternionSquadSetup function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Sets up control points for spherical quadrangle interpolation.

## Parameters

*pAOut* \[out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to AOut.

*pBOut* \[out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to BOut.

*pCOut* \[out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to COut.

*pQ0* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the input control point, Q0.

*pQ1* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the input control point, Q1.

*pQ2* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the input control point, Q2.

*pQ3* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the input control point, Q3.

## Return value

None.

## Remarks

This function takes four control points, which are supplied to the inputs pQ0, pQ1, pQ2, and pQ3. The function then alters these values to find a curve that flows along the shortest path. The values of q0, q2, and q3 are calculated as shown below.

```
q0 = |Q0 + Q1| < |Q0 - Q1| ? -Q0 : Q0
q2 = |Q1 + Q2| < |Q1 - Q2| ? -Q2 : Q2
q3 = |Q2 + Q3| < |Q2 - Q3| ? -Q3 : Q3
```

Having calculated the new Q values, the values for AOut, BOut, and COut are calculated as follows:

AOut = q1 \* e\[-0.25\ \*(\ Ln\[Exp(q1)\*q2\]\ +\ Ln\[Exp(q1)\*q0\]\ )\ \]

BOut = q2 \* e\[-0.25\ \*(\ Ln\[Exp(q2)\*q3\]\ +\ Ln\[Exp(q2)\*q1\]\ )\ \]

COut = q2

> [!Note]
> Ln is the API method [**D3DXQuaternionLn**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionln) and Exp is the API method [**D3DXQuaternionExp**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionexp).

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionnormalize) for any quaternion input that is not already normalized.

### Examples

The following example shows how to use a set of quaternion keys (Q0, Q1, Q2, Q3) to compute the inner quadrangle points (A, B, C). This ensures that the tangents are continuous across adjacent segments.

```
      A     B
Q0    Q1    Q2    Q3
```

The following code example demonstrates how you can interpolate between Q1 and Q2.

```
// Rotation about the z-axis
D3DXQUATERNION Q0 = D3DXQUATERNION(0,  0, 0.707f, -.707f);
D3DXQUATERNION Q1 = D3DXQUATERNION(0,  0, 0.000f, 1.000f);
D3DXQUATERNION Q2 = D3DXQUATERNION(0,  0, 0.707f, 0.707f);
D3DXQUATERNION Q3 = D3DXQUATERNION(0,  0, 1.000f, 0.000f);
D3DXQUATERNION A, B, C, Qt;
FLOAT time = 0.5f;

D3DXQuaternionSquadSetup(&A, &B, &C, &Q0, &Q1, &Q2, &Q3);
D3DXQuaternionSquad(&Qt, &Q1, &A, &B, &C, time);
```

> [!Note]
>
> - C is +/- Q2 depending on the result of the function.
> - Qt is the result of the function.
>
> The result is a rotation of 45 degrees around the z-axis for time = 0.5.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXQuaternionSquad**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionsquad)

