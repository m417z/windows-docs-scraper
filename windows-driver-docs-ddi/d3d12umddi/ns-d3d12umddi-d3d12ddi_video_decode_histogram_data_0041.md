# D3D12DDI_VIDEO_DECODE_HISTOGRAM_DATA_0041 structure

## Description

Describes data for the video decode histogram.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `DecodeProfile`

The decode profile GUID to retrieve the count of supported encryption GUIDs.

### `Width`

The width of the decoded frame.

### `Height`

The height of the decoded frame.

### `DecodeFormat`

The format of the decoded frame.

### `Components`

The components that the hardware supports.

### `BinCount`

The number of per component bins that are supported. BinCount must be >= 64, and must be a power of 2 (64, 128, 256, 512, etc.).

### `CounterBitDepth`

The bit depth of the bin counter. The counter is always stored in a 32 bit value and is therefore 32 bits or less. The counter is stored in the lower bits of the 32 bit storage. The upper bits are set to zero. If the in count exceeds this bit depth, the value is set to the maximum counter value. Valid values for CounterBitDepth are 16, 24, and 32.