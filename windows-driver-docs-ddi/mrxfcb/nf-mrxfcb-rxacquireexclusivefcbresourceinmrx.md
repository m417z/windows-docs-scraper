# RxAcquireExclusiveFcbResourceInMRx function

## Description

**RxAcquireExclusiveFcbResourceInMRx** acquires the FCB resource for a network mini-redirector driver in exclusive mode. This routine will wait for the FCB resource to be free if it was previously acquired and does not return control until the exclusive resource has been acquired.

## Parameters

### `Fcb`

A pointer to the FCB. This parameter is required and cannot be **NULL**.

## Return value

**RxAcquireExclusiveFcbResourceInMRx** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_LOCK_NOT_GRANTED** | The FCB resource was not acquired. |

## Remarks

The synchronization resources of interest to a network mini-redirector driver are primarily associated with the FCB. There is a paging I/O resource and a regular resource. The paging I/O resource is managed internally by RDBSS. The only resource accessible to a network mini-redirector driver is the regular resource which should be accessed using **RxAcquireExclusiveFcbResourceInMRx**, **RxAcquireExclusiveFcbResourceInMRxEx**, or **RxAcquireSharedFcbResourceInMRx**, depending on the acquired mode desired.

**RxAcquireExclusiveFcbResourceInMRx** will wait for the FCB resource to be free if it was previously acquired and does not return control until the exclusive resource has been acquired. This routine acquires the FCB resource even if the RX_CONTEXT associated with this FCB has been canceled.

An FCB resource acquired with **RxAcquireExclusiveFcbResourceInMRx** should be released by calling **RxReleaseFcbResourceInMRx** or **RxReleaseFcbResourceForThreadInMRx**.

## See also

[RxAcquireSharedFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquiresharedfcbresourceinmrx)

[RxAcquireSharedFcbResourceInMRxEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquiresharedfcbresourceinmrxex)

[RxReleaseFcbResourceForThreadInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxreleasefcbresourceforthreadinmrx)

[RxReleaseFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxreleasefcbresourceinmrx)