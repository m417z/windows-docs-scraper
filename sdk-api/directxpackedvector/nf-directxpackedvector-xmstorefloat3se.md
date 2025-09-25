# XMStoreFloat3SE function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se).

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

  static const XMVECTOR  Max = { 65472.f, 65427.f, 65427.f, 0 };
  N = XMVectorClamp(V, XMVectorZero(), Max);

  uint32_t m[3], e[3];
  ConvertToFloat14( N.x, &m[0], &e[0]);
  ConvertToFloat14( N.y, &m[1], &e[1]);
  ConvertToFloat14( N.z, &m[2], &e[2]);

  uint32_t T = XMMax( e[0], XMMax( e[1], e[2] ) );

  pDestination->xm = m[0] >> (T - e[0]);
  PDestination->ym = m[1] >> (T - e[1]);
  pDestination->zm = m[2] >> (T - e[2]);
  pDestination->e = T;

```

If the three components are not close to each other in magnitude, the largest value(s) will set the exponent and the
other components will be shifted to zero.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)