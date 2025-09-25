## Description

The **BdaMethodCreatePin** function creates a pin factory.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to create a pin factory. The BDA minidriver receives this IRP with the [KSMETHOD_BDA_CREATE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-pin-factory) request.

### `pKSMethod` [in]

Points to a [KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) structure that describes the method and request type of a method request.

### `pulPinFactoryID` [out, optional]

Points to a variable that receives the identifier of the pin factory.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaMethodCreatePin** function to create a pin factory after the minidriver receives a [KSMETHOD_BDA_CREATE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-pin-factory) request of the [KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration) method set from the network provider. Most BDA minidrivers can define dispatch and filter-automation tables so that those minidrivers dispatch the **BdaMethodCreatePin** function directly, without intercepting this request using an internal method ([KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)). See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Configuring a BDA Filter](https://learn.microsoft.com/windows-hardware/drivers/stream/configuring-a-bda-filter) for more information.

If a BDA minidriver must create a pin without relying on the network provider, the BDA minidriver should call the **BdaCreatePin** function.

## See also

[BdaCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatepin)

[BdaMethodDeletePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdamethoddeletepin)

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)

[KSMETHOD_BDA_CREATE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-pin-factory)

[KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)