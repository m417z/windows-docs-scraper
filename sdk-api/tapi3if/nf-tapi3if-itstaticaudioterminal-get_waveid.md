# ITStaticAudioTerminal::get_WaveId

## Description

The
**get_WaveId** method returns the wave ID for the audio device used to implement this terminal.

## Parameters

### `plWaveId` [out]

Pointer to a variable where, on success, the method will store the wave ID for this terminal.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

All MSPs must implement the
**get_WaveId** method on their audio terminals for TAPI's association of phone devices and audio terminals to work for calls on that MSP's addresses. See
[ITStaticAudioTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstaticaudioterminal) for what to do for audio terminals that are not accessible via standard Windows audio APIs.

All other terminals must return the correct wave ID, even if the internal implementation of the terminal does not use wave. In such cases, a mapping should be possible between the identifier used in the nonwave APIs and the wave ID. The MSP must perform this mapping.

## See also

[ITStaticAudioTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstaticaudioterminal)