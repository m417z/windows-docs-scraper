# XMLoadFloat3SE function

## Description

Loads an [XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The following pseudocode demonstrates the operation of the function.

```

  XMVECTOR vectorOut;

  float scale = powf( 2, (float)pSource->e - 15);

  vectorOut.x = ((float)pSource->xm / 512.0f)*scale;
  vectorOut.y = ((float)pSource->ym / 512.0f)*scale;
  vectorOut.z = ((float)pSource->zm / 512.0f)*scale;
  vectorOut.w = 0;

  return vectorOut;

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)