# MRxShouldTryToCollapseThisOpen routine

The *MRxShouldTryToCollapseThisOpen* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector indicate if RDBSS should try and collapse an open request onto an existing file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxShouldTryToCollapseThisOpen* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_MORE_PROCESSING_REQUIRED** | A network mini-redirector returns this value to disable collapsing of this open request. |

## Remarks

*MRxShouldTryToCollapseThisOpen* is called to determine if an open request should not be collapsed.

Before calling *MRxShouldTryToCollapseThisOpen*, RDBSS modifies the following member in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **pRelevantSrvOpen** member is set to the SRV\_OPEN.

The call to *MRxShouldTryToCollapseThisOpen* could be a change notify request for a directory. Therefore, the network mini-redirector might not allow collapsing open requests so that change notification works correctly.

RDBSS disallows collapsing opens if the **Create.NtCreateParameters.CreateOptions** member of the RX\_CONTEXT structure has the FILE\_OPEN\_FOR\_BACKUP\_INTENT option or the FILE\_DELETE\_ON\_CLOSE option set.

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

[**MRxExtendForNonCache**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxextendfornoncache)

[**MRxFlush**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxflush)

[**MRxForceClosed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_forceclosed_calldown)

[**MRxIsLockRealizable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_is_lock_realizable)

[**MRxTruncate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxtruncate)

[**MRxZeroExtend**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxzeroextend)

