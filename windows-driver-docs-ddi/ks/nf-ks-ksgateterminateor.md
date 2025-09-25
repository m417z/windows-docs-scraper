# KsGateTerminateOr function

## Description

The **KsGateTerminateOr** function deletes an existing OR gate and removes an input from any attached AND gate.

## Parameters

### `OrGate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure that is the OR gate to delete. This gate must be at the beginning of a gate chain.

## Remarks

Logical gates should be deleted in a front to back manner. **KsGateTerminateOr** does not update the gate chain for gates that are deleted at the end or in the middle. For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

## See also

[KsGateInitializeAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeand)

[KsGateInitializeOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeor)

[KsGateTerminateAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateterminateand)