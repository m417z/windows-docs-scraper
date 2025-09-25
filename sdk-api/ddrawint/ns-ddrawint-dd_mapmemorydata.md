# DD_MAPMEMORYDATA structure

## Description

The DD_MAPMEMORYDATA structure contains the information necessary to map or unmap a frame buffer into user-mode memory.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `bMap`

Specifies the memory operation that the driver should perform. A value of **TRUE** indicates that the driver should map memory; **FALSE** means that the driver should unmap memory.

### `hProcess`

Handle to the process whose address space is affected.

### `fpProcess`

Specifies the location in which the driver should return the base address of the process's memory-mapped space when **bMap** is **TRUE**. When **bMap** is **FALSE**, **fpProcess** contains the base address of the memory to be unmapped by the driver.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMapMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mapmemory) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMapMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mapmemory)