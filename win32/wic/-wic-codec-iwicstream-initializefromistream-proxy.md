# IWICStream\_InitializeFromIStream\_Proxy function

Proxy function for the [**InitializeFromIStream**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicstream-initializefromistream) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICStream**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicstream)\***

Pointer to this [**IWICStream**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicstream) object.

*pIStream* \[in\]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)\***

The initialize stream.

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

