# XMLoadU555 function

## Description

Loads an [XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The following pseudocode demonstrates the operation of the function.

```

XMVECTOR vectorOut;

vectorOut.x = (float)pSource->x;
vectorOut.y = (float)pSource->y;
vectorOut.z = (float)pSource->z;
vectorOut.w = (float)pSource->w;

return vectorOut;

```

Note these are not normalized values. To convert to the RGBA 5/5/5/1 format,
you must scale the resulting vector by `(1.f/31.f, 1.f/31.f, 1.f/31.f, 1.f)`.
Also, you will probably need to swizzle the standard .x = RED, .y = GREEN, .z =
BLUE, .w = ALPHA color vector's .x and .z value since the GPU format is BGR (not RGB).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)