# BdaCreatePin function

## Description

The **BdaCreatePin** function creates a new pin in the specified filter.

## Parameters

### `pKSFilter` [in]

Points to the filter in which to create a pin.

### `ulPinType` [in]

Specifies the type of pin to create. The BDA minidriver must define a list of pin types for each filter that it supports.

### `pulPinId` [out, optional]

Points to a variable that receives the identifier for the created pin.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the [BdaMethodCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdamethodcreatepin) function when the network provider dynamically creates a pin using the [KSMETHOD_BDA_CREATE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-pin-factory) request of the [KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration) method set. If a BDA minidriver must create a pin without relying on the network provider, the BDA minidriver should call the **BdaCreatePin** function directly.

.

## See also

[BdaDeletePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdadeletepin)

[BdaMethodCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdamethodcreatepin)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)

[KSMETHOD_BDA_CREATE_PIN_FACTORY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-pin-factory)