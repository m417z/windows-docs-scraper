# IDirectMusicSynth::GetAppend

## Description

The `GetAppend` method outputs the number of additional wave samples that the DirectMusic "port" needs to have appended to the end of a download buffer.

## Parameters

### `pdwAppend`

Output pointer for the number of samples to append. This parameter points to a caller-allocated variable into which the method writes a count specifying the number of appended samples for which memory is required. The required memory in bytes can be calculated from the wave format.

## Return value

`GetAppend` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Indicates that the pointer buffer is invalid. |
| **E_NOTIMPL** | Indicates that the method is not implemented. |

## Remarks

This method is called to determine how much extra storage to provide at the end of a download buffer. The method outputs a count indicating the number of additional wave samples by which the buffer should be extended.

When downloading a waveform, the synth might need to attach a little more data at the end of the waveform, depending on how the synth is implemented. The port's synthesis engine can use this extra memory to interpolate across a loop boundary.

For example, if a wave loops for 20 samples at the end, the interpolation math that calculates what to do as it loops back might require some extra data at the end so that it can interpolate properly.

Extending the download buffer by the *pdwAppend* amount allows the synth to simply add the extra samples to the end of the buffer. Otherwise, the synth would have to copy the contents of the download buffer to a larger buffer in order to have room to append the extra data.

Avoid confusing the term DirectMusic "port" with a DMus port driver. A DirectMusic port corresponds to a render or capture pin on a DirectMusic filter. For more information about DirectMusic ports, see the description of the **IDirectMusicPort** interface in the Microsoft Windows SDK documentation.