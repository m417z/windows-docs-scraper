## Description

The **PoSetSystemWakeDevice** function attempts to extract a PDO from the supplied device object. If a valid PDO is found then it is added to the list of sources which contributed to waking the system from a sleep state. There is a time interval (currently 2 seconds) during which, from the completed wait/wake IRPs, the power manager attempts to build a list of system wake sources.

## Parameters

### `DeviceObject` [in]

Supplies a pointer to the device object that has wait/wake IRPs contributing to waking the system from a sleep state.

## Remarks

## See also