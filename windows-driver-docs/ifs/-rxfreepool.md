# \_RxFreePool function

**\_RxFreePool** releases memory that was previously allocated using **\_RxAllocatePoolWithTag**.

## Parameters

*Buffer*
A pointer to the buffer of pool memory to be released.

*FileName*
A pointer to the source file name where the memory allocation occurred. This parameter is not currently used.

*LineNumber*
The line number in the source file where the memory allocation occurred. This parameter is not currently used.

## Return value

None

## Remarks

It is recommended that the **RxFreePool** macro be called instead of using this routine directly. On retail builds, this macro is defined to call **ExFreePool**.

Memory allocated with [**\_RxAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ifs/-rxallocatepoolwithtag) should be released by calling **\_RxFreePool**.

The **\_RxFreePool** routine calls **ExFreePool**.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Ntrxdef.h (include Ntrxdef.h) |
| IRQL | <= APC_LEVEL |

## See also

[**\_RxAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ifs/-rxallocatepoolwithtag)

[**\_RxCheckMemoryBlock**](https://learn.microsoft.com/windows-hardware/drivers/ifs/-rxcheckmemoryblock)

