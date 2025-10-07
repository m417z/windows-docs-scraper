# IWICMetadataQueryReader\_GetMetadataByName\_Proxy function

Proxy function for the [**GetMetadataByName**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicmetadataqueryreader-getmetadatabyname) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataqueryreader)\***

Pointer to this [**IWICMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataqueryreader) object.

*wzName* \[in\]

Type: **LPCWSTR**

The name of the requested metadata item.

*pvarValue* \[in, out\]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidlbase/ns-propidlbase-propvariant)\***

Pointer that receives the metadata property.

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