# XAUDIO2FX_VOLUMEMETER_LEVELS structure

## Description

Describes parameters for use with the volume meter APO.

## Members

### `pPeakLevels`

Array that will be filled with the maximum absolute level for each channel during a processing pass. The array must be at least *ChannelCount* × sizeof(float) bytes. *pPeakLevels* may be NULL if *pRMSLevels* is not NULL.

### `pRMSLevels`

Array that will be filled with root mean square level for each channel during a processing pass. The array must be at least *ChannelCount* × sizeof(float) bytes. *pRMSLevels* may be NULL if *pPeakLevels* is not NULL.

### `ChannelCount`

Number of channels being processed.

## Remarks

This structure is used with the [XAudio2 IXAudio2Voice::GetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-geteffectparameters) method.

*pPeakLevels* and *pRMSLevels* are not returned by [IXAudio2Voice::GetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-geteffectparameters), the arrays are only filled out if they are present. If *pPeakLevels* and *pRMSLevels* are used they must be allocated by the application. The application is responsible for freeing the arrays when they are no longer needed.

*ChannelCount* must be set by the application to match the number of channels in the voice the effect is applied to.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Create an Effect Chain](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--create-an-effect-chain)

[IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)

[XAudio Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)

[XAudio2CreateVolumeMeter](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/nf-xaudio2fx-xaudio2createvolumemeter)