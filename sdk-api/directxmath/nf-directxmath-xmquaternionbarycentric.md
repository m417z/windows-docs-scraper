# XMQuaternionBaryCentric function

## Description

Returns a point in barycentric coordinates, using the specified quaternions.

## Parameters

### `Q0` [in]

First quaternion in the triangle.

### `Q1` [in]

Second quaternion in the triangle.

### `Q2` [in]

Third quaternion in the triangle.

### `f` [in]

Weighting factor. See the remarks.

### `g` [in]

Weighting factor. See the remarks.

## Return value

Returns a quaternion in barycentric coordinates.

## Remarks

The following pseudocode demonstrates the operation of the function.

```

XMVECTOR Result;
XMVECTOR QA, QB;
float s = f + g;

if (s != 0.0f)
{
    QA = XMQuaternionSlerp(Q0, Q1, s);
    QB = XMQuaternionSlerp(Q0, Q2, s);
    Result = XMQuaternionSlerp(QA, QB, g / s);
}
else
{
    Result.x = Q0.x;
    Result.y = Q0.y;
    Result.z = Q0.z;
    Result.w = Q0.w;
}

return Result;

```

Note that Barycentric coordinates work for 'flat' surfaces but not for 'curved' ones. This function is therefore a bit of a work-around.
An alternative method for blending 3 quaternions is given by the following code:

```

inline XMVECTOR XMQuaternionBlend(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, float w1, float w2)
{
    // Note if you choose one of the three weights to be zero, you get a blend of two
    //  quaternions.  This does not give you slerp of those quaternions.
    float w0 = 1.0f - w1 - w2;
    XMVECTOR Result = XMVector4Normalize(
        XMVectorScale(Q0, w0) +
        XMVectorScale(Q1, w1) +
        XMVectorScale(Q2, w2));
    return Result;
}

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)

[XMQuaternionBaryCentricV](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionbarycentricv)