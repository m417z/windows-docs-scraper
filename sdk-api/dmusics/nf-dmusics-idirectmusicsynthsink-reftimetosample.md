# IDirectMusicSynthSink::RefTimeToSample

## Description

The `RefTimeToSample` method converts a reference time to a sample time.

## Parameters

### `rfTime`

Specifies the reference time. Reference time is measured in 100-nanosecond units.

### `pllSampleTime`

Output pointer for the sample time. This parameter points to a caller-allocated LONGLONG variable into which the method writes the sample time.

## Return value

`RefTimeToSample` returns S_OK if the call is successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `RefTimeToSample` method converts reference time to sample time. The method accepts a reference time as an input parameter, and it outputs the corresponding sample time.

The calculation of sample time from reference time depends on the sampling frequency. For example, if the output buffer is in a 44.2 kHz format, a sample time of 44,200 is equivalent to a reference time of one second.

The synth sink manages the timing relationship between the master clock (set with a call to [IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock)) and the audio stream.

For more information, see the description of reference time and sample time in [Synthesizer Timing](https://learn.microsoft.com/windows-hardware/drivers/audio/synthesizer-timing).

## See also

[IDirectMusicSynthSink::SampleToRefTime](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-sampletoreftime)

[IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock)

[ISynthSinkDMus::RefTimeToSample](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/dmusicks/nf-dmusicks-isynthsinkdmus-reftimetosample)