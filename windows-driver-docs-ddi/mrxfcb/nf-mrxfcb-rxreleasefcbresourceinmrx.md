# RxReleaseFcbResourceInMRx function

## Description

**RxReleaseFcbResourceInMRx** releases the FCB resource acquired by a network mini-redirector driver.

## Parameters

### `Fcb`

A pointer to the FCB. This parameter is required and cannot be **NULL**.

## Remarks

The synchronization resources of interest to a network mini-redirector driver are primarily associated with the FCB. There is a paging I/O resource and a regular resource. The paging I/O resource is managed internally by RDBSS. The only resource accessible to a network mini-redirector driver is the regular resource.

The **RxReleaseFcbResourceInMRx** routine will release an FCB resource previously acquired by calling **RxAcquireExclusiveFcbResourceInMRx**, **RxAcquireSharedFcbResourceInMRx**, or **RxAcquireSharedFcbResourceInMRxEx**. If there are any pending buffering state change requests for this FCB, then these buffering state changes will be processed first before the **RxReleaseFcbResourceInMRx** routine returns.

## See also

[RxAcquireExclusiveFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquireexclusivefcbresourceinmrx)

[RxAcquireSharedFcbResourceInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquiresharedfcbresourceinmrx)

[RxAcquireSharedFcbResourceInMRxEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxacquiresharedfcbresourceinmrxex)

[RxReleaseFcbResourceForThreadInMRx](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrxfcb/nf-mrxfcb-rxreleasefcbresourceforthreadinmrx)