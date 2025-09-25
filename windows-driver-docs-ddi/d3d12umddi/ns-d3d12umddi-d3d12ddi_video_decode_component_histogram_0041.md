# D3D12DDI_VIDEO_DECODE_COMPONENT_HISTOGRAM_0041 structure

## Description

Describes the histogram output buffer for a single component.

## Members

### `Offset`

The offset location in pBuffer to write the component histogram. Set to zero when this component is disabled.

> **Note** This value must be 256-byte aligned.

### `hDrvBuffer`

The target buffer for the hardware to write the components histogram. Set to a nullptr when the component histogram is disabled.