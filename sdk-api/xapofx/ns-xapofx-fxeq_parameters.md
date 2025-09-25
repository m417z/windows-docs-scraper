# FXEQ_PARAMETERS structure

## Description

Parameters for use with the FXEQ XAPO.

## Members

### `FrequencyCenter0`

Center frequency in Hz for band 0. Must be between FXEQ_MIN_FREQUENCY_CENTER and FXEQ_MAX_FREQUENCY_CENTER.

### `Gain0`

The boost or decrease to frequencies in band 0. Must be between FXEQ_MIN_GAIN and FXEQ_MAX_GAIN

### `Bandwidth0`

Width of band 0. Must be between FXEQ_MIN_BANDWIDTH and FXEQ_MAX_BANDWIDTH.

### `FrequencyCenter1`

Center frequency in Hz for band 1. Must be between FXEQ_MIN_FREQUENCY_CENTER and FXEQ_MAX_FREQUENCY_CENTER.

### `Gain1`

The boost or decrease to frequencies in band 1. Must be between FXEQ_MIN_GAIN and FXEQ_MAX_GAIN

### `Bandwidth1`

Width of band 1. Must be between FXEQ_MIN_BANDWIDTH and FXEQ_MAX_BANDWIDTH.

### `FrequencyCenter2`

Center frequency in Hz for band 2. Must be between FXEQ_MIN_FREQUENCY_CENTER and FXEQ_MAX_FREQUENCY_CENTER.

### `Gain2`

The boost or decrease to frequencies in band 2. Must be between FXEQ_MIN_GAIN and FXEQ_MAX_GAIN

### `Bandwidth2`

Width of band 2. Must be between FXEQ_MIN_BANDWIDTH and FXEQ_MAX_BANDWIDTH.

### `FrequencyCenter3`

Center frequency in Hz for band 3. Must be between FXEQ_MIN_FREQUENCY_CENTER and FXEQ_MAX_FREQUENCY_CENTER.

### `Gain3`

The boost or decrease to frequencies in band 3. Must be between FXEQ_MIN_GAIN and FXEQ_MAX_GAIN

### `Bandwidth3`

Width of band 3. Must be between FXEQ_MIN_BANDWIDTH and FXEQ_MAX_BANDWIDTH.

## Remarks

Each band ranges from **FrequencyCenterN** - (**BandwidthN** / 2) to **FrequencyCenterN** + (**BandwidthN** / 2).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)