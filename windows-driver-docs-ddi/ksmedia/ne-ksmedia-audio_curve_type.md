# AUDIO_CURVE_TYPE enumeration

## Description

The **AUDIO_CURVE_TYPE** enumeration defines constants that specify a curve algorithm to be applied to set a volume level.

## Constants

### `AUDIO_CURVE_TYPE_NONE`

Specifies that no curve algorithm will be applied. When this curve is specified, the duration of the curve specified must be equal to 0.

### `AUDIO_CURVE_TYPE_WINDOWS_FADE`

Specifies that the algorithm that is applied to the volume setting must follow the curve shown in the diagram in the [Remarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audio_curve_type#remarks) section.

## Remarks

The following snippet of pseudocode shows the logic for the algorithm that is applied to the volume setting to reach the target volume level.

```cpp
// POWER IN AMPLITUDE: 1.75

// Fade In:
// Curve begins at 0 when nFrame = 0
// When nFrame gets to (nFrames - 1), curve = 1
//
// curve = pow(nFrame / (nFrames - 1), exponent)

float fFrameCount = nFrames - 1.0f;
for (UINT32 nFrame = 0; nFrame < nFrames; nFrame++) {
    float curve = powf(nFrame / fFrameCount, 1.75f);
    for (UINT32 nChannel = 0; nChannel < pWfx->nChannels; nChannel++) {
            pFloat[nFrame * pWfx->nChannels + nChannel] *= curve;
    }
}

// Fade Out:
// curve begins at 1 when nFrame = 0
// When nFrame gets to (nFrames - 1), curve = 0
//
// curve = pow(1 - (nFrame / (nFrames - 1)), exponent)

float fFrameCount = nFrames - 1.0f;
for (UINT32 nFrame = 0; nFrame < nFrames; nFrame++) {
    float curve = powf(1.0f - (nFrame / fFrameCount), 1.75f);
    for (UINT32 nChannel = 0; nChannel < pWfx->nChannels; nChannel++) {
            pFloat[nFrame * pWfx->nChannels + nChannel] *= curve;
    }
}
```

And the following diagram shows a graphical representation of the preceding pseudocode for setting the volume level.

![Graphical representation of volume level curve.](https://learn.microsoft.com/windows-hardware/drivers/ddi/images/audio-curve-type.png)

## See also

[KSAUDIOENGINE_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_tagksaudioengine_volumelevel)

[KSPROPERTY_AUDIOENGINE_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-volumelevel)