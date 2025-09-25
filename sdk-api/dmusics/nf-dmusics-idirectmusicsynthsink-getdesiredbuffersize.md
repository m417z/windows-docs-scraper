# IDirectMusicSynthSink::GetDesiredBufferSize

## Description

The `GetDesiredBufferSize` method retrieves the synthesizer's preferred buffer size, expressed in samples.

## Parameters

### `pdwBufferSizeInSamples`

Output pointer for the buffer size. This parameter points to a caller-allocated variable into which the method writes the desired buffer length, expressed in samples.

## Return value

`GetDesiredBufferSize` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not set. |

## Remarks

The `GetDesiredBufferSize` method returns the desired buffer size based on the current format of the synth. DirectSound buffers passed to [IDirectMusicSynthSink::SetDirectSound](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setdirectsound) might be invalid unless they are at least this size.

For more information, see the description of the **IDirectMusicPort** interface in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynthSink::SetDirectSound](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setdirectsound)