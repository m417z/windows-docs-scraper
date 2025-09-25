# MIC_ARRAY_MODE enumeration

## Description

Specifies how the voice capture DSP performs microphone array processing. This enumeration is used with the [MFPKEY_WMAAECMA_FEATR_MICARR_MODE](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmaaecma-featr-micarr-modeproperty) property.

## Constants

### `MICARRAY_SINGLE_CHAN:0`

Use a single channel. Specify the channel number in the last 8 bits of the value.

### `MICARRAY_SIMPLE_SUM:0x100`

Sum all of the channels.

### `MICARRAY_SINGLE_BEAM:0x200`

Use beam forming with a beam selected by the DSP. After processing starts, you can query which beam was selected by reading the [MFPKEY_WMAAECMA_FEATR_MICARR_BEAM](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmaaecma-featr-micarr-beamproperty) property.

### `MICARRAY_FIXED_BEAM:0x400`

Use beam forming with the center beam.

### `MICARRAY_EXTERN_BEAM:0x800`

Use beam forming with a beam selected by the application. If you set this value, set the MFPKEY_WMAAECMA_FEATR_MICARR_BEAM property to specify the beam.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Voice Capture](https://learn.microsoft.com/windows/desktop/medfound/voicecapturedmo)