# XMVector4Normalize function

## Description

Returns the normalized version of a 4D vector.

## Parameters

### `V` [in]

4D vector.

## Return value

Returns the normalized version of *V*.

## Remarks

For a vector of length 0, this function returns a zero vector. For a vector with infinite length, it returns a vector of QNaN.

Note that for most graphics applications, ensuring the vectors have well-defined lengths that don't cause problems
for normalization is common practice. However, if you need a robust normalization that works for all floating-point inputs,
you can use the following code instead:

```

inline XMVECTOR XMVector4NormalizeRobust( FXMVECTOR V )
{
    // Compute the maximum absolute value component.
    XMVECTOR vAbs = XMVectorAbs(V);
    XMVECTOR max0 = XMVectorSplatX(vAbs);
    XMVECTOR max1 = XMVectorSplatY(vAbs);
    XMVECTOR max2 = XMVectorSplatZ(vAbs);
    XMVECTOR max3 = XMVectorSplatW(vAbs);
    max0 = XMVectorMax(max0, max1);
    max2 = XMVectorMax(max2, max3);
    max0 = XMVectorMax(max0, max2);

    // Divide by the maximum absolute component.
    XMVECTOR normalized = XMVectorDivide(V, max0);

    // Set to zero when the original length is zero.
    XMVECTOR mask = XMVectorNotEqual(g_XMZero, max0);
    normalized = XMVectorAndInt(normalized, mask);

    // (sqrLength, sqrLength, sqrLength, sqrLength)
    XMVECTOR t0 = XMVector4Dot(normalized, normalized);

    // (length, length, length, length)
    XMVECTOR length = XMVectorSqrt(t0);

    // Divide by the length to normalize.
    normalized = XMVectorDivide(normalized, length);

    // Set to zero when the original length is zero or infinity.  In the
    // latter case, this is considered to be an unexpected condition.
    normalized = XMVectorAndInt(normalized, mask);
    return normalized;
}

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-geometric)

[XMVector4NormalizeEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4normalizeest)