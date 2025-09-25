# KsGateAddOffInputToOr function

## Description

The **KsGateAddOffInputToOr** function adds a new input in the OFF state to a given OR gate.

## Parameters

### `OrGate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the OR gate to which to add a new OFF input.

## Remarks

This function should only be used on gates that were specifically created as OR gates; AVStream does not verify that the given gate is an OR gate.

This call is an empty function. It should be used for code readability and clarity.

## See also

[KsGateAddOnInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoor)

[KsGateRemoveOffInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromor)

[KsGateRemoveOnInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromor)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)