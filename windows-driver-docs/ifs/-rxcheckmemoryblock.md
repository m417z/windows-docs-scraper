# \_RxCheckMemoryBlock routine

**\_RxCheckMemoryBlock** checks a memory block for a special RX\_POOL\_HEADER header signature. Note that a network mini-redirector driver would need to add this special signature block to memory allocated in order to use the routine. This routine should not be used since this special header block has not been implemented.

## Parameters

*Buffer*
A pointer to the buffer of pool memory to be released.

*FileName*
A pointer to the source file name where the memory allocation occurred.

*LineNumber*
The line number in the source file where the memory allocation occurred.

## Return value

**RxCheckMemoryBlock** returns **TRUE** if the memory block passes the checks, or **FALSE** if it fails.

## Remarks

It is recommended that the **RxCheckMemoryBlock** macro be called instead of using this routine directly. On retail builds, this macro is defined to nothing. On checked builds, this macro is defined to call **\_RxCheckMemoryBlock**.

This routine should not be used since the special memory header block (RX\_POOL\_HEADER) that this routine checks is not added when calling the **\_RxAllocatePoolWithTag** routine. A network mini-redirector driver would need to add this special signature block to memory allocated in order to use this routine.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Ntrxdef.h (include Ntrxdef.h) |
| IRQL | <= APC_LEVEL |

## See also

[**\_RxAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ifs/-rxallocatepoolwithtag)

[**\_RxFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ifs/-rxfreepool)

