# KsGateAddOnInputToAnd function

## Description

The **KsGateAddOnInputToAnd** function adds a new input in the ON state to a given AND gate.

## Parameters

### `AndGate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the AND gate to which to add a new ON input.

## Remarks

This function should only be used on gates that were specifically created as AND gates; AVStream does not verify that the given gate is an AND gate.

This call is an empty function. It should be used for code readability and clarity.

## See also

[KsGateAddOffInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoand)

[KsGateRemoveOffInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromand)

[KsGateRemoveOnInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromand)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)