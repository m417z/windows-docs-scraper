# KsGateInitialize function

## Description

The **KsGateInitialize** function initializes a gate for use.

## Parameters

### `Gate` [in]

A pointer to the [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure to initialize.

### `InitialCount` [in]

This parameter specifies the initial count to place on the gate. Fills in *Gate -> Count*. For a new AND gate, this should be 1 (1 − 0 off inputs), and for a new OR gate, this should be 0 (0 on inputs). For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

### `NextGate` [in, optional]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure to which *Gate* should attach its output for state transitions. If this optional parameter is unspecified, *Gate* is not be attached to a subsequent gate.

### `StateToPropagate` [in]

This parameter specifies whether to propagate ON transitions or OFF transitions. For an OR gate, set to **TRUE**; for an AND gate, set to **FALSE**.

## Remarks

Minidrivers should not call **KsGateInitialize** directly, but should instead use [KsGateInitializeAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeand) or [KsGateInitializeOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeor).

AND and OR gates are conceptualizations of the gating mechanism. AVStream does not distinguish between them in the implementation of the common gate functions. The gate functions specific to AND and OR gates are inline calls to the common gate functions.

To learn more about the gate construct in AVStream, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream), [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate).

## See also

[KsGateInitializeAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeand)

[KsGateInitializeOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeor)

[KsGateTerminateAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateterminateand)

[KsGateTerminateOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateterminateor)