# MFCreateMP3ByteStreamPlugin function

\[This API is not supported and may be altered or unavailable in the future. Instead, applications should use the [Source Resolver](https://learn.microsoft.com/windows/win32/medfound/source-resolver) to create the MP3 media source.\]

Creates a byte-stream handler for the MP3 media source.

## Parameters

*riid* \[in\]

The interface identifier (IID) of the requested interface. Set this parameter to **IID\_IMFByteStreamHandler** to receive a pointer to the [**IMFByteStreamHandler**](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamhandler) interface.

*ppvHandler* \[out\]

Receives a pointer to the interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function has no associated import library. To call this function, you must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to mf.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| End of client support<br> | Windows Vista<br> |
| End of server support<br> | Windows Server 2008<br> |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/win32/medfound/media-foundation-functions)

[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/win32/medfound/scheme-handlers-and-byte-stream-handlers)

[Source Resolver](https://learn.microsoft.com/windows/win32/medfound/source-resolver)

