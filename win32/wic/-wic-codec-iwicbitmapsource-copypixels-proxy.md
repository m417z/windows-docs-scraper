# IWICBitmapSource\_CopyPixels\_Proxy function

Proxy function for the [**CopyPixels**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapsource-copypixels) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

Pointer to this [**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource) object.

*prc* \[in\]

Type: **const [**WICRect**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ns-wincodec-wicrect)\***

The rectangle to copy. A NULL value specifies the entire bitmap.

*cbStride* \[in\]

Type: **UINT**

The stride of the bitmap

*cbBufferSize* \[in\]

Type: **UINT**

The size of the buffer.

*pbBuffer* \[out\]

Type: **BYTE\***

A pointer to the buffer.

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