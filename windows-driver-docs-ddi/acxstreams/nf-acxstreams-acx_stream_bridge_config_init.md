## Description

The **ACX_STREAM_BRIDGE_CONFIG_INIT** function initializes an [ACX_STREAM_BRIDGE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_stream_bridge_config) structure.

## Parameters

### `Config`

A pointer to the [ACX_STREAM_BRIDGE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_stream_bridge_config) structure.

## Remarks

Drivers should call ACX_STREAM_BRIDGE_CONFIG_INIT when creating an ACXSTREAMBRIDGE.
This function resets the [ACX_STREAM_BRIDGE_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_stream_bridge_config) and initializes the Type field to AcxStreamBridgeDefaultType.

### Example

```cpp
    ACX_STREAM_BRIDGE_CONFIG bridgeCfg;

    ACX_STREAM_BRIDGE_CONFIG_INIT(&bridgeCfg);
    streamCfg.InModesCount = 1;
    streamCfg.InModes      = inModes;
    streamCfg.OutMode      = &AUDIO_SIGNALPROCESSINGMODE_DEFAULT;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)