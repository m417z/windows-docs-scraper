# IWICMetadataQueryWriter\_SetMetadataByName\_Proxy function

Proxy function for the [**SetMetadataByName**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicmetadataquerywriter-setmetadatabyname) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICMetadataQueryWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataquerywriter)\***

Pointer to this [**IWICMetadataQueryWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataquerywriter) object.

*wzName* \[in\]

Type: **LPCWSTR**

The name of the metadata item.

*pvarValue* \[in\]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidlbase/ns-propidlbase-propvariant)\***

The metadata to set.

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