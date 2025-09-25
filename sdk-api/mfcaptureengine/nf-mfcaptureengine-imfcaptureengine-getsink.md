# IMFCaptureEngine::GetSink

## Description

Gets a pointer to one of the capture sink objects. You can use the capture sinks to configure preview, recording, or still-image capture.

## Parameters

### `mfCaptureEngineSinkType` [in]

An [MF_CAPTURE_ENGINE_SINK_TYPE](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/ne-mfcaptureengine-mf_capture_engine_sink_type) value that specifies the capture sink to retrieve.

### `ppSink` [out]

Receives a pointer to the [IMFCaptureSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesink) interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |

## See also

[IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine)