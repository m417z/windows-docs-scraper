# IMFMediaEngineEx::InsertAudioEffect

## Description

Inserts an audio effect.

## Parameters

### `pEffect` [in]

One of the following:

* A pointer to the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface of a Media Foundation transform (MFT) that implements the audio effect.
* A pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface of an activation object. The activation object must create an MFT for the audio effect.

### `fOptional` [in]

Specifies whether the effect is optional.

| Value | Meaning |
| --- | --- |
| **TRUE** | The effect is optional. If the Media Engine cannot add the effect, it ignores the effect and continues playback. |
| **FALSE** | The effect is required. If the Media Engine object cannot add the effect, a playback error occurs. |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | The maximum number of audio effects was reached. |

## Remarks

The effect is applied when the next media resource is loaded.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)