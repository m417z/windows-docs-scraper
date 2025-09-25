# PWINDBG_IOCTL_ROUTINE callback function

## Description

The **PWINDBG_IOCTL_ROUTINE** (**Ioctl**) function performs a variety of different operations. Much of its functionality mirrors the functionality of other functions in wdbgexts.h.

## Parameters

### `IoctlType`

Specifies which **Ioctl** operation to perform. For a list of possible *IoctlType* values, see the "Remarks" section.

### `lpvData`

Points to the address of a data structure. The type of structure that is required depends on the value of *IoctlType*.

### `cbSize`

Specifies the size of the structure that *lpvData* points to.

## Return value

The meaning of return value depends on *IoctlType*. See the page for the corresponding **Ioctl** operation for the meaning of the return value.

## Remarks

The **Ioctl** function is the entry point for many of the functionalities supplied for WdbgExts extensions. Many of the other functions in wdbgexts.h are simply wrappers for calls to **Ioctl**.

The following table lists the possible *IoctlType* values. If the *IoctlType* corresponds to another function, that function is provided; otherwise, a link to the page describing the **Ioctl** operation is provided.

| *IoctlType* constant | Equivalent function | lpData structure |
| --- | --- | --- |
| IG_KD_CONTEXT | [GetKdContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getkdcontext) |  |
| IG_READ_CONTROL_SPACE | [ReadControlSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readcontrolspace)<br><br>**ReadControlSpace64** |  |
| IG_WRITE_CONTROL_SPACE | **WriteControlSpace** |  |
| IG_READ_IO_SPACE | [ReadIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readiospace)<br><br>**ReadIoSpace64** |  |
| IG_WRITE_IO_SPACE | [WriteIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writeiospace)<br><br>**WriteIoSpace64** |  |
| IG_READ_PHYSICAL | [ReadPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readphysical) |  |
| IG_WRITE_PHYSICAL | [WritePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writephysical) |  |
| IG_READ_IO_SPACE_EX | [ReadIoSpaceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readiospaceex)<br><br>**ReadIoSpaceEx64** |  |
| IG_WRITE_IO_SPACE_EX | [WriteIoSpaceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writeiospaceex)<br><br>**WriteIoSpaceEx64** |  |
| IG_SET_THREAD | [SetThreadForOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-setthreadforoperation)<br><br>**SetThreadForOperation64** |  |
| IG_READ_MSR | [ReadMsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readmsr) |  |
| IG_WRITE_MSR | [WriteMsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writemsr) |  |
| IG_GET_DEBUGGER_DATA | [GetDebuggerData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getdebuggerdata) |  |
| IG_GET_KERNEL_VERSION |  | [DBGKD_GET_VERSION64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_dbgkd_get_version64) |
| IG_RELOAD_SYMBOLS | **ReloadSymbols** |  |
| IG_GET_SET_SYMPATH | [GetSetSympath](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getsetsympath) |  |
| IG_GET_EXCEPTION_RECORD |  |  |
| IG_IS_PTR64 | **IsPtr64** |  |
| IG_GET_BUS_DATA |  | [GETSETBUSDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_getsetbusdata) |
| IG_SET_BUS_DATA |  | [GETSETBUSDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_getsetbusdata) |
| [IG_DUMP_SYMBOL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_sym_dump_param) |  | [SYM_DUMP_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_sym_dump_param) |
| IG_LOWMEM_CHECK |  | See Remarks. |
| IG_SEARCH_MEMORY | **SearchMemory** |  |
| IG_GET_CURRENT_THREAD | **GetCurrentThreadAddr** |  |
| IG_GET_CURRENT_PROCESS | **GetCurrentProcessAddr** |  |
| IG_GET_TYPE_SIZE | **GetTypeSize** |  |
| IG_GET_CURRENT_PROCESS_HANDLE | **GetCurrentProcessHandle** |  |
| IG_GET_INPUT_LINE | **GetInputLine** |  |
| IG_GET_EXPRESSION_EX | **GetExpressionEx** |  |
| IG_TRANSLATE_VIRTUAL_TO_PHYSICAL | **TranslateVirtualToPhysical** |  |
| IG_GET_CACHE_SIZE | **GetDebuggerCacheSize** |  |
| IG_READ_PHYSICAL_WITH_FLAGS | **ReadPhysicalWithFlags** |  |
| IG_WRITE_PHYSICAL_WITH_FLAGS | **WritePhysicalWithFlags** |  |
| IG_POINTER_SEARCH_PHYSICAL |  | [POINTER_SEARCH_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_pointer_search_physical) |
| IG_GET_THREAD_OS_INFO |  | [WDBGEXTS_THREAD_OS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_wdbgexts_thread_os_info) |
| IG_GET_CLR_DATA_INTERFACE |  |  |
| IG_GET_TEB_ADDRESS | **GetTebAddress** |  |
| IG_GET_PEB_ADDRESS | **GetPebAddress** |  |

The IG_LOWMEM_CHECK **Ioctl** operation looks for memory corruption in the low 4 GB of memory.

This **Ioctl** operation does not take any parameters and the *lpvData* and *cbSizeOfContext* parameters should be set to **NULL** and zero respectively.

### Return Value

If no corrupt memory was found, the return value is **TRUE**; otherwise, it is **FALSE**.

This operation is only available in kernel-mode debugging, and is only useful when the kernel was started using the **/nolowmem** option.

When the kernel is started with the **/nolowmem** option, the kernel, drivers, operating system, and applications are loaded in memory above 4 GB, while the low 4 GB of memory is filled with a unique pattern. The IG_LOWMEM_CHECK **Ioctl** operation checks this pattern for corruption.

This can be used to verify that a driver works correctly when using physical addresses greater than 32 bits in length. See *Physical Address Extension (PAE)*, **/pae**, and **/nolowmem** in the Windows Driver Kit.