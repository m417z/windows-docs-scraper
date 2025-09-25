# XMStoreFloat3PK function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in a [XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk).

## Parameters

### `pDestination` [out]

Address at which to store the data.

### `V` [in]

Vector containing the data to store.

## Return value

None.

## Remarks

The following pseudocode demonstrates the operation of the function.

```

  XMVECTOR N;

  static const XMVECTOR  Max = { 65024.f, 65024.f, 64512.f, 0 };
  N = XMVectorClamp(V, XMVectorZero(), Max);

  ConvertToFloat11( N.x, &pDestination->xm, &pDestination->xe);
  ConvertToFloat11( N.y, &pDestination->ym, &pDestination->ye);
  ConvertToFloat10( N.z, &pDestination->zm, &pDesitnation->ze);

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)