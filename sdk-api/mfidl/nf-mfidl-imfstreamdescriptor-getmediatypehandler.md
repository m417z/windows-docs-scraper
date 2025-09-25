# IMFStreamDescriptor::GetMediaTypeHandler

## Description

Retrieves a media type handler for the stream. The media type handler can be used to enumerate supported media types for the stream, get the current media type, and set the media type.

## Parameters

### `ppMediaTypeHandler` [out]

Receives a pointer to the [IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFStreamDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamdescriptor)

[Presentation Descriptors](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptors)