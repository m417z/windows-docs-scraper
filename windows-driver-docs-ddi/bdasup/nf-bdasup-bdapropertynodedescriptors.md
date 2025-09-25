## Description

The **BdaPropertyNodeDescriptors** function retrieves a list of nodes in a template topology.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to retrieve the list of nodes. The BDA minidriver receives this IRP with the [KSPROPERTY_BDA_NODE_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-node-descriptors) request.

### `pKSProperty` [in]

Points to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property and request type of the property request.

### `pNodeDescriptorProperty` [out, optional]

Points to an array that receives the list of GUIDs for the nodes in a template topology.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaPropertyNodeDescriptors** function to retrieve the list of nodes after the minidriver receives a [KSPROPERTY_BDA_NODE_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-node-descriptors) request of the [KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology) property set from the network provider. Most BDA minidrivers can define dispatch and filter-automation tables so that those minidrivers dispatch the **BdaPropertyNodeDescriptors** function directly, without intercepting this request using an internal get-handler ([KStrGetPropertyHandler](https://learn.microsoft.com/previous-versions/ff567177(v=vs.85))). See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Determining BDA Device Topology](https://learn.microsoft.com/windows-hardware/drivers/stream/determining-bda-device-topology) for more information.

For a list of BDA nodes that are available to create in a template topology, see [BDA Node Category GUIDs](https://learn.microsoft.com/windows-hardware/drivers/stream/bda-node-category-guids).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_BDA_NODE_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-node-descriptors)

[KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)