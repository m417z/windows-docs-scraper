# KsGateAddOffInputToAnd function

## Description

The **KsGateAddOffInputToAnd** function adds a new input in the OFF state to a given AND gate.

## Parameters

### `AndGate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the AND gate to which to add a new OFF input.

## Remarks

Adding an OFF input to an open AND gate closes the gate and propagates the close down to any attached gates.

This function should only be used on gates that were specifically created as AND gates; AVStream does not verify that the given gate is an AND gate.

**KsGateAddOffInputToAnd** is an inline function call to [KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff). If conceptually adding a new input to a gate, the minidriver should call **KsGateAddOffInputToAnd** rather than **KsGateTurnInputOff**.

## See also

[KsGateAddOnInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoand)

[KsGateRemoveOffInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromand)

[KsGateRemoveOnInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromand)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)