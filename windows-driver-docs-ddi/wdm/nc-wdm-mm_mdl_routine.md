# MM_MDL_ROUTINE callback function

## Description

A driver-supplied callback routine that is invoked after a memory descriptor
list (MDL) is mapped by calling the [MmMapMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapmdl) function.

## Parameters

### `DriverContext` [in, optional]

A pointer to a driver-defined context. The driver's callback function can store any status information in the driver context and then examine the value, when the callback is invoked.

### `MappedVa` [in]

A pointer to a buffer that contains the system virtual address of the
mapping.

## See also

[MmMapMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapmdl)