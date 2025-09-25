# IMFSampleGrabberSinkCallback::OnProcessSample

## Description

Called when the sample-grabber sink receives a new media sample.

## Parameters

### `guidMajorMediaType` [in]

The major type that specifies the format of the data. For a list of possible values, see [Major Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).

### `dwSampleFlags` [in]

Reserved.

### `llSampleTime` [in]

The presentation time for this sample, in 100-nanosecond units.
If the sample does not have a presentation time, the value of this parameter is **_I64_MAX**.

### `llSampleDuration` [in]

The duration of the sample, in 100-nanosecond units.
If the sample does not have a duration, the value of this parameter is **_I64_MAX**.

### `pSampleBuffer` [in]

A pointer to a buffer that contains the sample data.

### `dwSampleSize` [in]

Size of the *pSampleBuffer* buffer, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you use the sample-grabber sink in a playback topology, this method should return quickly, or it might interfere with playback. Do not block the thread, wait on events, or perform other lengthy operations inside this method.

## See also

[IMFSampleGrabberSinkCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsamplegrabbersinkcallback)