# XMVectorSetIntZPtr function

## Description

Sets the `z` component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) containing integer data, with a value
contained in an instance of uint32_t referred to by a pointer.

## Parameters

### `V`

A valid 4D vector storing integer data.

### `z` [in]

Pointer to a uint32_t containing the value to be stored in the `z` element of the [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) object `V`.

## Return value

An instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) whose *z* component has been set to the integer value pointed to by
the argument *z* of `XMVectorSetIntZPtr`. All other components of the returned **XMVECTOR Data Type** instance have the same value as those of the input vector *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Accessor Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-accessors)