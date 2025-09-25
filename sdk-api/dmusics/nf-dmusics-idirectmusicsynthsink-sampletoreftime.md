# IDirectMusicSynthSink::SampleToRefTime

## Description

The `SampleToRefTime` method converts a sample time to a reference time.

## Parameters

### `llSampleTime`

Specifies the sample time. For more information, see the following Remarks section.

### `prfTime`

Output pointer for the reference time. This parameter points to a caller-allocated REFERENCE_TIME variable into which the method writes the reference time.

## Return value

`SampleToRefTime` returns S_OK if the call is successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `SampleToRefTime` method converts sample time to reference time. Sample time is expressed as the number of samples rendered, and reference time is measured in 100-nanosecond units.

The synth sink manages the timing relationship between the master clock (set with a call to [IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock)) and the audio stream.

For more information, see the description of reference time and sample time in [Synthesizer Timing](https://learn.microsoft.com/windows-hardware/drivers/audio/synthesizer-timing).

## See also

[IDirectMusicSynthSink::RefTimeToSample](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-reftimetosample)

[IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock)

[ISynthSinkDMus::SampleToRefTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/dmusicks/nf-dmusicks-isynthsinkdmus-sampletoreftime)