# KsPinAttachAndGate function

## Description

The **KsPinAttachAndGate** function connects *Pin* as an input to a previously initialized AND gate, and connects *AndGate* as an input to the relevant filter's AND gate.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure to use an input to the AND gate.

### `AndGate` [in, optional]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure that is the previously initialized AND gate to connect to the relevant filter's AND gate. If this optional parameter is **NULL**, any **KSGATE** currently attached to the pin is detached.

## Remarks

To insert the gate, first call [KsGateInitializeAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeand). Then call **KsPinAttachAndGate**. For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

**KsPinAttachAndGate** must be called at IRQL = PASSIVE_LEVEL before the pin in question leaves KSSTATE_STOP.

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateInitializeAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeand)

[KsPinAttachOrGate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinattachorgate)