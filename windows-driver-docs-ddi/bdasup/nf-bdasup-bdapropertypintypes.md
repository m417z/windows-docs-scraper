## Description

The **BdaPropertyPinTypes** function retrieves a list of pin types in a template topology.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to retrieve list of pin types. The BDA minidriver receives this IRP with the [KSPROPERTY_BDA_PIN_TYPES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-types) request.

### `pKSProperty` [in]

Points to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property and request type of the property request.

### `pulProperty` [out]

Points to an array that receives the list of pin types.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaPropertyPinTypes** function to retrieve the list of pin types after the minidriver receives a [KSPROPERTY_BDA_PIN_TYPES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-types) request of the [KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology) property set from the network provider. Most BDA minidrivers can define dispatch and filter-automation tables so that those minidrivers dispatch the **BdaPropertyPinTypes** function directly, without intercepting this request using an internal get-handler ([KStrGetPropertyHandler](https://learn.microsoft.com/previous-versions/ff567177(v=vs.85))). See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Determining BDA Device Topology](https://learn.microsoft.com/windows-hardware/drivers/stream/determining-bda-device-topology) for more information.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_BDA_PIN_TYPES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-types)

[KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)