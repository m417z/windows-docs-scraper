# XMVectorSetInt function

## Description

Creates a vector with unsigned integer components.

## Parameters

### `x` [in]

**uint32_t** value to assign to the x-component of the returned vector.

### `y` [in]

**uint32_t** value to assign to the y-component of the returned vector.

### `z` [in]

**uint32_t** value to assign to the z-component of the returned vector.

### `w` [in]

**uint32_t** value to assign to the w-component of the returned vector.

## Return value

An instance [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) each of whose four components (*x*,*y*,*z*, and *w*) is an integer with the same value as the corresponding input argument to `XMVectorSetInt`.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR V;
uint32_t x,y,z,w;
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