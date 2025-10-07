# MCI\_WAVE\_SET\_PARMS structure

The **MCI\_WAVE\_SET\_PARMS** structure contains information for the [**MCI\_SET**](https://learn.microsoft.com/windows/win32/multimedia/mci-set) command for waveform-audio devices.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwTimeFormat**

Device's time format.

**dwAudio**

Channel number for audio output. Typically used when turning a channel on or off.

**wInput**

Audio input channel.

**wOutput**

Output device to use. For example, this value could be 2 if a system had two installed sound cards.

**wFormatTag**

Format of the waveform-audio data, such as WAVE\_FORMAT\_PCM. Possible values are defined in Mmreg.h.

**wReserved2**

Reserved.

**nChannels**

Mono (1) or stereo (2).

**wReserved3**

Reserved.

**nSamplesPerSec**

Samples per second.

**nAvgBytesPerSec**

Sample rate in bytes per second.

**nBlockAlign**

Block alignment of the data.

**wReserved4**

Reserved.

**wBitsPerSample**

Bits per sample.

**wReserved5**

Reserved.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the members.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Mciapi.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_SET**](https://learn.microsoft.com/windows/win32/multimedia/mci-set)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

