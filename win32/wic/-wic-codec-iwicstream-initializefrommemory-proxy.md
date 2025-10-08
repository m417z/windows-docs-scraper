# IWICStream\_InitializeFromMemory\_Proxy function

Proxy function for the [**InitializeFromMemory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicstream-initializefrommemory) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICStream**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicstream)\***

Pointer to this [**IWICStream**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicstream) object.

*pbBuffer* \[in\]

Type: **BYTE\***

Pointer to the buffer used to initialize the stream.

*cbBufferSize* \[in\]

Type: **DWORD**

The size of buffer.

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

