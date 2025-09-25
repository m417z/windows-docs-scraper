# XMVectorInsert function

## Description

Rotates a vector left by a given number of 32-bit components and insert selected elements of that result into another
vector.

## Parameters

### `VD` [in]

Vector to insert into.

### `VS` [in]

Vector to rotate left.

### `VSLeftRotateElements` [in]

Number of 32-bit components by which to rotate *VS* left.

### `Select0` [in]

Either 0 or 1. If one, the x-component of the rotated vector will be inserted into the corresponding component of
*VD*. Otherwise, the x-component of *VD* is left alone.

### `Select1` [in]

Either 0 or 1. If one, the y-component of the rotated vector will be inserted into the corresponding component of
*VD*. Otherwise, the y-component of *VD* is left alone.

### `Select2` [in]

Either 0 or 1. If one, the z-component of the rotated vector will be inserted into the corresponding component of
*VD*. Otherwise, the z-component of *VD* is left alone.

### `Select3` [in]

Either 0 or 1. If one, the w-component of the rotated vector will be inserted into the corresponding component of
*VD*. Otherwise, the w-component of *VD* is left alone.

## Return value

Returns the [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) that results from the rotation and insertion.

## Remarks

For best performance, the result of
**XMVectorInsert** should be assigned back to *VD*.

For cases with constant uint32_t parameters, it is more efficient to use the template form of [XMVectorInsert](https://learn.microsoft.com/windows/desktop/dxmath/xmvectorinsert-template):

```

template<uint32_t VSLeftRotateElements, uint32_t Select0, uint32_t Select1, uint32_t Select2, uint32_t Select3>
    XMVECTOR XMVectorInsert(FXMVECTOR VD, FXMVECTOR VS)

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Component-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-component-wise)

[XMVectorPermute](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorpermute)

[XMVectorRotateLeft](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorrotateleft)

[XMVectorRotateRight](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorrotateright)

[XMVectorShiftLeft](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorshiftleft)