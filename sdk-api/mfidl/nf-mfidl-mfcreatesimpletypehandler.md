# MFCreateSimpleTypeHandler function

## Description

Creates a media-type handler that supports a single media type at a time.

## Parameters

### `ppHandler` [out]

Receives a pointer to the [IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler) interface of the media-type handler. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The media-type handler created by this function supports one media type at a time. Set the media type by calling [IMFMediaTypeHandler::SetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-setcurrentmediatype). After the type is set, [IMFMediaTypeHandler::IsMediaTypeSupported](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-ismediatypesupported) always checks against that type.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)