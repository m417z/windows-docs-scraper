# IMFSampleGrabberSinkCallback2::OnProcessSampleEx

## Description

Called when the sample-grabber sink receives a new media sample.

## Parameters

### `guidMajorMediaType` [in]

The major type GUID that specifies the format of the data. For a list of possible values, see [Major Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).

### `dwSampleFlags` [in]

Sample flags. The sample-grabber sink gets the value of this parameter by calling the [IMFSample::GetSampleFlags](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-getsampleflags) method of the media sample.

### `llSampleTime` [in]

The presentation time for this sample, in 100-nanosecond units. If the sample does not have a presentation time, the value of this parameter is **_I64_MAX**

### `llSampleDuration` [in]

The duration of the sample, in 100-nanosecond units.

If the sample does not have a duration, the value of this parameter is **_I64_MAX**.

### `pSampleBuffer` [in]

A pointer to a buffer that contains the sample data.

### `dwSampleSize` [in]

The size, in bytes, of the *pSampleBuffer* buffer.

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. Use this interface to get the attributes for this sample (if any). For a list of sample attributes, see [Sample Attributes](https://learn.microsoft.com/windows/desktop/medfound/sample-attributes).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you use the sample-grabber sink in a playback topology, this method should return quickly, or it might interfere with playback. Do not block the thread, wait on events, or perform other lengthy operations inside this method.

## See also

[IMFSampleGrabberSinkCallback2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsamplegrabbersinkcallback2)