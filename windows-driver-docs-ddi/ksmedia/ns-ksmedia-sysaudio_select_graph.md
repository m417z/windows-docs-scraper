# SYSAUDIO_SELECT_GRAPH structure

## Description

The SYSAUDIO_SELECT_GRAPH structure is used to specify a graph that includes an optional node such as an AEC control.

## Members

### `Property`

Specifies the property to get or set. This parameter is a structure of type [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `PinId`

Specifies the SysAudio starting pin ID for the graph.

### `NodeId`

Specifies the SysAudio node ID to be included in the graph.

### `Flags`

No flag bits are defined. Set to zero.

### `Reserved`

Reserved. Set to zero.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_SYSAUDIO_SELECT_GRAPH](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-select-graph)