# IWICBitmapFlipRotator\_Initialize\_Proxy function

Proxy function for the [**Initialize**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapfliprotator-initialize) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapFlipRotator**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapfliprotator)\***

Pointer to this [**IWICBitmapFlipRotator**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapfliprotator) object.

*pISource* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

The input bitmap source.

*options* \[in\]

Type: **[**WICBitmapTransformOptions**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmaptransformoptions)**

The [**WICBitmapTransformOptions**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmaptransformoptions) to flip or rotate the image.

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