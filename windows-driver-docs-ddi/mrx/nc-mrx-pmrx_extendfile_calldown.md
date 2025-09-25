# PMRX_EXTENDFILE_CALLDOWN callback function

## Description

The **MRxExtendForCache** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector extend a file when the file is being cached by the cache manager.

## Parameters

### `RxContext`

[in, out] A pointer to the RX_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

### `NewFileSize`

[in, out] A pointer to the LARGE_INTEGER structure indicating the byte count of the new file size.

### `NewAllocationSize`

[out] A pointer to the LARGE_INTEGER structure for storing the new allocation size when **MRxExtendForCache** returns.

## Return value

**MRxExtendForCache** returns STATUS_SUCCESS on success or an error code on failure.

## Remarks

**MRxExtendForCache** handles network requests to extend the file for cached I/O.

Before calling **MRxExtendForCache**, RDBSS modifies the following members in the RX_CONTEXT structure pointed to by the **RxContext** parameter:

* **LowIoContext.Operation** is set to LOWIO_OP_WRITE
* **LowIoContext.ParamsFor.ReadWrite.Flags** has the LOWIO_READWRITEFLAG_EXTENDING_FILESIZE bit set

A network mini-redirector that caches file or directory information may need to invalidate its cache information when the file is extended.

## See also

[**MRxAreFilesAliased**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[**MRxCleanupFobx**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549841(v=vs.85))

[**MRxCloseSrvOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown)

[**MRxCollapseOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcollapseopen)

[**MRxCreate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcreate)

[**MRxDeallocateForFcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fcb)

[**MRxDeallocateForFobx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fobx)

[**MRxExtendForNonCache**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxextendfornoncache)

[**MRxFlush**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxflush)

[**MRxForceClosed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_forceclosed_calldown)

[**MRxIsLockRealizable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_is_lock_realizable)

[**MRxShouldTryToCollapseThisOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxshouldtrytocollapsethisopen)

[**MRxTruncate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxtruncate)

[**MRxZeroExtend**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxzeroextend)