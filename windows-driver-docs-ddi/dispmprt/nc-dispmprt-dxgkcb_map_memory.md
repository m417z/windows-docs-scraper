# DXGKCB_MAP_MEMORY callback function

## Description

The **DxgkCbMapMemory** function maps a range of translated physical addresses (associated with a memory resource assigned to a display adapter) into system space or the virtual address space of a user-mode process.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `TranslatedAddress` [in]

The base translated physical address of the memory range to be mapped. The display miniport driver previously obtained this address by calling [**DxgkCbGetDeviceInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_get_device_information).

### `Length` [in]

The size, in bytes, of the range to be mapped.

### `InIoSpace` [in]

A Boolean value that specifies whether the range is in I/O space (**TRUE**) or memory space (**FALSE**).

### `MapToUserMode` [in]

A Boolean value that specifies whether the range is mapped into user-mode space or system space. If **TRUE**, the range is mapped into the (user-mode) virtual address space of the current process. If **FALSE**, the range is mapped into system space. If **InIoSpace** is **TRUE**, this parameter is ignored.

### `CacheType` [in]

A [**MEMORY_CACHING_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) enumerator that specifies the caching behavior of the mapped range.

### `VirtualAddress` [out]

A pointer to a variable that receives the address of the beginning of the mapped range. The way that the mapped range is accessed depends on the values of **InIoSpace** and **MapToUserMode**. The following table summarizes the different ways that the mapped range is accessed.

| Value of InIoSpace | MapToUserMode is FALSE | MapToUserMode is TRUE |
| ------------------ |----------------------- | --------------------- |
| FALSE | READ_REGISTER_X WRITE_REGISTER_X | User-mode code performs ordinary memory access.|
| TRUE | READ_PORT_X WRITE_PORT_X | Not possible. |

## Return value

**DxgkCbMapMemory** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in **Ntstatus.h**.

## Remarks

The PHYSICAL_ADDRESS data type is defined in **Ntdef.h**.

## See also

[**MEMORY_CACHING_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type)