# XMVectorSet function

## Description

Creates a vector using four floating-point values.

## Parameters

### `x` [in]

The x component of the vector to return.

### `y` [in]

The y component of the vector to return.

### `z` [in]

The z component of the vector to return.

### `w` [in]

The w component of the vector to return.

## Return value

An instance [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) each of whose four components
(*x*,*y*,*z*, and *w*) is a
floating-point number with the same value as the corresponding input argument to
`XMVectorSet`.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR V;
float x,y,z,w;
V.x = x;
V.y = y;
V.z = z;
V.w = w;

return V;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Initialization Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-initialization)