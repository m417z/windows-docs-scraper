# IXAudio2MasteringVoice::GetChannelMask

## Description

Returns the channel mask for this voice.

## Parameters

### `pChannelmask` [out]

Returns the channel mask for this voice. This corresponds to the **dwChannelMask** member of the [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible) structure.

## Return value

This method does not return a value.

## Remarks

The *pChannelMask* argument is a bit-mask of the various channels in the speaker geometry reported by the audio system. This information is needed for the [X3DAudioInitialize](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudioinitialize) *SpeakerChannelMask* parameter.

The X3DAUDIO.H header declares a number of **SPEAKER_** positional defines to decode these channels masks.

Examples include:

```
SPEAKER_STEREO // SPEAKER_FRONT_LEFT (0x1) | SPEAKER_FRONT_RIGHT (0x2)

SPEAKER_5POINT1 // SPEAKER_FRONT_LEFT (0x1) | SPEAKER_FRONT_RIGHT (0x2)
                                    // | SPEAKER_FRONT_CENTER (0x4)
                                    // | SPEAKER_LOW_FREQUENCY (0x8)
                                    // | SPEAKER_BACK_LEFT (0x10) | SPEAKER_BACK_RIGHT (0x20)
```

**Note** For the DirectX SDK versions of XAUDIO, the channel mask for the output device was obtained via the **IXAudio2::GetDeviceDetails** method, which doesn't exist in Windows 8 and later.

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8)

## See also

[IXAudio2MasteringVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2masteringvoice)