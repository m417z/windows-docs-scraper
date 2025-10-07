# D3DXSHMultiply6 function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [Spherical Harmonics Math](https://github.com/Microsoft/DirectXMath/tree/main/SHMath) library function **XMSHMultiply6**.

Computes the product of two spherical harmonics functions (f and g). Both functions are of order N = 6.

## Parameters

*pOut* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the output SH coefficients — the basis function *Y*ₗₘ is stored at l² + *m* + l. The order *N* determines the length of the array, where there should always be *N*² coefficients.

*pF* \[in\]

Type: **const [**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Input SH coefficients for first function.

*pG* \[in\]

Type: **const [**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Second set of input SH coefficients.

## Return value

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to SH output coefficients.

## Remarks

The product of two SH functions of order N = 6 generates an SH function of order 2 × *N* - 1 = 11, but the results are truncated. This means that the product commutes ( *f* × *g* = *g* × *f* ) but doesn't associate ( *f* × ( *g* × *h* ) ≠ ( *f* × *g* ) × *h* ).

This function uses the following equation:

```
pOut[i] = int(y_i(s) * f(s) * g(s))
```

where y\_i(s) is the ith SH basis function, and where f(s) and g(s) use the following SH function:

```
sum_i(y_i(s)*c_i)
```

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

