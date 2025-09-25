## Description

The **BdaPropertyTemplateConnections** function retrieves a list of connections that describe how pin types and node types are connected in a template topology.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to retrieve the list of connections. The BDA minidriver receives this IRP with the [KSPROPERTY_BDA_TEMPLATE_CONNECTIONS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-template-connections) request.

### `pKSProperty` [in]

Points to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property and request type of the property request.

### `pConnectionProperty` [out, optional]

Points to an array that receives the list of [KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection) structures that describe the connections in a template topology.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaPropertyTemplateConnections** function to retrieve the list of template connections after the minidriver receives a [KSPROPERTY_BDA_TEMPLATE_CONNECTIONS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-template-connections) request of the [KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology) property set from the network provider. Most BDA minidrivers can define dispatch and filter-automation tables so that those minidrivers dispatch the **BdaPropertyTemplateConnections** function directly, without intercepting this request using an internal get-handler ([KStrGetPropertyHandler](https://learn.microsoft.com/previous-versions/ff567177(v=vs.85))). See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Determining BDA Device Topology](https://learn.microsoft.com/windows-hardware/drivers/stream/determining-bda-device-topology) for more information.

The BDA minidriver provided a list of connections to the BDA support library in an array of [KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection) structures when the BDA minidriver passed the BDA filter template ([BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template)) in [BdaCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatefilterfactory) and [BdaInitFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdainitfilter) function calls. This array is a representation of all the possible connections between node and pin types that can be made within the filter or between the filter and adjoining filters. The **BdaPropertyTemplateConnections** function returns this array.

## See also

[BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template)

[BdaCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatefilterfactory)

[BdaInitFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdainitfilter)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_BDA_TEMPLATE_CONNECTIONS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-template-connections)

[KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)

[KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection)