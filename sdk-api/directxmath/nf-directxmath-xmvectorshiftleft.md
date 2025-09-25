# XMVectorShiftLeft function

## Description

Shifts a vector left by a given number of 32-bit elements, filling the vacated elements with elements from a second
vector.

## Parameters

### `V1` [in]

Vector to shift left.

### `V2` [in]

Vector used to fill in the vacated components of *V1* after it is shifted left.

### `Elements` [in]

Number of 32-bit elements by which to shift *V* left. This parameter must be 0, 1, 2, or 3.

## Return value

Returns the shifted and filled in [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Remarks

The following code demonstrates how this function might be used.

```
XMVECTOR v1 = XMVectorSet( 10.0f, 20.0f, 30.0f, 40.0f );
XMVECTOR v2 = XMVectorSet( 50.0f, 60.0f, 70.0f, 80.0f );
XMVECTOR result = XMVectorShiftLeft( v1, v2, 1 );
```

The shifted vector (*result*) will be <20.0f, 30.0f, 40.0f, 50.0f>.

In the case of a constant shift value, it is more efficient to use the template form of [XMVectorShiftLeft](https://learn.microsoft.com/windows/desktop/dxmath/xmvectorshiftleft-template):

```

template<uint32_t Elements>
    XMVECTOR XMVectorShiftLeft(FXMVECTOR V1, FXMVECTOR V2)

Example: XMVectorShiftLeft<1>( v1, v2 );

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Component-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-component-wise)

[XMVectorPermute](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorpermute)

[XMVectorRotateLeft](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorrotateleft)

[XMVectorRotateRight](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorrotateright)