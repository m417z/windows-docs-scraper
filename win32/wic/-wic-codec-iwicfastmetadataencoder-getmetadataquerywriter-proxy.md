# IWICFastMetadataEncoder\_GetMetadataQueryWriter\_Proxy function

Proxy function for the [**GetMetadataQueryWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicfastmetadataencoder-getmetadataquerywriter) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapFrameDecode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframedecode)\***

Pointer to this [**IWICBitmapFrameDecode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframedecode) object.

*ppIMetadataQueryWriter* \[out\]

Type: **[**IWICMetadataQueryWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataquerywriter)\*\***

A pointer that receives a pointer to the encoder's metadata query writer.

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