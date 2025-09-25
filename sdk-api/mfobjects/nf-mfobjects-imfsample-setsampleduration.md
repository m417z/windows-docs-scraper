# IMFSample::SetSampleDuration

## Description

Sets the duration of the sample.

## Parameters

### `hnsSampleDuration` [in]

Duration of the sample, in 100-nanosecond units.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method succeeds if the duration is negative, although negative durations are probably not valid for most types of data. It is the responsibility of the object that consumes the sample to validate the duration.

The duration can also be zero. This might be valid for some types of data. For example, the sample might contain stream metadata with no buffers.

Until this method is called, the [IMFSample::GetSampleDuration](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-getsampleduration) method returns **MF_E_NO_SAMPLE_DURATION**.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)

[Time Stamps and Durations](https://learn.microsoft.com/windows/desktop/medfound/time-stamps-and-durations)