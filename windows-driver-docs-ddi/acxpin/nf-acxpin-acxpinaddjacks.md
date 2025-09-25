## Description

The **AcxPinAddJacks** function adds an array of jacks to the specified pin.

## Parameters

### `Pin` [in]

The pin to which the jacks are added.

### `Jacks` [in, reads(jackCount)]

A pointer to an array of **ACXJACK** objects to add to the specified *Pin*.

### `jackCount` [in]

The number of **ACXJACK** objects in the *Jacks* array.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)