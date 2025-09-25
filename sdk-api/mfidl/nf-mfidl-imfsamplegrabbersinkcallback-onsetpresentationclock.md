# IMFSampleGrabberSinkCallback::OnSetPresentationClock

## Description

Called when the presentation clock is set on the sample-grabber sink.

## Parameters

### `pPresentationClock` [in]

Pointer to the presentation clock's [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method should return quickly, or it might interfere with playback. Do not block the thread, wait on events, or perform other lengthy operations inside this method.

## See also

[IMFSampleGrabberSinkCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsamplegrabbersinkcallback)