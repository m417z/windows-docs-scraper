# RxReleaseFcbResourceForThreadInMRx function

## Description

**RxReleaseFcbResourceForThreadInMRx** releases the FCB resource acquired by a network mini-redirector driver with a particular thread ID.

## Parameters

### `pRxContext` [in]

A pointer to the RX_CONTEXT structure.

### `MrxFcb` [in, out]

A pointer to the FCB. This parameter is required and cannot be **NULL**.

### `ResourceThreadId` [in]

The thread ID that originally acquired the resource.

## Remarks

The synchronization resources of interest to a network mini-redirector driver are primarily associated with the FCB. There is a paging I/O resource and a regular resource. The paging I/O resource is managed internally by RDBSS. The only resource accessible to a network mini-redirector driver is the regular resource.

The **RxReleaseFcbResourceForThreadInMRx** routine will release an FCB resource previously acquired for a particular thread ID. This resource would have been acquired by calling **RxAcquireExclusiveFcbResourceInMRx**, **RxAcquireSharedFcbResourceInMRx**, or **RxAcquireSharedFcbResourceInMRxEx**. If there are any pending buffering state change requests for this FCB, then these buffering state changes will be processed first before the **RxReleaseFcbResourceForThreadInMRx** routine returns.

## See also

[RxAcquireExclusiveFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquireexclusivefcbresourceinmrx)

[RxAcquireSharedFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquiresharedfcbresourceinmrx)

[RxAcquireSharedFcbResourceInMRxEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquiresharedfcbresourceinmrxex)

[RxReleaseFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxreleasefcbresourceinmrx)