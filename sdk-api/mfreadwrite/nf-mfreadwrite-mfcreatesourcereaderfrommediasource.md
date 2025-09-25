# MFCreateSourceReaderFromMediaSource function

## Description

Creates the source reader from a media source.

## Parameters

### `pMediaSource` [in]

A pointer to the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) interface of a media source.

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. You can use this parameter to configure the source reader. For more information, see [Source Reader Attributes](https://learn.microsoft.com/windows/desktop/medfound/source-reader-attributes). This parameter can be **NULL**.

### `ppSourceReader` [out]

Receives a pointer to the [IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_DRM_UNSUPPORTED**** | The source contains protected content. |

## Remarks

Call **CoInitialize(Ex)** and [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) before calling this function.

By default, when the application releases the source reader, the source reader shuts down the media source by calling [IMFMediaSource::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) on the media source. At that point, the application can no longer use the media source.

To change this default behavior, set the [MF_SOURCE_READER_DISCONNECT_MEDIASOURCE_ON_SHUTDOWN](https://learn.microsoft.com/windows/desktop/medfound/mf-source-reader-disconnect-mediasource-on-shutdown) attribute in the *pAttributes* parameter. If this attribute is **TRUE**, the application is responsible for shutting down the media source.

When using the Source Reader, do not call any of the following methods on the media source:

* [IMFMediaSource::Pause](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-pause)
* [IMFMediaSource::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-start)
* [IMFMediaSource::Stop](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-stop)
* All [IMFMediaEventGenerator](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventgenerator) methods

This function is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)