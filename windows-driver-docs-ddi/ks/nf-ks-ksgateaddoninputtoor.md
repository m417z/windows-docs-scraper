# KsGateAddOnInputToOr function

## Description

The **KsGateAddOnInputToOr** function adds a new input in the ON state to a given OR gate.

## Parameters

### `OrGate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the OR gate to which to add a new ON input.

## Remarks

Adding an ON input to an OR gate in the OFF or closed state results in the gate opening and the transition being propagated to any gates attached to *OrGate*. Use this function only with gates that were specifically created as OR gates. AVStream does not verify that the given gate is an OR gate.

This call is an inline function call to [KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon). Minidrivers should call **KsGateAddOnInputToOr** rather than **KsGateTurnInputOn** if conceptually adding a new input to the gate.

## See also

[KsGateAddOffInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoor)

[KsGateRemoveOffInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromor)

[KsGateRemoveOnInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromor)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)