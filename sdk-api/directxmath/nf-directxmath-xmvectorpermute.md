# XMVectorPermute function

## Description

Permutes the components of two vectors to create a new vector.

## Parameters

### `V1` [in]

First vector.

### `V2` [in]

Second vector.

### `PermuteX`

Index form 0-7 indicating where the X component of the new vector should be copied from.

### `PermuteY`

Index form 0-7 indicating where the Y component of the new vector should be copied from.

### `PermuteZ`

Index form 0-7 indicating where the Z component of the new vector should be copied from.

### `PermuteW`

Index form 0-7 indicating where the W component of the new vector should be copied from.

## Return value

Returns the permuted vector that resulted from combining the source vectors.

## Remarks

If all 4 indices reference only a single vector (i.e. they are all in the range 0-3 or all in the range 4-7),
use [XMVectorSwizzle](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorswizzle) instead for better performance.

The [XM_PERMUTE_](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-constants) constants are provided to
use as input values for *PermuteX*,*PermuteY*,*PermuteZ*, and *PermuteW*.

For constant PermuteX/Y/Z/W parameters, it is much more efficient to use the template form of
[XMVectorPermute](https://learn.microsoft.com/windows/desktop/dxmath/xmvectorpermute-template):

```

template<uint32_t PermuteX, uint32_t PermuteY, uint32_t PermuteZ, uint32_t PermuteW>
    XMVECTOR XMVectorPermute(FXMVECTOR V1, FXMVECTOR V2)

Example: XMVectorPermute<XM_PERMUTE_0Z, XM_PERMUTE_1X, XM_PERMUTE_0W, XM_PERMUTE_1Y>( V1, V2 );

```

**Note** This version of `XMVectorPermute` is new for DirectXMath. The XNAMath v2.x library made use of `XMVectorPermuteControl`,
a control `XMVECTOR` instead of 4 indices for `XMVectorPermute`, and used different values for the XM_PERMUTE_x constants.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Component-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-component-wise)

[XMVectorSwizzle](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorswizzle)