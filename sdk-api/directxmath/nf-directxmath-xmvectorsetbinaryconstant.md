# XMVectorSetBinaryConstant function

## Description

Creates a vector, each of whose components is either 0.0f or 1.0f.

## Parameters

### `C0` [in]

This parameter must be a number (an immediate value, either 0 or 1) and not a variable. If *C0* is 0, the
x-component of the returned vector will be 0.0f. Otherwise, the x-component will be 1.0f.

### `C1` [in]

This parameter must be a number (an immediate value, either 0 or 1) and not a variable. If *C1* is 0, the
y-component of the returned vector will be 0.0f. Otherwise, the y-component will be 1.0f.

### `C2` [in]

This parameter must be a number (an immediate value, either 0 or 1) and not a variable. If *C2* is 0, the
z-component of the returned vector will be 0.0f. Otherwise, the z-component will be 1.0f.

### `C3` [in]

This parameter must be a number (an immediate value, either 0 or 1) and not a variable. If *C3* is 0, the
w-component of the returned vector will be 0.0f. Otherwise, the w-component will be 1.0f.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type), each of whose components is either 0.0f or 1.0f.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Initialization Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-initialization)

[XMVectorSetInt](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsetint)

[XMVectorSplatConstant](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsplatconstant)

[XMVectorSplatConstantInt](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsplatconstantint)