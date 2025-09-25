## Description

The **BdaPropertyGetControllingPinId** function retrieves the identifier of a pin on which to control the properties, methods, and events of a specific node.

## Parameters

### `Irp` [in]

Points to the IRP for the request to retrieve the controlling pin for a node. The BDA minidriver receives this IRP with the [KSPROPERTY_BDA_CONTROLLING_PIN_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-controlling-pin-id) request.

### `Property` [in]

Points to a [KSP_BDA_NODE_PIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdamedia/ns-bdamedia-_ksp_bda_node_pin) structure that describes the property and request type of the property request to retrieve the controlling pin for a node.

### `pulControllingPinId` [out, optional]

Points to a variable that receives the identifier of the controlling pin for a node.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaPropertyGetControllingPinId** function to retrieve the identifier of the controlling pin for a node after the minidriver receives a [KSPROPERTY_BDA_CONTROLLING_PIN_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-controlling-pin-id) request of the [KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology) property set from the network provider. Most BDA minidrivers can define dispatch and filter-automation tables so that those minidrivers dispatch the **BdaPropertyGetControllingPinId** function directly, without intercepting this request using an internal get-handler ([KStrGetPropertyHandler](https://learn.microsoft.com/previous-versions/ff567177(v=vs.85))). See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Determining BDA Device Topology](https://learn.microsoft.com/windows-hardware/drivers/stream/determining-bda-device-topology) for more information.

## See also

[KSPROPERTY_BDA_CONTROLLING_PIN_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-controlling-pin-id)

[KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)

[KSP_BDA_NODE_PIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdamedia/ns-bdamedia-_ksp_bda_node_pin)