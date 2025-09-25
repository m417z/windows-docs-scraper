# XMLoadFloat3PK function

## Description

Loads an [XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The following pseudocode demonstrates the operation of the function.

```

  XMVECTOR vectorOut;

  float xscale = powf( 2, (float)pSource->xe - 15);
  vectorOut.x = ((float)pSource->xm / 64.0f)*xscale;

  float yscale = powf( 2, (float)pSource->ye - 15);
  vectorOut.y = ((float)pSource->ym / 64.0f)*yscale;

  float zscale = powf( 2, (float)pSource->ze - 15);
  vectorOut.z = ((float)pSource->zm / 32.0f)*zscale;

  vectorOut.w = 0;

  return vectorOut;

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)