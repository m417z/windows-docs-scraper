# MFCreateSampleGrabberSinkActivate function

## Description

Creates an activation object for the sample grabber media sink.

## Parameters

### `pIMFMediaType`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface, defining the media type for the sample grabber's input stream.

### `pIMFSampleGrabberSinkCallback`

Pointer to the [IMFSampleGrabberSinkCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsamplegrabbersinkcallback) interface of a callback object. The caller must implement this interface.

### `ppIActivate`

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. Use this interface to complete the creation of the sample grabber. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To create the sample grabber sink, call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) on the pointer received in the *ppIActivate* parameter.

Before calling [ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject), you can configure the sample grabber by setting any of the following attributes on the *ppIActivate* pointer:

* [MF_SAMPLEGRABBERSINK_IGNORE_CLOCK](https://learn.microsoft.com/windows/desktop/medfound/mf-samplegrabbersink-ignore-clock)
* [MF_SAMPLEGRABBERSINK_SAMPLE_TIME_OFFSET](https://learn.microsoft.com/windows/desktop/medfound/mf-samplegrabbersink-sample-time-offset-attribute)

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)