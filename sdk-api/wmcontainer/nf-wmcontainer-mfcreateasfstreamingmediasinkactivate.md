# MFCreateASFStreamingMediaSinkActivate function

## Description

Creates an activation object for the ASF streaming sink.

The ASF streaming sink enables an application to write streaming Advanced Systems Format (ASF) packets to an HTTP byte stream.
The activation object can be used to create the ASF streaming sink in another process.

## Parameters

### `pByteStreamActivate`

A pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface of an activation object. The caller implements this interface. The [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) method of the activation object must create a byte-stream object. The byte stream exposes the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface. The ASF streaming sink will write data to this byte stream.

### `pContentInfo`

A pointer to an [ASF ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/asf-contentinfo-object) that contains the properties that describe the ASF content. These settings can contain stream settings, encoding properties, and metadata. For more information about these properties, see [Setting Properties in the ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/setting-properties-in-the-contentinfo-object).

### `ppIActivate`

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface of the activation object that is used to create the ASF streaming-media sink. To create the media sink, the application must call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) by using the received pointer. The **ActivateObject** method also calls **IMFActivate::Activate** on the byte stream activate object specified by *pByteStreamActivate*, to create it so that the media sink can write streamed content in the byte stream. The caller must release the **IMFActivate** interface pointer of the media sink activation object received in *ppIActivate*.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Starting in Windows 7, Media Foundation provides an ASF streaming sink that writes the content in a live streaming scenario. This function should be used in secure transcode scenarios where this media sink needs to be created and configured in the remote
process. Like the ASF file sink, the new media sink performs ASF related tasks such as writing the ASF header, generating data packets (muxing). The content is written to a caller-implemented byte stream such as an HTTP byte stream.
The caller must also provide an activation object that media sink can use to create the byte stream remotely.

In addition, it performs transcryption for streaming protected content. It hosts the Windows Media Digital Rights Management (DRM) for Network Devices Output Trust Authority (OTA) that handles the license request and response. For more information, see [IMFDRMNetHelper](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfdrmnethelper) interface.

The new media sink does not perform any time adjustments. If the clock seeks, the timestamps are not changed.

## See also

[MFCreateASFStreamingMediaSink](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-mfcreateasfstreamingmediasink)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)