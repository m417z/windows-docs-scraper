# IWICImagingFactory\_CreateDecoderFromStream\_Proxy function

Proxy function for the [**CreateDecoderFromStream**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createdecoderfromstream) method.

## Parameters

*pFactory* \[in\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\***

*pIStream* \[in\]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)\***

The stream to create the decoder from.

*pguidVendor* \[in\]

Type: **const GUID\***

The vendor GUID for the decoder .

*metadataOptions* \[in\]

Type: **[**WICDecodeOptions**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicdecodeoptions)**

The [**WICDecodeOptions**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicdecodeoptions) to use when creating the decoder.

*ppIDecoder* \[out\]

Type: **[**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder)\*\***

A pointer that receives a pointer to a new [**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder).

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