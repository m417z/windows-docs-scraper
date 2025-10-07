# IWICBitmapFrameEncode\_SetResolution\_Proxy function

Proxy function for the [**SetResolution**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapframeencode-setresolution) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode)\***

Pointer to this [**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode) object.

*dpiX* \[in\]

Type: **double**

The horizontal resolution value.

*dpiY* \[in\]

Type: **double**

The vertical resolution value.

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