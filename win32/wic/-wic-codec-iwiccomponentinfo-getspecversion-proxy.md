# IWICComponentInfo\_GetSpecVersion\_Proxy function

Proxy function for the [**GetSpecVersion**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwiccomponentinfo-getspecversion) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICComponentInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccomponentinfo)\***

Pointer to this [**IWICComponentInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccomponentinfo) object.

*cchSpecVersion* \[in\]

Type: **UINT**

The size of the *wzSpecVersion* buffer.

*wzSpecVersion* \[in, out\]

Type: **WCHAR\***

When this method returns, contain a culture invarient string of the component's specification version. The version form is NN.NN.NN.NN.

*pcchActual* \[out\]

Type: **UINT\***

A pointer that receives the actual length of the component's specification version.

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