# IWICMetadataQueryReader\_GetLocation\_Proxy function

Proxy function for the [**GetLocation**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicmetadataqueryreader-getlocation) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataqueryreader)\***

Pointer to this [**IWICMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataqueryreader) object.

*cchMaxLength* \[in\]

Type: **UINT**

The length of the *wzNamespace* buffer.

*wzNamespace* \[in, out\]

Type: **WCHAR\***

Pointer that receives the current namespace location.

*pcchActualLength* \[out\]

Type: **UINT\***

The actual buffer length needed to retrieve the current namespace location.

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