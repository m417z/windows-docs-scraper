# XMVectorSplatConstantInt function

## Description

Creates a vector with identical integer components.

## Parameters

### `IntConstant` [in]

Value to replicate to each component of the returned vector.

The value of *IntConstant* must satisfy: -16 <= *IntConstant* <=15.

**Note** This parameter must be a number (an immediate value) and not a variable.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type), each of whose components is *IntConstant*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Initialization Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-initialization)

[XMVectorSetBinaryConstant](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsetbinaryconstant)

[XMVectorSetInt](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsetint)

[XMVectorSplatConstant](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsplatconstant)