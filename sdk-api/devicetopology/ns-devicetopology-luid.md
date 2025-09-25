# LUID structure

## Description

The **LUID** structure stores the video port identifier. This structure is stored in the **PortId** member of the [KSJACK_SINK_INFORMATION](https://learn.microsoft.com/windows/win32/api/devicetopology/ns-devicetopology-ksjack_sink_information) structure.

## Members

### `LowPart`

LowPart of the video port identifier.

### `HighPart`

HighPart of the video port identifier.

## See also

[Core Audio Structures](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-structures)

[IKsJackSinkInformation::GetJackSinkInformation](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjacksinkinformation-getjacksinkinformation)