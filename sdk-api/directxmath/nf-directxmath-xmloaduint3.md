# XMLoadUInt3 function

## Description

Loads unsigned integer data into the x, y, and z components
of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type), without type checking.

## Parameters

### `pSource` [in]

Address of an [XMUINT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmuint3) structure containing the data to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

For 16-byte aligned memory, it may be faster to use [XMLoadInt3A](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloadint3a) with a casting operator.

The following pseudocode shows the operation of this function.

```

XMVECTOR vectorOut;

vectorOut.x = (float)pSource->x;
vectorOut.y = (float)pSource->y;
vectorOut.z = (float)pSource->z;
vectorOut.w = 0;

return vectorOut;

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)