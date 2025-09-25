# XMLoadUDec4 function

## Description

Loads an [XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
XMVECTOR vectorOut;

return vectorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)