# XMVectorSetIntY function

## Description

Set the value of the `y` component of an [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `V` [in]

A valid 4D vector storing integer data.

### `y` [in]

An integer value to be assigned to `y` of *V*.

## Return value

An instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) whose *y* component has been set to the integer value provided by
the argument *y* to `XMVectorSetIntY`. All other components of the returned **XMVECTOR Data Type** instance have the same value as those of the input vector *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Accessor Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-accessors)