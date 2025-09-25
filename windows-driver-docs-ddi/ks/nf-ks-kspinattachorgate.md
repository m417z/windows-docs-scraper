# KsPinAttachOrGate function

## Description

The **KsPinAttachOrGate** function connects *Pin* as an input to a previously initialized OR gate, and connects *OrGate* as an input to the relevant filter's AND gate.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure to use an input to the OR gate.

### `OrGate` [in, optional]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure that is the previously initialized OR gate to connect to the relevant filter's AND gate. If this optional parameter is NULL, any **KSGATE** currently attached to the pin is detached.

## Remarks

To insert the gate, first call [KsGateInitializeOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeor). Then call **KsPinAttachOrGate**. For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

Do not leave an unattached OR gate at filter creation time. Instead, create the OR gate later, for example when the minidriver instantiates the pin.

**KsPinAttachOrGate** must be called at IRQL = PASSIVE_LEVEL before the pin in question leaves KSSTATE_STOP.

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateInitializeOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeor)

[KsPinAttachAndGate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinattachandgate)