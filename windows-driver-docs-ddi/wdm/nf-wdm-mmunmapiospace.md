# MmUnmapIoSpace function

## Description

The **MmUnmapIoSpace** routine unmaps a specified range of physical addresses previously mapped by **MmMapIoSpace**.

## Parameters

### `BaseAddress` [in]

Pointer to the base virtual address to which the physical pages were mapped.

### `NumberOfBytes` [in]

Specifies the number of bytes that were mapped.

## Remarks

If a driver calls **MmMapIoSpace** during device start-up, it must call **MmUnmapIoSpace** when it receives a PnP stop-device or remove-device IRP for the same device object.

## See also

[MmMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapiospace)