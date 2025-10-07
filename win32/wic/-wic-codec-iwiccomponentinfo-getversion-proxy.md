# IWICComponentInfo\_GetVersion\_Proxy function

Proxy function for the [**GetVersion**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwiccomponentinfo-getversion) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICComponentInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccomponentinfo)\***

Pointer to this [**IWICComponentInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccomponentinfo) object.

*cchVersion* \[in\]

Type: **UINT**

The size of the *wzVersion* buffer.

*wzVersion* \[in, out\]

Type: **WCHAR\***

A pointer that receives a culture invariant string of the component's version.

*pcchActual* \[out\]

Type: **UINT\***

A pointer that receives the actual length of the component's version.

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