# AEC_SYSTEM_MODE enumeration

## Description

Specifies the processing mode for the voice capture DSP. This enumeration is used with the [MFPKEY_WMAAECMA_SYSTEM_MODE](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmaaecma-system-modeproperty)  property.

## Constants

### `SINGLE_CHANNEL_AEC:0`

AEC processing only.

### `ADAPTIVE_ARRAY_ONLY`

Reserved.

### `OPTIBEAM_ARRAY_ONLY`

Microphone array processing only.

### `ADAPTIVE_ARRAY_AND_AEC`

Reserved.

### `OPTIBEAM_ARRAY_AND_AEC`

Microphone array processing and AEC processing.

### `SINGLE_CHANNEL_NSAGC`

No microphone array processing and no AEC processing.

### `MODE_NOT_SET`

Uninitialized. This value is the initial value of the MFPKEY_WMAAECMA_SYSTEM_MODE property. Do not set this value.

## Remarks

In all modes, the DSP applies noise suppression and automatic gain control by default. To disable noise suppression, set the [MFPKEY_WMAAECMA_FEATR_NS](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmaaecma-featr-nsproperty) property. To disable automatic gain control, set the [MFPKEY_WMAAECMA_FEATR_AGC](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmaaecma-featr-agcproperty) property.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Voice Capture](https://learn.microsoft.com/windows/desktop/medfound/voicecapturedmo)