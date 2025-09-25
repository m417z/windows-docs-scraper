# PMRX_DEALLOCATE_FOR_FCB callback function

## Description

The **MRxDeallocateForFcb** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that the network mini-redirector deallocate an FCB structure. This call is in response to a request to close a file system object.

## Parameters

### `Fcb`

[in, out] A pointer to the FCB structure to deallocate.

## Return value

**MRxDeallocateForFcb** returns STATUS_SUCCESS.

## Remarks

**MRxDeallocateForFcb** is called by [**RxFinalizeNetFCB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizenetfcb) as part of the process to finalize an FCB structure. The calls to **RxFinalizeNetFCB** and **MRxDeallocateForFcb** occur when an [**IRP_MJ_CLOSE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) request is received.

## See also

[**MRxAreFilesAliased**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[**MRxCleanupFobx**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549841(v=vs.85))

[**MRxCloseSrvOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown)

[**MRxCollapseOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcollapseopen)

[**MRxCreate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcreate)

[**MRxDeallocateForFobx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fobx)

[**MRxExtendForCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extendfile_calldown)

[**MRxExtendForNonCache**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxextendfornoncache)

[**MRxFlush**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxflush)

[**MRxForceClosed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_forceclosed_calldown)

[**MRxIsLockRealizable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_is_lock_realizable)

[**MRxShouldTryToCollapseThisOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxshouldtrytocollapsethisopen)

[**MRxTruncate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxtruncate)

[**MRxZeroExtend**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxzeroextend)

[**RxFinalizeNetFCB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizenetfcb)