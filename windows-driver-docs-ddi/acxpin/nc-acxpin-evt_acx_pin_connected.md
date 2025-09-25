## Description

The **EVT_ACX_PIN_CONNECTED** callback function is implemented by the driver and is called when the circuit bridge pin is connected to bridge pin of another circuit.

## Parameters

### `Pin`

An [ACXPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/) object representing the specific pin that was connected.

### `TargetCircuit`

An **ACXTARGETCIRCUIT** object representing the circuit to which the *Pin* was connected.

### `TargetPinId`

The identifier of the pin in the *TargetCircuit* to which the *Pin* was connected.

## Remarks

This event happens when the composite circuit is fully initialized. From this point on, the *TargetCircuit* can be used to send [kernel streaming properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties) and [kernel streaming methods](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-methods) requests.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)