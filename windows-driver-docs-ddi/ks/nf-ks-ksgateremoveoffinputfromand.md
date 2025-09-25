# KsGateRemoveOffInputFromAnd function

## Description

The **KsGateRemoveOffInputFromAnd** function removes an existing input that is in the OFF state from an AND gate.

## Parameters

### `AndGate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the AND gate from which to remove an OFF input.

## Remarks

Removing the last OFF input from the gate results in the gate opening and the transition being propagated to any gates connected to *AndGate*. For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

**KsGateRemoveOffInputFromAnd** should only be used on gates that were specifically created as AND gates; AVStream does not verify that the given gate is an AND gate.

**KsGateRemoveOffInputFromAnd** is an inline function call to [KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon). If conceptually removing an existing input to the gate rather than turning it off, a minidriver should call **KsGateRemoveOffInputFromAnd** instead of **KsGateTurnInputOn**.

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateAddOffInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoand)

[KsGateAddOnInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoand)

[KsGateRemoveOnInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromand)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)