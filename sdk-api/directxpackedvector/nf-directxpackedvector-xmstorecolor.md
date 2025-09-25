# XMStoreColor function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor).

## Parameters

### `pDestination` [out]

Address at which to store the data.

### `V` [in]

Vector containing the data to store. X contains the Red color channel, Y contains the Green, Z the Blue, and W the Alpha
channel.

## Return value

None.

## Remarks

The function takes a vector, clamps it to the range 0.0f to 1.0f, converts the components into a unsigned, normalized
integer format, packs the components into a 32-bit integer, and writes the result out to the given address. The most
significant component is written to the second most significant eight bits of the integer, and so on.

The following pseudocode demonstrates the operation of the function.

```
XMVector N;

N = saturate(V);
N = scale(N, 255.0f);
N = round(N);

pDestination->c = ((uint32_t)N.w << 24) |
                  ((uint32_t)N.x << 16) |
                  ((uint32_t)N.y << 8) |
                  ((uint32_t)N.z);
```

For Direct3D 10.x and Direct3D 11, this matches the component order for functions that take a float ColorRGBA[4] parameter.

```

 XMVECTOR Yellow = XMVectorSet( 1.0f, 1.0f, 0.0f, 1.0f );

 XMFLOAT4 clrf;
 XMStoreFloat4( &clrf, Yellow );
 pDeviceContext->ClearRenderTargetView( pRTV, (const float*)clrf );

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)