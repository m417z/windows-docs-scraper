# IDebugDataSpaces2::GetVirtualTranslationPhysicalOffsets

## Description

The **GetVirtualTranslationPhysicalOffsets** method returns the physical addresses of the system paging structures at different levels of the paging hierarchy.

## Parameters

### `Virtual` [in]

Specifies the location in the target's virtual address space to translate.

### `Offsets` [out, optional]

Receives the physical addresses for the system paging structures. If it is set to **NULL**, this information is not returned.

### `OffsetsSize` [in]

Specifies the number of elements the array *Offsets* holds. This is the maximum number of addresses that will be returned.

### `Levels` [out, optional]

Receives the number of levels in the paging hierarchy for the specified address. If this is **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **HRESULT_FROM_NT(STATUS_NO_PAGEFILE)** | No physical page containing the specified address could be found. |

## Remarks

This method is only available in kernel-mode debugging.

Translating a virtual address to a physical address requires Windows to walk down the paging hierarchy. At each level it reads paging information from physical memory. This method returns the offsets for these physical pages. The number of levels in the paging hierarchy may be different for different addresses.

The address at the last level of the hierarchy is the physical address corresponding to the specified virtual address. This is what [VirtualToPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-virtualtophysical) would return.

For details on how virtual addresses are translated into physical addresses, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.