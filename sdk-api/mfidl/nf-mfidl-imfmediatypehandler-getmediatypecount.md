# IMFMediaTypeHandler::GetMediaTypeCount

## Description

Retrieves the number of media types in the object's list of supported media types.

## Parameters

### `pdwTypeCount` [out]

Receives the number of media types in the list.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get the supported media types, call [IMFMediaTypeHandler::GetMediaTypeByIndex](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-getmediatypebyindex).

For a media source, the media type handler for each stream must contain at least one supported media type. For media sinks, the media type handler for each stream might contain zero media types. In that case, the application must provide the media type. To test whether a particular media type is supported, call [IMFMediaTypeHandler::IsMediaTypeSupported](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-ismediatypesupported).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler)