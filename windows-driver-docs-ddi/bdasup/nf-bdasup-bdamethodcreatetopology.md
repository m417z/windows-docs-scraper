## Description

The **BdaMethodCreateTopology** function creates a template topology between two pins of a filter.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to create topology. The BDA minidriver receives this IRP with the [KSMETHOD_BDA_CREATE_TOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-topology) request.

### `pKSMethod` [in]

Points to a [KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) structure that describes the method and request type of a method request.

### `pvIgnored` [optional]

Points to a buffer that is ignored.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaMethodCreateTopology** function to create the template topology between two filter pins after the minidriver receives a [KSMETHOD_BDA_CREATE_TOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-topology) request of the [KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration) method set from the network provider. Most BDA minidrivers can define dispatch and filter-automation tables so that those minidrivers dispatch the **BdaMethodCreateTopology** function directly. Some BDA minidrivers must intercept this request, using an internal method ([KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)), rather than dispatch it directly. These minidrivers must obtain a pointer to the BDA filter from the passed IRP before calling **BdaMethodCreateTopology** so that they can use the filter to keep track of associated pins. These minidrivers can then send instructions to the hardware when connecting particular pin types. See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Configuring a BDA Filter](https://learn.microsoft.com/windows-hardware/drivers/stream/configuring-a-bda-filter) for more information.

If a BDA minidriver must create the template topology between two filter pins without relying on the network provider, the BDA minidriver should call the [BdaCreateTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatetopology) function.

## See also

[BdaCreateTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatetopology)

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)

[KSMETHOD_BDA_CREATE_TOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-topology)

[KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)