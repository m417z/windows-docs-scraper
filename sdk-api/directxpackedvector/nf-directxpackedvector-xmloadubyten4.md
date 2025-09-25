# XMLoadUByteN4 function

## Description

Loads an [XMUBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten4) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMUBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten4) structure to load. This parameter must point to cached
memory.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
XMVECTOR vectorOut;

vectorOut.x = (float)pSource->x / 255.0f;
vectorOut.y = (float)pSource->y / 255.0f;
vectorOut.z = (float)pSource->z / 255.0f;
vectorOut.w = (float)pSource->w / 255.0f;
	
return vectorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)