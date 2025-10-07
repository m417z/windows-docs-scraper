# IWICMetadataBlockReader\_GetReaderByIndex\_Proxy function

Proxy function for the [**GetReaderByIndex**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nf-wincodecsdk-iwicmetadatablockreader-getreaderbyindex) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICMetadataBlockReader**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwicmetadatablockreader)\***

Pointer to this [**IWICMetadataBlockReader**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwicmetadatablockreader) object.

*nIndex* \[in\]

Type: **UINT**

*ppIMetadataReader* \[out\]

Type: **[**IWICMetadataReader**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwicmetadatareader)\*\***

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