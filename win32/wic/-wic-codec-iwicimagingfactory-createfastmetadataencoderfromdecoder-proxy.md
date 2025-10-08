# IWICImagingFactory\_CreateFastMetadataEncoderFromDecoder\_Proxy function

Proxy function for the [**CreateFastMetadataEncoderFromDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createfastmetadataencoderfromdecoder) method.

## Parameters

*pFactory* \[in\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\***

*pIDecoder* \[in\]

Type: **[**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder)\***

The decoder to create the [**IWICFastMetadataEncoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicfastmetadataencoder) from.

*ppIFME* \[out\]

Type: **[**IWICFastMetadataEncoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicfastmetadataencoder)\*\***

A pointer that receives a pointer to the new [**IWICFastMetadataEncoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicfastmetadataencoder).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Windowscodecs.dll; <br>Wincodec.lib |

