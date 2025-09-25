# KsGateInitializeAnd function

## Description

The **KsGateInitializeAnd** function initializes a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure as an AND gate and attaches it to the OR gate specified by *NextOrGate*.

## Parameters

### `AndGate` [in]

A pointer to the KSGATE structure to initialize as a new AND gate.

### `NextOrGate` [in, optional]

A pointer to an existing KSGATE structure to which *AndGate* attaches. This parameter should be an OR gate and is optional.

## Remarks

The next gate (following *AndGate*) must be an OR gate, whether it is specified in this call or later. For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

**KsGateInitializeAnd** is an inline call to [KsGateInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitialize).

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitialize)

[KsGateInitializeOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeor)

[KsGateTerminateAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateterminateand)

[KsGateTerminateOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateterminateor)