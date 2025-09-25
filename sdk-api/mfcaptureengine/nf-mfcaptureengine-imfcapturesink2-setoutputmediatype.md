# IMFCaptureSink2::SetOutputMediaType

## Description

Dynamically sets the output media type of the record sink or preview sink.

## Parameters

### `dwStreamIndex` [in]

The stream index to change the output media type on.

### `pMediaType` [in]

The new output media type.

### `pEncodingAttributes` [in]

The new encoder attributes. This can be **null**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded |
| **MF_E_INVALID_MEDIATYPE** | The sink does not support the media type. |

## Remarks

This is an asynchronous call. Listen to the [MF_CAPTURE_ENGINE_OUTPUT_MEDIA_TYPE_SET](https://learn.microsoft.com/windows/desktop/medfound/mf-capture-engine-output-media-type-set) event
to be notified when the output media type has been set.

## See also

[IMFCaptureSink2](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesink2)