# PMRX_DEALLOCATE_FOR_FOBX callback function

## Description

The **MRxDeallocateForFobx** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that the network mini-redirector deallocate an FOBX structure. This call is in response to a request to close a file system object.

## Parameters

### `Fobx`

[in, out] A pointer to the FOBX structure to deallocate.

## Return value

**MRxDeallocateForFobx** returns STATUS_SUCCESS.

## Remarks

**MRxDeallocateForFobx** is called by [**RxFinalizeNetFOBX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetfobx) as part of the process to finalize an FOBX structure. The calls to **RxFinalizeNetFOBX** and **MRxDeallocateForFobx** occurs when an [**IRP_MJ_CLOSE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) request is received.

RDBSS ignores the return value from **MRxDeallocateForFobx**.

## See also

[**MRxAreFilesAliased**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[**MRxCleanupFobx**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549841(v=vs.85))

[**MRxCloseSrvOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown)

[**MRxCollapseOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcollapseopen)

[**MRxCreate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcreate)

[**MRxDeallocateForFcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fcb)

[**MRxExtendForCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extendfile_calldown)

[**MRxExtendForNonCache**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxextendfornoncache)

[**MRxFlush**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxflush)

[**MRxForceClosed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_forceclosed_calldown)

[**MRxIsLockRealizable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_is_lock_realizable)

[**MRxShouldTryToCollapseThisOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxshouldtrytocollapsethisopen)

[**MRxTruncate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxtruncate)

[**MRxZeroExtend**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxzeroextend)

[**RxFinalizeNetFOBX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetfobx)

[**RxFinalizeNetFCB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizenetfcb)