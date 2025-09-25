# XMVectorGetIntByIndexPtr function

## Description

Retrieve, into an instance of an integer referenced by pointer, the value of one of the four components of an
[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) containing integer data by index.

## Parameters

### `x` [out]

Pointer to an instance of an integer object that will receive the value of the *i* component of the
[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) object `V`.

### `V`

A [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) containing integer data.

### `i`

The index of the component to be retrieved.

## Return value

None.

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

[XMVectorGetIntByIndex](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh404788(v=vs.85))

[XMVectorSetIntByIndexPtr](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsetintbyindexptr)