# KSTOPOLOGY structure

## Description

The KSTOPOLOGY structure describes the topology of pins and nodes.

## Members

### `CategoriesCount`

Specifies the number of functional categories that the driver supports.

### `Categories`

Points to the beginning of the array of functional categories that the driver supports.

### `TopologyNodesCount`

Specifies the number of nodes that the driver supports.

### `TopologyNodes`

Points to the beginning of the array of GUIDs that describe the type of each node. For a list of video kernel streaming related nodes, see [Kernel Streaming Topology Nodes](https://learn.microsoft.com/windows-hardware/drivers/stream/kernel-streaming-topology-nodes). For a list of audio kernel streaming related nodes, see [Audio Topology Nodes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-topology-nodes).

### `TopologyConnectionsCount`

Specifies the number of entries in the array pointed to by **TopologyConnections**. The node numbers of each entry must correspond to the array offset of the node within **TopologyNodes**. When this structure is a part of a streaming minidriver's [HW_STREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header), the pin numbers must correspond to the offsets within the array of [HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information) structures in the minidriver's [HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor) structure.

### `TopologyConnections`

Points to the beginning of the array of topology connections for this structure.

### `TopologyNodesNames`

Specifies the GUID of the localized Unicode string name for the node, stored in the registry.

### `Reserved`

Reserved for system use. Drivers should set this to zero.

## Remarks

A stream class minidriver creates and passes this structure as part of its [HW_STREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header) structure. The class driver uses this structure to process topology property requests. The property data that the class driver returns is determined from the KSTOPOLOGY structure as follows:

## See also

[HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor)

[HW_STREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header)

[HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information)

[KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection)