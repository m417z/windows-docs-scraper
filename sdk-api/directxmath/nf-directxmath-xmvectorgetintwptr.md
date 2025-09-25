# XMVectorGetIntWPtr function

## Description

Retrieves the `w` component of an [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) containing integer data, and stores that
component's value in an instance of uint32_t referred to by a pointer.

## Parameters

### `w` [out]

Pointer to a uint32_t that will receive the value of the `w` element of the [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) object
`V`.

### `V`

A valid 4D vector storing integer data.

## Return value

None.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Accessor Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-accessors)