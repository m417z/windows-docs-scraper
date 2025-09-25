# MmMapViewInSystemSpace function

## Description

The **MmMapViewInSystemSpace** function maps the specified section into the system's address space.

## Parameters

### `Section`

Supplies a pointer to the section to map.

### `MappedBase`

Contains the address where the section was mapped.

### `ViewSize`

Supplies the size of the view to map. If this is specified as zero, the whole section is mapped. Returns the actual size mapped.

## Return value

This function returns true if the map view operation was successful.

## Remarks

## See also

[MmUnmapViewInSystemSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunmapviewinsystemspace)