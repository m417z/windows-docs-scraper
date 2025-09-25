# XMStoreU555 function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555).

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
  static const XMVECTOR  Max = {31.f, 31.f, 31.f, 1.0f };

  N = XMVectorClamp(V, XMVectorZero, Max);
  N = XMVectorRound(N);

  pDestination->x = (int8_t)N.v[0];
  pDestination->y = (int8_t)N.v[1];
  pDestination->z = (int8_t)N.v[2];
  pDestination->w = (int8_t)N.v[3];

```

Note these are not normalized values. To convert to the RGBA 5/5/5/1 format,
you must scale the input vector by `(31.f, 31.f, 31.f, 1.f)`.
Also, you will probably need to swizzle
the standard .x = RED, .y = GREEN, .z = BLUE, .w = ALPHA color vector's .x and .z value
since the GPU format is BGR (not RGB).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)