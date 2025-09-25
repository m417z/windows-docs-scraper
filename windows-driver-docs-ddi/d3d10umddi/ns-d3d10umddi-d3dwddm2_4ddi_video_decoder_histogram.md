# D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM structure

## Description

Contains decode histogram output buffer information such as decode profile, resolution, and format.

## Members

### `Offset`

The offset location in hBuffer to write the component histogram.

### `hBuffer`

The target buffer for hardware to write the components histogram. Set to a nullptr when the component histogram is disabled.

## Remarks

## See also