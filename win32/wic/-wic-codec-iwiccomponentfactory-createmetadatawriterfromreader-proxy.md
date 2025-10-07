# IWICComponentFactory\_CreateMetadataWriterFromReader\_Proxy function

Proxy function for the [**CreateMetadataWriterFromReader**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nf-wincodecsdk-iwiccomponentfactory-createmetadatawriterfromreader) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICComponentFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwiccomponentfactory)\***

Pointer to this [**IWICComponentFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwiccomponentfactory) object.

*pIReader* \[in\]

Type: **[**IWICMetadataReader**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwicmetadatareader)\***

*pguidVendor* \[in\]

Type: **const GUID\***

*ppIWriter* \[out\]

Type: **[**IWICMetadataWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwicmetadatawriter)\*\***

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