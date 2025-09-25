# RxUnregisterMinirdr function

## Description

**RxUnregisterMinirdr** is an inline routine called by a network mini-redirector driver to de-register the driver with RDBSS and remove the registration information from the internal RDBSS registration table.

## Parameters

### `RxDeviceObject` [in]

A pointer to the RDBSS device object for this network redirector.

## Remarks

**RxUnregisterMinirdr** is an inline routine defined in *rxstruc.h* that de-registers the driver with RDBSS and removes the registration information from the internal RDBSS registration table. If name tables were initialized, then these tables will be finalized for release. Any outstanding asynchronous requests to the network mini-redirector are spun down, and any worker threads associated with the redirector are spun down. **RxUnregisterMinirdr** also tries to remove the device object from the system by calling **IoDeleteDevice**.

Typically, the **RxUnregisterMinirdr** routine is called as a result of an FSCTL or IOCTL request from a user-mode application or service to unload the network mini-redirector, although this call could also be made from the network mini-redirector or as part of shutdown processing by the operating system or as a result of a failure in the [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

Note that the inline routine, **RxUnregisterMinirdr**, is the preferred way to unregister a driver with RDBSS. The **RxUnregisterMinirdr** inline routine calls **RxpUnregisterMinirdr**, but then also decrements the object reference to the RDBSS device object so that this object can be released by the system.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[IoDeleteDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletedevice)

[RxRegisterMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxregisterminirdr)

[RxStartMiniRdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstartminirdr)

[RxStopMiniRdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstopminirdr)

[RxpUnregisterMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxpunregisterminirdr)