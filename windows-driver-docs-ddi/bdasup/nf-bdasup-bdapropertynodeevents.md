## Description

The **BdaPropertyNodeEvents** function retrieves a list of events that a node supports.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to retrieve the list of events for a node. The BDA minidriver receives this IRP with the [KSPROPERTY_BDA_NODE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-node-events) request.

### `pKSProperty` [in]

Points to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property and request type of the property request.

### `pguidProperty` [out, optional]

Points to an array that receives the list of GUIDs for the events supported by a node.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaPropertyNodeEvents** function to retrieve the list of events for a node after the minidriver receives a [KSPROPERTY_BDA_NODE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-node-events) request of the [KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology) property set from the network provider. Most BDA minidrivers can define dispatch and filter-automation tables so that those minidrivers dispatch the **BdaPropertyNodeEvents** function directly, without intercepting this request using an internal get-handler ([KStrGetPropertyHandler](https://learn.microsoft.com/previous-versions/ff567177(v=vs.85))). See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Determining BDA Device Topology](https://learn.microsoft.com/windows-hardware/drivers/stream/determining-bda-device-topology) for more information.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_BDA_NODE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-node-events)

[KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)