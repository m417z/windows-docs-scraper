# XMStoreUDecN4_XR function

## Description

Stores an extended range [XMUDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudecn4) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type). This type stores a 10:10:10:2 normalized GPU format using the Extended Range (XR) with the color bias set to match DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM.

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
static const XMVECTOR Scale = {510.0f, 510.0f, 510.0f, 3.0f};
static const XMVECTOR Bias = { 384.0f, 384.0f, 384.0f, 0.0f };
static const XMVECTOR C = { 1023.f, 1023.f, 1023.f, 3.f };

assert(pDestination);

N = XMVectorMultiplyAdd( V, Scale, Bias );
N = XMVectorClamp( V, XMVectorZero(), C );

pDestination->v = ((uint32_t)N.v[3] << 30) |
(((uint32_t)N.v[2] & 0x3FF) << 20) |
(((uint32_t)N.v[1] & 0x3FF) << 10) |
(((uint32_t)N.v[0] & 0x3FF));
```

For more details on the Extended Range (XR) with Bias conversion, see [XR_BIAS Color Channel Conversion Rules](https://learn.microsoft.com/windows-hardware/drivers/display/xr-bias-color-channel-conversion-rules).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)

[XMLoadUDecN4_XR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadudecn4_xr)