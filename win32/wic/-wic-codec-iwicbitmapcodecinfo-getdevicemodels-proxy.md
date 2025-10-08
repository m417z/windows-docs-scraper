# IWICBitmapCodecInfo\_GetDeviceModels\_Proxy function

Proxy function for the [**GetDeviceModels**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapcodecinfo-getdevicemodels) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapCodecInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapcodecinfo)\***

Pointer to this [**IWICBitmapCodecInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapcodecinfo) object.

*cchDeviceModels* \[in\]

Type: **UINT**

The size of the device models buffer.

*wzDeviceModels* \[in, out\]

Type: **WCHAR\***

A pointer that receives a comma delimited list of device model names associated with the codec.

*pcchActual* \[in, out\]

Type: **UINT\***

The actual buffer size needed to retrieve all of the device model names.

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

