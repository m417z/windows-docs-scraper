# XAUDIO2_EFFECT_CHAIN structure

## Description

Defines an effect chain.

## Members

### `EffectCount`

Number of effects in the effect chain for the voice.

### `pEffectDescriptors`

Array of [XAUDIO2_EFFECT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_descriptor) structures containing pointers to XAPO instances.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Create an Effect Chain](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--create-an-effect-chain)

[IXAudio2::CreateMasteringVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createmasteringvoice)

[IXAudio2::CreateSourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createsourcevoice)

[IXAudio2::CreateSubmixVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createsubmixvoice)

[IXAudio2Voice::SetEffectChain](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectchain)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)

[XAudio2 Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)