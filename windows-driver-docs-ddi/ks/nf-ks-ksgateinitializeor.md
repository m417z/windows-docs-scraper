# KsGateInitializeOr function

## Description

The **KsGateInitializeOr** function initializes a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure as an OR gate and attaches it to the AND gate specified by *NextAndGate*.

## Parameters

### `OrGate` [in]

A pointer to the KSGATE structure to initialize as a new OR gate.

### `NextAndGate` [in, optional]

A pointer to an existing KSGATE structure to which *OrGate* attaches. Optional.

## Remarks

The next gate (following *OrGate*) must be an AND gate, whether it is specified in this call or later. If you need to connect an OR gate to another OR gate, use [KsGateInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitialize). For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

This function is an inline call to **KsGateInitialize**.

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitialize)

[KsGateInitializeAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeand)

[KsGateTerminateAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateterminateand)

[KsGateTerminateOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateterminateor)