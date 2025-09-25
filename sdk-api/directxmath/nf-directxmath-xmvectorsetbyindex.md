# XMVectorSetByIndex function

## Description

Use a floating-point object to set the value of one of the four components of an [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) containing
integer data referenced by an index.

## Parameters

### `V`

A [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) containing integer data.

### `f`

The floating point value used to set the *i* component of the returned [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

### `i`

The index of the component to be retrieved.

## Return value

An instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) whose *i* component has been set to the floating-point value
provided by the argument *f*. All other components of the returned **XMVECTOR Data Type** instance
have the same value as those of the input vector *V*.

## Remarks

The value of *i* must be positive and less than or equal to three ( *0*  <=  *i*  <=
 *3* ).

The indexes have the following correspondence with [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) vector components:

| Index | Component |
| --- | --- |
| `0` | `x` |
| `1` | `y` |
| `2` | `z` |
| `3` | `w` |

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Accessor Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-accessors)

[XMVectorGetByIndex](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh404786(v=vs.85))

[XMVectorSetByIndexPtr](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsetbyindexptr)