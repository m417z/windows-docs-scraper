# XMVectorRotateLeft function

## Description

Rotates the vector left by a given number of 32-bit elements.

## Parameters

### `V` [in]

Vector to rotate left.

### `Elements` [in]

Number of 32-bit elements by which to rotate *V* left. This parameter must be 0, 1, 2, or 3.

## Return value

Returns the rotated [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Remarks

The following code demonstrates how this function may be used.

```
XMVECTOR v = XMVectorSet( 10.0f, 20.0f, 30.0f, 40.0f );
XMVECTOR result = XMVectorRotateLeft( v, 1 );
```

The rotated vector (*result*) will be <20.0f, 30.0f, 40.0f, 10.0f>.

In the case of a constant rotate value, it is more efficient to use the template form of [XMVectorRotateLeft](https://learn.microsoft.com/windows/desktop/dxmath/xmvectorrotateleft-template):

```

template<uint32_t Elements>
    XMVECTOR XMVectorRotateLeft(FXMVECTOR V)

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Component-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-component-wise)

[XMVectorPermute](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorpermute)

[XMVectorRotateRight](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorrotateright)

[XMVectorShiftLeft](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorshiftleft)