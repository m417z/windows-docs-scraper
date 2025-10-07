# MRxExtendForNonCache routine

The *MRxExtendForNonCache* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector extend a file when the file is not being cached by the cache manager.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

*pNewFileSize* \[in, out\]
A pointer to the LARGE\_INTEGER value indicating the byte count of the new file size.

*pNewAllocationSize* \[out\]
A pointer to the LARGE\_INTEGER for storing the new allocation size when [**MRxExtendForCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extendfile_calldown) returns.

## Return value

*MRxExtendForNonCache* returns STATUS\_SUCCESS on success or an error code on failure.

## Remarks

*MRxExtendForNonCache* handles network requests to extend the file for non-cached I/O.

Before calling *MRxExtendForNonCache*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

**LowIoContext.Operation** is set to LOWIO\_OP\_WRITE

**LowIoContext.ParamsFor.ReadWrite.Flags** has the LOWIO\_READWRITEFLAG\_EXTENDING\_FILESIZE bit set

A network mini-redirector that caches file or directory information may need to invalidate its cache information when the file is extended.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxAreFilesAliased**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[**MRxCleanupFobx**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549841(v=vs.85))

[**MRxCloseSrvOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown)

[**MRxCollapseOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcollapseopen)

[**MRxCreate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcreate)

[**MRxDeallocateForFcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fcb)

[**MRxDeallocateForFobx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fobx)

[**MRxExtendForCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extendfile_calldown)

[**MRxFlush**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxflush)

[**MRxForceClosed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_forceclosed_calldown)

[**MRxIsLockRealizable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_is_lock_realizable)

[**MRxShouldTryToCollapseThisOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxshouldtrytocollapsethisopen)

[**MRxTruncate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxtruncate)

[**MRxZeroExtend**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxzeroextend)

