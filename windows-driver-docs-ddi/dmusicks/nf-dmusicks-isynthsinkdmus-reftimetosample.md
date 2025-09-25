# ISynthSinkDMus::RefTimeToSample

## Description

The `RefTimeToSample` method converts a reference time into a sample time.

## Parameters

### `rfTime` [in]

Pointer to the reference time being passed in. The reference time is measured in 100-nanosecond units.

### `pllSampleTime` [out]

Output pointer for the sample time. This parameter points to a caller-allocated variable into which the method writes the calculated sample time.

## Return value

`RefTimeToSample` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `RefTimeToSample` method converts reference time to sample time. The method takes a reference time as an input parameter, and it outputs the corresponding sample time.

The calculation of the reference time from the sample time depends on the sampling frequency. For example, if the output buffer is in a 44.1 kHz format, a sample time of 44,100 is equivalent to a reference time of one second.

## See also

[IDirectMusicSynthSink::RefTimeToSample](https://learn.microsoft.com/windows/win32/api/dmusics/nf-dmusics-idirectmusicsynthsink-reftimetosample)

[ISynthSinkDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-isynthsinkdmus)