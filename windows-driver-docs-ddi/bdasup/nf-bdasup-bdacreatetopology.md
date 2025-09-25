# BdaCreateTopology function

## Description

The **BdaCreateTopology** function creates the topology between two pins.

## Parameters

### `pKSFilter` [in]

Points to the BDA filter on which to create topology.

### `InputPinId` [in]

Specifies the identifier of the filter's input pin.

### `OutputPinId` [in]

Specifies the identifier of the filter's output pin.

## Return value

Returns STATUS_SUCCESS or an appropriate error code. Returns **NULL** if no valid pin pairing exists with the specified input and output pins.

## Remarks

A BDA minidriver calls the [BdaMethodCreateTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdamethodcreatetopology) function when the network provider dynamically creates a topology between filter pins using the [KSMETHOD_BDA_CREATE_TOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-topology) request of the [KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration) method set. If a BDA minidriver must create a topology between filter pins without relying on the network provider, the BDA minidriver should call the **BdaCreateTopology** function directly.

## See also

[BdaMethodCreateTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdamethodcreatetopology)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)

[KSMETHOD_BDA_CREATE_TOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-create-topology)