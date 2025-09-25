# KSWAVE_OUTPUT_CAPABILITIES structure

## Description

The KSWAVE_OUTPUT_CAPABILITIES structure is used to describe the output capabilities of a device.

## Members

### `MaximumChannelsPerConnection`

Specifies the maximum number of channels per connection.

### `MinimumBitsPerSample`

Specifies the minimum bits per sample.

### `MaximumBitsPerSample`

Specifies the maximum bits per sample.

### `MinimumSampleFrequency`

Specifies the minimum sampling frequency.

### `MaximumSampleFrequency`

Specifies the maximum sampling frequency.

### `TotalConnections`

Indicates the total number of connections.

### `StaticConnections`

Indicates the number of static connections.

### `StreamingConnections`

Indicates the number of streaming connections.

### `ActiveConnections`

Indicates the number of active connections.

### `ActiveStaticConnections`

Indicates the number of active static connections.

### `ActiveStreamingConnections`

Indicates the number of active streaming connections.

### `Total3DConnections`

Indicates the total number of 3D connections.

### `Static3DConnections`

Indicates the number of static 3D connections.

### `Streaming3DConnections`

Indicates the number of streaming 3D connections.

### `Active3DConnections`

Indicates the number of active 3D connections.

### `ActiveStatic3DConnections`

Indicates the number of static 3D connections.

### `ActiveStreaming3DConnections`

Indicates the number of streaming 3D connections.

### `TotalSampleMemory`

Specifies the total amount of sample memory.

### `FreeSampleMemory`

Specifies the available free sample memory.

### `LargestFreeContiguousSampleMemory`

Specifies the largest, free contiguous amount of sample memory.

## Remarks

This structure is used by the [KSPROPERTY_WAVE_OUTPUT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-wave-output-capabilities) property.

## See also

[KSPROPERTY_WAVE_OUTPUT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-wave-output-capabilities)