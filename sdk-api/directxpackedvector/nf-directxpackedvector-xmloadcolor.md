# XMLoadColor function

## Description

Loads an [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter with X containing
the Red color channel, Y containing the Green, Z the Blue, and W the Alpha channel. The values in the components range from 0 to 1.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
XMVECTOR vectorOut;

vectorOut.x = (float)((pSource->c >> 16) & 0xFF) / 255.0f;
vectorOut.y = (float)((pSource->c >> 8) & 0xFF) / 255.0f;
vectorOut.z = (float)((pSource->c >> 0) & 0xFF) / 255.0f;
vectorOut.w = (float)((pSource->c >> 24) & 0xFF) / 255.0f;

return vectorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)