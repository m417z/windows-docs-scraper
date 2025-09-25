# RxFillAndInstallFastIoDispatch function

## Description

**RxFillAndInstallFastIoDispatch** fills out a fast I/O dispatch vector to be identical with the normal dispatch I/O vector and installs it into the driver object associated with the device object passed.

## Parameters

### `RxDeviceObject` [in]

A pointer to the RDBSS device object for this network redirector.

### `FastIoDispatch` [in, out]

A pointer to the fast I/O dispatch table to fill in and use.

### `FastIoDispatchSize` [in]

The size, in bytes, of the fast I/O dispatch table passed.

## Remarks

The **RxFillAndInstallFastIoDispatch** routine is implemented differently for monolithic and non-monolithic drivers network mini-redirector.

For non-monolithic network mini-redirector drivers, such as the Microsoft SMB redirector that links to rdbss.sys dynamically, **RxFillAndInstallFastIoDispatch** is a convenience routine that copies the normal dispatch I/O vector table routines to the fast I/O dispatch vector table. This routine would normally be used by a non-monolithic network mini-redirector to fill out the fast I/O dispatch table before calling [**RxRegisterMiniRdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxregisterminirdr). This routine uses the minimum of the **FastIoDispatchSize** parameter and the size of the FAST_IO_DISPATCH structure defined in ntifs.h to determine the number of bytes to copy.

For monolithic network mini-redirectors built by developers, the **RxFillAndInstallFastIoDispatch** routine does nothing.

## See also

[**RxRegisterMinirdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxregisterminirdr)

[**RxSetDomainForMailslotBroadcast**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxsetdomainformailslotbroadcast)

[**RxStartMiniRdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstartminirdr)

[**RxStopMiniRdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstopminirdr)