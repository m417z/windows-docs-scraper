# IWICBitmapLock\_GetStride\_Proxy function

Proxy function for the [**GetStride**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmaplock-getstride) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapLock**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmaplock)\***

Pointer to this [**IWICBitmapLock**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmaplock) object.

*pcbStride* \[out\]

Type: **UINT\***

The bitmap stride.

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