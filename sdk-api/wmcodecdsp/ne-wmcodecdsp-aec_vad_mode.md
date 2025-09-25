# AEC_VAD_MODE enumeration

## Description

Specifies the type of voice activity detection (VAD) for the voice capture DSP. This enumeration is used with the [MFPKEY_WMAAECMA_FEATR_VAD](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmaaecma-featr-vadproperty) property.

## Constants

### `AEC_VAD_DISABLED:0`

Voice activity detection is disabled.

### `AEC_VAD_NORMAL`

General purpose VAD. This setting attempts to balance the false detection rate and the missed detection rate. The output can have the following values.

| Value | Description |
| --- | --- |
| 0 | Non-speech. |
| 1 | Voiced speech. |
| 2 | Unvoiced speech. |
| 3 | Mixture of voiced and unvoiced speech. |

### `AEC_VAD_FOR_AGC`

Voice activity detection for automatic gain control and noise suppression. In this mode, the VAD threshold is higher than the normal mode, to reduce the false detection rate. The output distinguishes voiced speech from other sounds (non-speech or unvoiced speech). The output can have the following values.

| Value | Description |
| --- | --- |
| 0 | Non-speech or unvoiced speech. |
| 1 | Voiced speech. |

### `AEC_VAD_FOR_SILENCE_SUPPRESSION`

Voice activity detection for silence suppression. In this mode, the output distinguishes speech (voiced or unvoiced) from non-speech. The output can have the following values.

| Value | Description |
| --- | --- |
| 0 | Non-speech. |
| 1 | Voiced or unvoiced speech. |

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Voice Capture](https://learn.microsoft.com/windows/desktop/medfound/voicecapturedmo)