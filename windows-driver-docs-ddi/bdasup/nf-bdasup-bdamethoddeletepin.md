## Description

The **BdaMethodDeletePin** function deletes a pin factory.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to delete a pin factory. The BDA minidriver receives this IRP with the [KSMETHOD_BDA_DELETE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-delete-pin-factory) request.

### `pKSMethod` [in]

Points to a [KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) structure that describes the method and request type of a method request.

### `pvIgnored`

Points to a buffer that is ignored.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaMethodDeletePin** function to delete a pin factory after the minidriver receives a [KSMETHOD_BDA_DELETE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-delete-pin-factory) request of the [KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration) method set from the network provider. Most BDA minidrivers can define dispatch and filter-automation tables so that those minidrivers dispatch the **BdaMethodDeletePin** function directly, without intercepting this request using an internal method ([KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)). See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Configuring a BDA Filter](https://learn.microsoft.com/windows-hardware/drivers/stream/configuring-a-bda-filter) for more information.

If a BDA minidriver must delete a pin without relying on the network provider, the BDA minidriver should call the [BdaDeletePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdadeletepin) function.

## See also

[BdaDeletePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdadeletepin)

[BdaMethodCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdamethodcreatepin)

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)

[KSMETHOD_BDA_DELETE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-delete-pin-factory)

[KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)