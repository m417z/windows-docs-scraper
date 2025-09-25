# IDebugDataSpaces4::ReadProcessorSystemData

## Description

The **ReadProcessorSystemData** method returns data about the specified processor.

## Parameters

### `Processor` [in]

Specifies the processor whose data is to be read.

### `Index` [in]

Specifies the data type to read. The following table contains the valid values. After successful completion, the data returned in the buffer *Buffer* has the type specified by the middle column.

| Value | Description |
| --- | --- |
| DEBUG_DATA_KPCR_OFFSET | Returns the virtual address of the processor's Processor Control Region (PCR).<br><br>In this case, the argument *Buffer* can be considered to have type PULONG64. |
| DEBUG_DATA_KPRCB_OFFSET | Returns the virtual address of the processor's Processor Control Block (PRCB).<br><br>In this case, the argument *Buffer* can be considered to have type PULONG64. |
| DEBUG_DATA_KTHREAD_OFFSET | Returns the virtual address of the KTHREAD structure for the system thread running on the processor.<br><br>In this case, the argument *Buffer* can be considered to have type PULONG64. |
| DEBUG_DATA_BASE_TRANSLATION_VIRTUAL_OFFSET | Returns the virtual address of the base of the paging information owned by the operating system or the processor. The address and the content at the address are processor- and operating-system-dependent. <br><br>In this case, the argument *Buffer* can be considered to have type PULONG64. |
| DEBUG_DATA_PROCESSOR_IDENTIFICATION | Returns a description of the processor.<br><br>In this case, the argument *Buffer* can be considered to have type PDEBUG_PROCESSOR_IDENTIFICATION_ALL . |
| DEBUG_DATA_PROCESSOR_SPEED | Returns the speed of the processor in MHz. This may not work in a particular session.<br><br>In this case, the argument *Buffer* can be considered to have type PULONG. |

### `Buffer` [out]

Receives the processor data. Upon successful completion of the method, the contents of this buffer may be accessed by casting *Buffer* to the type specified in the above table.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be returned.

### `DataSize` [out, optional]

Receives the size of the data in bytes. If *DataSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.

For information about the PCR, PRCB, and KTHREAD structures, as well as information about paging tables, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.