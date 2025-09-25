# XMLoadUDecN4_XR function

## Description

Loads an extended range [XMUDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudecn4) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type). This type loads a 10:10:10:2 normalized GPU format using the Extended Range (XR) with the color bias set to match DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM.

## Parameters

### `pSource` [in]

Address of the [XMUDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudecn4) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
XMVECTOR vectorOut;

int32_t Element;

Element = pSource->v & 0x3FF;
vectorOut.x = (float)(Element - 0x180) / 510.f;
Element = (pSource->v >> 10) & 0x3FF;
vectorOut.y = (float)(Element - 0x180) / 510.f;
Element = (pSource->v >> 20) & 0x3FF;
vectorOut.z = (float)(Element - 0x180) / 510.f;
vectorOut.w = (float)(pSource->v >> 30) / 3.f;

return vectorOut;
```

For more details on the Extended Range (XR) with Bias conversion, see [XR_BIAS Color Channel Conversion Rules](https://learn.microsoft.com/windows-hardware/drivers/display/xr-bias-color-channel-conversion-rules).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)

[XMStoreUDecN4_XR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreudecn4_xr)