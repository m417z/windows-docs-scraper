# XMVectorSwizzle function

## Description

Swizzles a vector.

## Parameters

### `V` [in]

Vector to swizzle.

### `E0` [in]

Index that describes which component of *V* to place in the x-component of the swizzled vector. A value of 0
selects the x-component, 1 selects the y-component, 2 selects the z-component, and 3 selects the w-component.

### `E1` [in]

Index that describes which component of *V* to place in the y-component of the swizzled vector. A value of 0
selects the x-component, 1 selects the y-component, 2 selects the z-component, and 3 selects the w-component.

### `E2` [in]

Index that describes which component of *V* to place in the z-component of the swizzled vector. A value of 0
selects the x-component, 1 selects the y-component, 2 selects the z-component, and 3 selects the w-component.

### `E3` [in]

Index that describes which component of *V* to place in the w-component of the swizzled vector. A value of 0
selects the x-component, 1 selects the y-component, 2 selects the z-component, and 3 selects the w-component.

## Return value

Returns the swizzled [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Remarks

The following code demonstrates how this function might be used.

```
XMVECTOR v = XMVectorSet( 10.0f, 20.0f, 30.0f, 40.0f );
XMVECTOR result = XMVectorSwizzle(v, 3, 3, 0, 2 );
```

The swizzled vector (*result*) will be <40.0f, 40.0f, 10.0f, 30.0f>.

`XM_SWIZZLE_X`, `XM_SWIZZLE_Y`, `XM_SWIZZLE_Z`, and `XM_SWIZZLE_W` are constants which
evaluate to 0, 1, 2, and 3 respectively for use with **XMVectorSwizzle**.
This is identical to `XM_PERMUTE_0X`, `XM_PERMUTE_0Y`, `XM_PERMUTE_0Z`, and `XM_PERMUTE_0W`.

For the case of constant indices (E0, E1, E2, E3), it is much more efficient to use the template form of [XMVectorSwizzle](https://learn.microsoft.com/windows/desktop/dxmath/xmvectorswizzle-template):

```

template<uint32_t SwizzleX, uint32_t SwizzleY, uint32_t SwizzleZ, uint32_t SwizzleW>
    XMVECTOR XMVectorSwizzle(FXMVECTOR V)

Example: XMVectorSwizzle< 3, 3, 0, 2>(v);

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Component-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-component-wise)

[XMVectorPermute](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorpermute)