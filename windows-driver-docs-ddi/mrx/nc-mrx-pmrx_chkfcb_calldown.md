# PMRX_CHKFCB_CALLDOWN callback function

## Description

The **MRxAreFilesAliased** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request the network mini-redirector to determine if two FCB structures represent the same file.

## Parameters

### `Fcb1` [in]

A pointer to the first FCB structure.

### `Fcb2` [in]

A pointer to the second FCB structure.

## Return value

**MRxAreFilesAliased** returns STATUS_SUCCESS indicating that the files are not aliased, or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| ------------- | ------------- |
| STATUS_MORE_PROCESSING_REQUIRED | The **IndexNumber.QuadPart** members of the two FCB structures are identical. This value indicates that the two files that are being compared are aliases. |

## Remarks

RDBSS calls this routine when processing two files that appear to be the same but have different names (for example, an MS-DOS short name and a long name).

**MRxAreFilesAliased** is called by the [**RxPurgeRelatedFobxs**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxpurgerelatedfobxs) routine when purging all the structures of an FOBX structure associated with a NET_ROOT structure. As part of this process, an attempt is made to purge all the FOBX structures that had a close pending before the purge request was received. RDBSS needs to scavenge any temporary FOBX structures in the following cases:

* The **PurgingFcb** parameter that is passed to the [**RxPurgeRelatedFobxs**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxpurgerelatedfobxs) routine is the FCB structure for which the scavenging should occur. When this parameter is a directory, RDBSS needs to ensure that files that can potentially be in that directory are closed.

* The FCB structure that is associated with the FOBX structure on the **FobxsToBeFinalized** member of the RDBSS_SCAVENGER structure doesn't point to the same FCB structure as the **PurgingFCB** parameter passed to [**RxPurgeRelatedFobxs**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxpurgerelatedfobxs). This is complicated by the fact that they might not be the same FCB structures, but are actually the same file because of aliasing. In this case, the **MRxAreFilesAliased** routine is called to determine if the FCB structure is aliased.

**MRxAreFilesAliased** is also called by the [**RxScavengeFobxsForNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxscavengefobxsfornetroot) routine when purging all the file objects associated with a NET_ROOT structure. This is complicated by the fact that the **PurgingFCB** parameter passed to **RxScavengeFobxsForNetRoot** and the FCB structure that is associated with the NET_ROOT structure might actually be the same file because of aliasing. In this case, the **MRxAreFilesAliased** routine is called to determine if the FCB structure is aliased.

## See also

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

[**MRxShouldTryToCollapseThisOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxshouldtrytocollapsethisopen)

[**MRxTruncate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxtruncate)

[**MRxZeroExtend**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxzeroextend)

[**RxFinalizeNetFCB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizenetfcb)

[**RxPurgeRelatedFobxs**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxpurgerelatedfobxs)

[**RxScavengeFobxsForNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxscavengefobxsfornetroot)