# IWICBitmapLock\_GetDataPointer\_STA\_Proxy function

Proxy function for the [**GetDataPointer**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmaplock-getdatapointer) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapLock**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmaplock)\***

Pointer to this [**IWICBitmapLock**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmaplock) object.

*pcbBufferSize* \[out\]

Type: **UINT\***

A pointer that receives the size of the buffer.

*ppbData* \[out\]

Type: **BYTE\*\***

A pointer that receives a pointer to the top left pixel in the locked rectangle.

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

