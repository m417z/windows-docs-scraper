# MRxCollapseOpen routine

The *MRxCollapseOpen* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that the network mini-redirector collapse an open file system request onto an existing SRV\_OPEN structure.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxCollapseOpen* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the operation. |

## Remarks

*MRxCollapseOpen* is called by RDBSS to collapse an SRV\_OPEN structure locally. The network mini-redirector is consulted to determine if a collapse is possible so there is no reason to call the network mini-redirector twice. If the network mini-redirector decides to collapse the SRV\_OPEN structure, then it will do so and pass back a returnable status. A return value of STATUS\_SUCCESS is a terminating return value. A different return value, for example, STATUS\_MORE\_PROCESSING\_REQUIRED, is considered a non-terminating return value.

Before calling *MRxCollapseOpen*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

**pRelevantSrvOpen** is set to the SRV\_OPEN structure to collapse.

**Create.pSrvCall** is set to the SRV\_CALL structure associated with the SRV\_OPEN.

If the network mini-redirector decides to collapse the SRV\_OPEN structure, then the **SrvOpen** member of the RX\_CONTEXT structure must be set to the collapsed SRV\_OPEN structure.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxAreFilesAliased**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[**MRxCleanupFobx**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549841(v=vs.85))

[**MRxCloseSrvOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown)

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

