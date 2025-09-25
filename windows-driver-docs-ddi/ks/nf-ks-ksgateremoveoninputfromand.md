# KsGateRemoveOnInputFromAnd function

## Description

The **KsGateRemoveOnInputFromAnd** function removes an existing input that is in the ON state from an AND gate.

## Parameters

### `AndGate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the AND gate from which to remove an ON input.

## Remarks

**KsGateRemoveOnInputFromAnd** should only be used on gates that were specifically created as AND gates; AVStream does not verify that the given gate is truly an AND gate.

For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

This call is an empty function. It should be used for code readability and clarity.

## See also

[KsGateAddOffInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoand)

[KsGateAddOnInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoand)

[KsGateRemoveOffInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromand)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)