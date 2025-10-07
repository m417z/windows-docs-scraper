# IWICBitmapDecoder\_GetMetadataQueryReader\_Proxy function

Proxy function for the [**GetMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapdecoder-getmetadataqueryreader) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder)\***

Pointer to this [**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder) object.

*ppIMetadataQueryReader* \[out\]

Type: **[**IWICMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataqueryreader)\*\***

A pointer that receives a pointer to the metadata.

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