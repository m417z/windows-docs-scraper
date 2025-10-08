# IWICComponentInfo\_GetCLSID\_Proxy function

Proxy function for the [**GetCLSID**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwiccomponentinfo-getclsid) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICComponentInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccomponentinfo)\***

Pointer to this [**IWICComponentInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccomponentinfo) object.

*pclsid* \[out\]

Type: **CLSID\***

A pointer that receives the component's CLSID.

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

