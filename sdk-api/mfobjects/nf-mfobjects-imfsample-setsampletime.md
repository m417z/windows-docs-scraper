# IMFSample::SetSampleTime

## Description

Sets the presentation time of the sample.

## Parameters

### `hnsSampleTime` [in]

The presentation time, in 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Some pipeline components require samples that have time stamps. Generally the component that generates the data for the sample also sets the time stamp. The Media Session might modify the time stamps.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)

[Time Stamps and Durations](https://learn.microsoft.com/windows/desktop/medfound/time-stamps-and-durations)