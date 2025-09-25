# MF_TOPOSTATUS enumeration

## Description

Specifies the status of a topology during playback.

## Constants

### `MF_TOPOSTATUS_INVALID:0`

This value is not used.

### `MF_TOPOSTATUS_READY:100`

The topology is ready to start. After this status flag is received, you can use the Media Session's [IMFGetService::GetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfgetservice-getservice) method to query the topology for services, such as rate control.

### `MF_TOPOSTATUS_STARTED_SOURCE:200`

The Media Session has started to read data from the media sources in the topology.

### `MF_TOPOSTATUS_DYNAMIC_CHANGED:210`

The Media Session modified the topology, because the format of a stream changed.

### `MF_TOPOSTATUS_SINK_SWITCHED:300`

The media sinks have switched from the previous topology to this topology. This status value is not sent for the first topology that is played. For the first topology, the [MESessionStarted](https://learn.microsoft.com/windows/desktop/medfound/mesessionstarted) event indicates that the media sinks have started receiving data.

### `MF_TOPOSTATUS_ENDED:400`

Playback of this topology is complete. The Media Session might still use the topology internally. The Media Session does not completely release the topology until it sends the next **MF_TOPOSTATUS_STARTED_SOURCE** status event or the [MESessionEnded](https://learn.microsoft.com/windows/desktop/medfound/mesessionended) event.

## Remarks

This enumeration is used with the [MESessionTopologyStatus](https://learn.microsoft.com/windows/desktop/medfound/mesessiontopologystatus) event. The MESessionTopologyStatus event always has an [MF_EVENT_TOPOLOGY_STATUS](https://learn.microsoft.com/windows/desktop/medfound/mf-event-topology-status-attribute) attribute whose value is a member of this enumeration.

For a single topology, the Media Session sends these status flags in numerical order, starting with **MF_TOPOSTATUS_READY**. However, there is no guarantee about the ordering of the events across two different topologies. For example, you might get **MF_TOPOSTATUS_READY** for a topology before you get **MF_TOPOSTATUS_ENDED** for the previous topology.

## See also

[MESessionTopologyStatus](https://learn.microsoft.com/windows/desktop/medfound/mesessiontopologystatus)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)