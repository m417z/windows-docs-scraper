# IMFSample::GetSampleDuration

## Description

Retrieves the duration of the sample.

## Parameters

### `phnsSampleDuration` [out]

Receives the duration, in 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NO_SAMPLE_DURATION** | The sample does not have a specified duration. |

## Remarks

If the sample contains more than one buffer, the duration includes the data from all of the buffers.

If the retrieved duration is zero, or if the method returns **MF_E_NO_SAMPLE_DURATION**, the duration is unknown. In that case, it might be possible to calculate the duration from the media type—for example, by using the video frame rate or the audio sampling rate.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)