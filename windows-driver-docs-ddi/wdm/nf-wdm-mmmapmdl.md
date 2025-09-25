# MmMapMdl function

## Description

This function maps physical pages described by a memory descriptor
list (MDL) into the system virtual address space.

## Parameters

### `MemoryDescriptorList` [in]

A pointer to a valid MDL.

### `Protection` [in]

A bitwise of flags that indicates the protection to set for the pages. Possible values are PAGE_Xxx constants defined in Wdm.h.

### `DriverRoutine` [in]

 A pointer to a driver-supplied callback routine ([MM_MDL_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-mm_mdl_routine)) that is invoked after the MDL is mapped.

### `DriverContext` [in]

A pointer to a driver-defined context. The driver's callback function can store any status information in the driver context and then examine the value, when the callback is invoked.

## Return value

 If the callback function pointed to by *DriverRoutine* was invoked, this function returns STATUS_SUCCESS. The function returns an appropriate NTSTATUS value if the MDL could not be mapped or the callback function could not be invoked.

## Remarks

**MmMapMdl** maps the MDL (if it's not already mapped), invokes the callback, then releases the mapping (if one was created). The caller does not need to perform any cleanup.

## See also

[MM_MDL_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-mm_mdl_routine)