# RxAcquireSharedFcbResourceInMRxEx function

## Description

**RxAcquireSharedFcbResourceInMRxEx** acquires the FCB resource for a network mini-redirector driver in shared mode. This routine will wait for the FCB resource to be free if it was previously acquired exclusively and does not return control until the shared resource has been acquired.

## Parameters

### `pRxContext` [in]

A pointer to the RX_CONTEXT. This parameter supplies the context of the operation for special treatment by internal RDBSS tracking if this feature is enabled.

### `Fcb`

A pointer to the FCB. This parameter is required and cannot be **NULL**.

## Return value

**RxAcquireSharedFcbResourceInMRxEx** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_LOCK_NOT_GRANTED** | The FCB resource was not acquired. |
| **STATUS_CANCELLED** | The RX_CONTEXT associated with the FCB was canceled. |

## Remarks

The synchronization resources of interest to a network mini-redirector driver are primarily associated with the FCB. There is a paging I/O resource and a regular resource. The paging I/O resource is managed internally by RDBSS. The only resource accessible to a network mini-redirector driver is the regular resource which should be accessed using **RxAcquireExclusiveFcbResourceInMRx**, **RxAcquireExclusiveFcbResourceInMRxEx**, or **RxAcquireSharedFcbResourceInMRx**, depending on the acquired mode desired.

**RxAcquireSharedFcbResourceInMRxEx** will wait for the FCB resource to be free if it was previously acquired exclusively and does not return control until the shared resource has been acquired. This routine acquires the FCB resource even if the RX_CONTEXT associated with this FCB has been canceled.

An FCB resource acquired with **RxAcquireSharedFcbResourceInMRxEx** should be released by calling **RxReleaseFcbResourceInMRx** or **RxReleaseFcbResourceForThreadInMRx**.

## See also

[RxAcquireExclusiveFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquireexclusivefcbresourceinmrx)

**RxAcquireSharedFcbResourceInMRx**

[RxReleaseFcbResourceForThreadInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxreleasefcbresourceforthreadinmrx)

[RxReleaseFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxreleasefcbresourceinmrx)