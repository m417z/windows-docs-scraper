# IWICMetadataQueryReader\_GetEnumerator\_Proxy function

Proxy function for the [**GetEnumerator**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicmetadataqueryreader-getenumerator) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataqueryreader)\***

Pointer to this [**IWICMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataqueryreader) object.

*ppIEnumString* \[out\]

Type: **IEnumString\*\***

A pointer that receives a pointer to a metadata enumerator.

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

