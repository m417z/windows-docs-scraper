# IMFMediaTypeHandler::GetMajorType

## Description

Gets the major media type of the object.

## Parameters

### `pguidMajorType` [out]

Receives a GUID that identifies the major type. For a list of possible values, see [Major Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The major type identifies what kind of data is in the stream, such as audio or video. To get the specific details of the format, call [IMFMediaTypeHandler::GetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-getcurrentmediatype).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler)