# BdaDeletePin function

## Description

The **BdaDeletePin** function deletes a pin from the specified filter.

## Parameters

### `pKSFilter` [in]

Points to the filter in which to delete a pin.

### `pulPinId` [out, optional]

Points to a variable that contains the identifier for the pin to delete.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the [BdaMethodDeletePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdamethoddeletepin) function when the network provider dynamically deletes a pin using the [KSMETHOD_BDA_DELETE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-delete-pin-factory) request of the [KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration) method set. If a BDA minidriver must delete a pin without relying on the network provider, the BDA minidriver should call the **BdaDeletePin** function directly.

## See also

[BdaCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatepin)

[BdaMethodDeletePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdamethoddeletepin)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)

[KSMETHOD_BDA_DELETE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-delete-pin-factory)