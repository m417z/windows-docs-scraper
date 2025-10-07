# WICCreateImagingFactory\_Proxy function

Proxy function for creating the [**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory).

## Parameters

*SDKVersion* \[in\]

Type: **UINT**

*ppIImagingFactory* \[out\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\*\***

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is a helper for creating a WIC factory for explicit DLL linking, which was needed for Windows XP. In normal usage, you would use [**CoCreateInstance**](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) instead (see [WIC API class factories](https://learn.microsoft.com/windows/win32/wic/-wic-api#class-factories)), since that's always included in all newer versions of Windows.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Windowscodecs.dll;

windowscodecs.lib |