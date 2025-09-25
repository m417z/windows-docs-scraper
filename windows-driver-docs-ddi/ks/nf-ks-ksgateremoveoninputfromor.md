# KsGateRemoveOnInputFromOr function

## Description

The **KsGateRemoveOnInputFromOr** function removes an existing input that is in the ON state from an OR gate.

## Parameters

### `OrGate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the OR gate from which to remove an ON input.

## Remarks

Removing the last ON input from a given OR gate results in the gate closing and the transition being propagated to any gates connected to *OrGate*. For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

**KsGateRemoveOnInputFromOr** should only be used on gates that were specifically created as AND gates; AVStream does not verify that the given gate is an AND gate.

This call is an inline function call to [KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff). If conceptually removing an existing input to a gate, a minidriver should call **KsGateRemoveOnInputFromOr** rather than **KsGateTurnInputOff**.

## See also

[KsGateAddOffInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoor)

[KsGateAddOnInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoor)

[KsGateRemoveOffInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromor)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)