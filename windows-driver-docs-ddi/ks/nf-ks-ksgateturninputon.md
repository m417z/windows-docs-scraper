# KsGateTurnInputOn function

## Description

The **KsGateTurnInputOn** function turns on an existing input to *Gate*.

## Parameters

### `Gate` [in, optional]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the gate that currently has an input in the OFF state to transition to the ON state. May be an AND gate or an OR gate.

## Remarks

It is the minidriver's responsibility to verify that the gate that the minidriver passes to **KsGateTurnInputOn** has at least one OFF input. If you call this function with an AND gate that has no inputs currently in the OFF state, the call sets the AND gate into an invalid state. If you call this function with an OR gate that has no inputs currently in the OFF state, the result is equivalent to adding another input in the ON state to *Gate*.

Furthermore, if turning an input on would cause *Gate* to transition from the closed state to the open state, this call instead turns on an input to whatever gate is attached to *Gate*. For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateAddOffInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoand)

[KsGateAddOffInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoor)

[KsGateAddOnInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoand)

[KsGateAddOnInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoor)

[KsGateRemoveOffInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromand)

[KsGateRemoveOffInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromor)

[KsGateRemoveOnInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromand)

[KsGateRemoveOnInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromor)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)