# KsGateRemoveOffInputFromOr function

## Description

The **KsGateRemoveOffInputFromOr** function removes an existing input that is in the OFF state from an OR gate.

## Parameters

### `OrGate` [in]

A pointer to the [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the OR gate from which to remove an OFF input.

## Remarks

**KsGateRemoveOffInputFromOr** should only be used on gates that were specifically created as AND gates; AVStream does not verify that the given gate is truly an AND gate.

For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

This call is an empty function. It should be used for code readability and clarity.

## See also

[KsGateAddOffInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoor)

[KsGateAddOnInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoor)

[KsGateRemoveOnInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromor)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)