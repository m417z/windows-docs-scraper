# IMFCaptureSink::AddStream

## Description

Connects a stream from the capture source to this capture sink.

## Parameters

### `dwSourceStreamIndex` [in]

The source stream to connect. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. To get the number of streams, call [IMFCaptureSource::GetDeviceStreamCount](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-getdevicestreamcount). |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_PHOTO_STREAM**<br><br>0xFFFFFFFB | The first image stream. |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

### `pMediaType` [in]

An [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) pointer that specifies the desired format of the output stream. The details of the format will depend on the capture sink.

* Photo sink: A still image format compatible with [Windows Imaging Component](https://learn.microsoft.com/windows/desktop/wic/-wic-lh) (WIC).
* Preview sink: An uncompressed audio or video format.
* Record sink: The audio or video format that will be written to the output file.

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. For compressed streams, you can use this parameter to configure the encoder. This parameter can also be **NULL**.

For the preview sink, set this parameter to **NULL**.

### `pdwSinkStreamIndex` [out]

Receives the index of the new stream on the capture sink. Note that this index will not necessarily match the value of *dwSourceStreamIndex*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDMEDIATYPE** | The format specified in *pMediaType* is not valid for this capture sink. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwSourceStreamIndex* parameter is invalid, or the specified source stream was already connected to this sink. |

## See also

[IMFCaptureSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesink)