# XMVectorSetWPtr function

## Description

Sets the `w` component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) containing floating-point data, with a value
contained in an instance of float referred to by a pointer.

## Parameters

### `V`

A valid 4D vector storing floating-point data.

### `w` [in]

Pointer to a float containing the value to be stored in the `w` element of the [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) object `V`.

## Return value

An instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) whose *w* component has been set to the floating-point value
provided by the argument *w* to `XMVectorSetWPtr`. All other components of the returned
**XMVECTOR Data Type** instance have the same value as those of the input vector *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Accessor Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-accessors)