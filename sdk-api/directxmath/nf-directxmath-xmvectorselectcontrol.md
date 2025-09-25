# XMVectorSelectControl function

## Description

Defines a control vector for use in [XMVectorSelect](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselect).

## Parameters

### `VectorIndex0` [in]

Index that determines which vector in [XMVectorSelect](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselect) will be selected. If zero, the first vector's first component will be selected. Otherwise, the second vector's component will be selected.

### `VectorIndex1` [in]

Index that determines which vector in [XMVectorSelect](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselect) will be selected. If zero, the first vector's second component will be selected. Otherwise, the second vector's component will be selected.

### `VectorIndex2` [in]

Index that determines which vector in [XMVectorSelect](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselect) will be selected. If zero, the first vector's third component will be selected. Otherwise, the second vector's component will be selected.

### `VectorIndex3` [in]

Index that determines which vector in [XMVectorSelect](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselect) will be selected. If zero, the first vector's fourth component will be selected. Otherwise, the second vector's component will be selected.

## Return value

Returns the control vector.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR    ControlVector;
const uint32_t  ControlElement[] =
            {
                XM_SELECT_0,
                XM_SELECT_1
            };

assert(VectorIndex0 < 2);
assert(VectorIndex1 < 2);
assert(VectorIndex2 < 2);
assert(VectorIndex3 < 2);

ControlVector.u[0] = ControlElement[VectorIndex0];
ControlVector.u[1] = ControlElement[VectorIndex1];
ControlVector.u[2] = ControlElement[VectorIndex2];
ControlVector.u[3] = ControlElement[VectorIndex3];

return ControlVector;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

#### Examples

Using XMVectorSelectControl

In this example, **XMVectorSelectControl** is used to generate a control mask that will select the x and w components from the first vector and the y and z components from the second.

The vector result will be ( 3.0f, 5.0f, 5.0f, 3.0f ).

```
XMVECTOR three = XMVectorReplicate( 3.0f );
XMVECTOR five = XMVectorReplicate( 5.0f );

XMVECTOR control = XMVectorSelectControl( 0, 1, 1, 0 );
XMVECTOR result = XMVectorSelect( three, five, control );
```

## See also

[Component-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-component-wise)

[XMVectorSelect](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselect)