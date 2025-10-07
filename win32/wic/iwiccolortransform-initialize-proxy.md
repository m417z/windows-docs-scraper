# IWICColorTransform\_Initialize\_Proxy function

Initializes an [**IWICColorTransform**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolortransform) with a [**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource) and transforms it from one [**IWICColorContext**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolorcontext) to another.

## Parameters

*pIColorTransform* \[in\]

Type: **[**IWICColorTransform**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolortransform)\***

The color transform to initialize.

*pIBitmapSource* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

The bitmap source used to initialize the color transform.

*pIContextSource* \[in\]

Type: **[**IWICColorContext**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolorcontext)\***

The color context source.

*pIContextDest* \[in\]

Type: **[**IWICColorContext**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolorcontext)\***

The color context destination.

*pixelFmtDest* \[in\]

Type: **REFWICPixelFormatGUID**

The GUID of the desired pixel format.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Requirements

| Requirement | Value |
|----------------|-------------------------------------------------------------------------------------------------|
| DLL<br> | WindowsCodecsExt.dll |

