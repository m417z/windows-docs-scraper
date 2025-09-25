# IMiniportAudioSignalProcessing::GetModes

## Description

The GetModes method retrieves the audio signal processing modes supported by an audio pin.

## Parameters

### `Pin` [in]

The index of the audio pin.

### `SignalProcessingModes` [out, optional]

This parameter is optional. It returns an array of GUIDs that identify the signal processing modes supported by the *Pin* parameter.

### `NumSignalProcessingModes` [in, out]

When used as an input, it specifies the number of elements that can be written to the buffer that is specified in *SignalProcessingModes*. When used as an output, it returns the number of elements that were written to the buffer.

## Return value

**GetModes** returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

If *SignalProcessingModes* is NULL, then **GetModes** writes the number of supported modes to *NumSignalProcessingModes* and returns STATUS_SUCCESS. This allows callers to query the number of supported modes in order to allocate buffers.

If *SignalProcessingModes* is not NULL, then **GetModes** verifies that *NumSignalProcessingModes* is greater than or equal to the number of supported modes. If it is, then the method writes the supported modes to the *SignalProcessingModes* buffer, writes the actual number of supported modes to *NumSignalProcessingModes*, and returns STATUS_SUCCESS.

The following table presents and explains the error messages than can be returned by **GetModes**.

| Error code | Description |
| --- | --- |
| STATUS_BUFFER_TOO_SMALL | The buffer that was set aside for *NumSignalProcessingModes* is too small. |
| STATUS_INVALID_PARAMETER | The value of the *Pin* parameter indicates a Pin ID that is >= the number of pin factories on the filter. The pin index is zero-based, so for n pin factories on a filter, the highest index value should be n-1. |
| STATUS_NOT_SUPPORTED | A Pin ID was specified for a pin which does not support signal processing modes. For example, if the Pin ID refers to an audio loopback pin or a bridge pin, then **GetModes** will return this error code. |

## See also

[IMiniportAudioSignalProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudiosignalprocessing)