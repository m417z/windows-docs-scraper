# IWICComponentFactory\_CreateQueryWriterFromBlockWriter\_Proxy function

Proxy function for the [**CreateQueryWriterFromBlockWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nf-wincodecsdk-iwiccomponentfactory-createquerywriterfromblockwriter) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICComponentFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwiccomponentfactory)\***

Pointer to this [**IWICComponentFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwiccomponentfactory) object.

*pIBlockWriter* \[in\]

Type: **[**IWICMetadataBlockWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodecsdk/nn-wincodecsdk-iwicmetadatablockwriter)\***

*ppIQueryWriter* \[out\]

Type: **[**IWICMetadataQueryWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataquerywriter)\*\***

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

