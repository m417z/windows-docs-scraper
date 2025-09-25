# XMVectorSetIntZ function

## Description

Set the value of the `z` component of an [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `V` [in]

A valid 4D unsigned integer vector.

### `z` [in]

A unsigned integer value to be assigned to `z` of *V*.

## Return value

An instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) whose *z* component has been set to the integer value provided by
the argument *z* to `XMVectorSetIntZ`. All other components of the returned **XMVECTOR Data Type** instance have the same value as those of the input vector *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Accessor Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-accessors)