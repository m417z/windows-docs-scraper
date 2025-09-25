# MFCreateASFStreamingMediaSink function

## Description

Creates an activation object for the ASF streaming sink.

The ASF streaming sink enables an application to write streaming Advanced Systems Format (ASF) packets to an HTTP byte stream.

## Parameters

### `pIByteStream`

 A pointer to a byte stream object in which the ASF media sink writes the streamed content.

### `ppIMediaSink`

Receives a pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface of the ASF streaming-media sink object. To create the media sink, the application must call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) on the received pointer. The caller must release the interface pointer.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To create the ASF streaming sink in another process, call [MFCreateASFStreamingMediaSinkActivate](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-mfcreateasfstreamingmediasinkactivate).

An application can get a pointer to the [ASF ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/asf-contentinfo-object) by calling **IUnknown::QueryInterface** on the media sink object received in the *ppIMediaSink* parameter. The ContentInfo object is used to set the encoder configuration settings, provide stream properties supplied by an ASF profile, and add metadata information. These configuration settings populate the various ASF header objects of the encoded ASF file. For more information, see
[Setting Properties in the ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/setting-properties-in-the-contentinfo-object).

#### Examples

The following code example shows how to create a media sink for an ASF source. This example copies the stream configuration settings from the source to the ContentInfo object that represents the ASF header object of the output file.

```cpp
//  Creates an an instance of the ASF streaming sink.

HRESULT CreateASFStreamingSink(
    IMFMediaSource *pSource,
    IMFByteStream  *pOutputByteStream,
    IMFMediaSink   **ppMediaSink
    )
{
    IMFPresentationDescriptor* pSourcePD = NULL;
    IMFASFProfile* pASFProfile = NULL;;
    IMFMediaSink* pMediaSink = NULL;
    IMFASFContentInfo* pASFContentInfo = NULL;

    // Create the streaming media sink for the ASF file
    HRESULT hr = MFCreateASFStreamingMediaSink(pOutputByteStream, &pMediaSink);
    if (FAILED(hr))
    {
        goto done;
    }

    //
    // Transfer the ASF profile from the media source to the sink.
    //

    // Get the presentation descriptor from the source.
    hr = pSource->CreatePresentationDescriptor(&pSourcePD);
    if (FAILED(hr))
    {
        goto done;
    }

    // Convert the presentation descriptor to an ASF profile.
    hr = MFCreateASFProfileFromPresentationDescriptor(pSourcePD, &pASFProfile);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = pMediaSink->QueryInterface(IID_PPV_ARGS(&pASFContentInfo));
    if (FAILED(hr))
    {
        goto done;
    }

    // Set the profile on the sink.
    hr = pASFContentInfo->SetProfile(pASFProfile);
    if (FAILED(hr))
    {
        goto done;
    }

    *ppMediaSink = pMediaSink;
    (*ppMediaSink)->AddRef();

done:
    SafeRelease(&pSourcePD);
    SafeRelease(&pASFProfile);
    SafeRelease(&pASFContentInfo);
    SafeRelease(&pMediaSink);
    return hr;
}

```

## See also

[MFCreateASFStreamingMediaSinkActivate](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-mfcreateasfstreamingmediasinkactivate)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)