# IMFCaptureEngine::StopRecord

## Description

Stops recording.

## Parameters

### `bFinalize` [in]

A Boolean value that specifies whether to finalize the output file. To create a valid output file, specify **TRUE**. Specify **FALSE** only if you want to interrupt the recording and discard the output file. If the value is **FALSE**, the operation completes more quickly, but the file will not be playable.

### `bFlushUnprocessedSamples` [in]

A Boolean value that specifies if the unprocessed samples waiting to be encoded should be flushed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is asynchronous. If the method returns a success code, the caller will receive an **MF_CAPTURE_ENGINE_RECORD_STOPPED** event through the [IMFCaptureEngineOnEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengineoneventcallback-onevent) method. The operation can fail asynchronously after the method succeeds. If so, the error code is conveyed through the **OnEvent** method.

## See also

[IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine)