# IWICBitmapScaler\_Initialize\_Proxy function

Proxy function for the [**Initialize**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapscaler-initialize) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapScaler**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapscaler)\***

Pointer to this [**IWICBitmapScaler**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapscaler) object.

*pISource* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

The input bitmap source.

*uiWidth* \[in\]

Type: **UINT**

The destination width.

*uiHeight* \[in\]

Type: **UINT**

The desination height.

*mode* \[in\]

Type: **[**WICBitmapInterpolationMode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmapinterpolationmode)**

The interpolation mode to use when scaling.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Windowscodecs.dll;

Wincodec.lib |