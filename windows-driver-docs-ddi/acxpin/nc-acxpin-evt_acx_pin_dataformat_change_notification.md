## Description

The **EVT_ACX_PIN_DATAFORMAT_CHANGE_NOTIFICATION** callback function is implemented by the driver and is called when a data format change occurs on the specified pin.

## Parameters

### `Pin`

An [ACXPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/) object representing the specific pin for which the data format change occurred.

### `TargetCircuit`

An **ACXTARGETCIRCUIT** object representing the circuit to which the *Pin* is connected.

### `TargetPinId`

The identifier of the pin in the *TargetCircuit* to which the *Pin* is connected.

## Remarks

The change is triggered by a change in the corresponding (connected) remote pin or circuit.

### ACX requirements

**Minimum ACX version:** 1.1

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)