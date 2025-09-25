## Description

The **AcxPinAddEvents** function adds an array of events to the specified pin.

## Parameters

### `Pin` [in]

The pin to which the events are added.

### `Events` [in, reads(EventsCount)]

A pointer to an array of **ACXEVENT** objects to add to the specified *Pin*.

### `EventsCount` [in]

The number of **ACXEVENT** objects in the *Events* array.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)