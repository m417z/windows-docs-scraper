## Description

The **EVT_ACX_PIN_DISCONNECTED** callback function is implemented by the driver and is called when the circuit bridge pin is disconnected from the pin of another circuit.

## Parameters

### `Pin`

An [ACXPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/) object representing the specific pin that was disconnected.

### `TargetCircuit`

An **ACXTARGETCIRCUIT** object representing the circuit from which the *Pin* was disconnected.

### `TargetPinId`

The identifier of the pin in the *TargetCircuit* from which the *Pin* was disconnected.

## Remarks

This callback is not guaranteed to be called in the following scenarios:

- This device is removed or surprised-removed.
- This device is disabled (query-removed and removed) via device manager.

A driver must not rely on this callback as its only resource cleanup.

The specified ACXTARGETCIRCUIT may be already in its stop state b/c the target circuit may already be gone.

Driver can still access its ACXTARGETCIRCUIT context.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)