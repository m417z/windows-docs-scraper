# ISynthSinkDMus::SampleToRefTime

## Description

The `SampleToRefTime` method converts a sample time to a reference time.

## Parameters

### `llSampleTime` [in]

Specifies the sample time being passed in.

### `prfTime` [out]

Output pointer for the reference time. This parameter is a pointer to a caller-allocated variable into which the method writes the calculated reference time. Reference time is measured in 100-nanosecond units.

## Return value

`SampleToRefTime` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `SampleToRefTime` method accepts a sample time as an input parameter, converts the sample time to a reference time, and outputs the reference time to a location specified by the caller.

The calculation of reference time from sample time to reference time depends on the sampling frequency. For example, if the output buffer is in a 44.2 kHz format, a sample time of 44,200 is equivalent to a reference time of one second.

## See also

[IDirectMusicSynthSink::SampleToRefTime](https://learn.microsoft.com/windows/win32/api/dmusics/nf-dmusics-idirectmusicsynthsink-sampletoreftime)

[ISynthSinkDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-isynthsinkdmus)