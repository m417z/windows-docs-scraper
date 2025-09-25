# RxStartMinirdr function

## Description

**RxStartMinirdr** is called to start up a network mini-redirector that has previously called to register with RDBSS. As part of **RxStartMinirdr**, RDBSS will also register the network mini-redirector driver as a universal naming convention (UNC) provider with the Multiple UNC Provider (MUP) if the driver indicates support for UNC names.

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT structure to use to get the device object and determine if this is a file system process.

### `PostToFsp` [out]

A pointer to a logical value set to TRUE on return if the request must be posted for later processing by the file system process.

## Return value

**RxStartMinirdr** returns STATUS_SUCCESS if the startup sequence was successful or one of the following error values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | The request to register as a UNC provider failed because access was denied. |
| STATUS_ACCESS_VIOLATION | The request to register as a UNC provider failed with an access violation. |
| STATUS_INSUFFICIENT_RESOURCES | There were insufficient resources to complete this routine. |
| STATUS_PENDING | The startup sequence for RDBSS and network mini-redirectors must be completed in the context of system process, not a user-mode application process. If the call to **RxStartMinirdr** comes from a user-mode process (a user-mode service request, for example), then the request is posted for later processing within RDBSS and STATUS_PENDING will be returned. This error can also be returned if certain internal RDBSS locks cannot be acquired without waiting. The call will be completed later from a system thread. |
| STATUS_REDIRECTOR_STARTED | The network mini-redirector was already started. |

## Remarks

A network mini-redirector registers with RDBSS whenever the driver is loaded by the kernel and then unregisters with RDBSS when the driver is unloaded. A network mini-redirector informs RDBSS that it has been loaded by calling **RxRegisterMinirdr**, the registration routine exported from RDBSS. As part of this registration process, the network mini-redirector passes a parameter to **RxRegisterMinirdr** that is a pointer to a large structure, MINIRDR_DISPATCH, which contains configuration information for the network mini-redirector and a table of pointers to callback routines implemented by the network mini-redirector driver. RDBSS uses the callback routines passed in this structure to communicate with the network mini-redirector.

The network mini-redirector does not actually start operation until it receives a call to its [MRxStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown_ctx) routine, one of the callback routines passed in the MINIRDR_DISPATCH structure. The **MrxStart** callback routine must be implemented by the network mini-redirector driver if it wishes to receive callback routines for operations unless the network mini-redirector preserves its own driver dispatch entry points. Otherwise, RDBSS will only allow the following I/O request packets through to the driver until **MrxStart** returns successfully:

* IRP requests for device create operations and device operations where the **FileObject->FileName.Length** parameter on the IRPSP is zero and the **FileObject->RelatedFileObject** parameter is NULL.

For any other IRP request, the RDBSS dispatch routine [RxFsdDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxfsddispatch) will return a status of STATUS_REDIRECTOR_NOT_STARTED.

The RDBSS dispatch routine will also fail any requests for the following I/O request packets:

* IRP_MJ_CREATE_MAILSLOT
* IRP_MJ_CREATE_NAMED_PIPE

The network mini-redirector **MrxStart** routine is called by RDBSS when the **RxStartMinirdr** routine is called. The RDBSS **RxStartMinirdr** routine is usually called as a result of an FSCTL or IOCTL request from a user-mode application or service to start the network mini-redirector. The call to **RxStartMinirdr** cannot be made from the [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine of the network mini-redirector after a successful call to **RxRegisterMinirdr** since some of the start processing requires that the driver initialization be completed.

When RDBSS receives an FSCTL or IOCTL request sent to network mini-redirector driver from user mode, RDBSS creates an RX_CONTEXT structure and passes this call to the network mini-redirector's [MRxLowIOSubmit[LOWIO_OP_FSCTL]](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxlowiosubmit-lowio-op-fsctl-) or [MRxLowIOSubmit[LOWIO_OP_IOCTL]](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxlowiosubmit-lowio-op-ioctl-) call back routine defined in the MINIRDR_DISPATCH structure. The network mini-redirector's implementation of this call back routine would recognize the request to start and call **RxStartMinirdr**. This normal process of events is listed below in more detail:

1. A user-mode application issues a private FSCTL or IOCTL request to start the network mini-redirector.

2. The RDBSS kernel driver receives the FSCTL or IOCTL request on behalf of the network mini-redirector since RDBSS has replaced the driver dispatch entry points of the mini-redirector driver to point to RDBSS internal routines. Note that this assumes that the network mini-redirector did not set the RX_REGISTERMINI_FLAG_DONT_INIT_DRIVER_DISPATCH in the **Controls** parameter when calling **RxRegisterMinirdr**. This option passed to **RxRegisterMinirdr** would be unusual and indicates that the network mini-redirector does not want RDBSS to replace its driver dispatch entry points.

3. RDBSS receives the FSCTL or IOCTL request internally on behalf of the network redirector. The RDBSS dispatcher allocates and initializes an RX_CONTEXT structure. RDBSS then calls the network mini-redirector **MRxLowIOSubmit[LOW_OP_FSCTL]** or **MRxLowIOSubmit[LOW_OP_IOCTL]** routine defined in the MINIRDR_DISPATCH structure for this network mini-redirector, passing in the initialized RX_CONTEXT structure as a parameter.

4. The network mini-redirector implementation of this call back routine would recognize the private FSCTL or IOCTL request to start and call **RxStartMinirdr**, passing in a pointer the RX_CONTEXT structure it received from RDBSS as the **RxContext** parameter and the address of the **PostToFSP** member of **RxContext** as the **PostToFsp** parameter.

5. Since this call was initiated from user mode, **RxStartMinirdr** would return STATUS_PENDING and set **PostToFsp** to TRUE.

6. The network mini-redirector **MRxLowIOSubmit[LOW_OP_FSCTL]** or **MRxLowIOSubmit[LOW_OP_IOCTL]** routine would receive this return value and pass it back to the RDBSS dispatcher.

7. The RDBSS dispatcher would receive the STATUS_PENDING return value and would set **PostToFsp** to TRUE and would then post a request to a worker thread to re-execute the call to the network mini-redirector.

After this point, there are two possible outcomes based on whether the FSCTL or IOCTL was requested as an asynchronous or a synchronous operation.

If this were an asynchronous request, the following would occur:

* The user-mode caller would receive the STATUS_PENDING response from the call. The posted worker thread would eventually call **RxStartMinirdr** from a file system thread and the call would be processed. The **RxStartMinirdr** routine will try to register the network mini-redirector as a UNC provider, if requested. On versions of Windows prior to Windows Vista, RDBSS will then try to register the network mini-redirector as a file system with the I/O manager. If these calls are successful, then **RxStartMinirdr** calls the **MrxStart** callback routine implemented by the network mini-redirector. The return value from **MrxStart** would eventually be returned to the user-mode application that initiated the calling sequence process as an asynchronous operation.

If this were a synchronous request, the following would occur:

* The user-mode caller would not receive the STATUS_PENDING response but would be forced to wait until the call returned from the posted worker thread. The posted worker thread would eventually call **RxStartMinirdr** from a file system thread and the call would be processed. The **RxStartMinirdr** routine will try to register the network mini-redirector as a UNC provider, if requested. On versions of Windows prior to Windows Vista, RDBSS will then try to register the network mini-redirector as a file system with the I/O manager. If these calls are successful, then **RxStartMinirdr** calls the **MrxStart** callback routine implemented by the network mini-redirector. The return value from **MrxStart** would be returned to the user mode application that initiated the calling sequence process.

If a network mini-redirector indicates support for UNC when registering with RDBSS (the **Controls** parameter to **RxRegisterMinirdr**), then **RxStartMinirdr** will try to register the **DeviceName** parameter of the network mini-redirector as a UNC provider with MUP (RDBSS calls [FsRtlRegisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncprovider) on behalf of the network mini-redirector).

On versions of Windows prior to Windows Vista, **RxStartMinirdr** registers the file system with the I/O manager (RDBSS calls [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) on behalf of the network mini-redirector).

If the calls are successful, then **RxStartMinirdr** calls the network mini-redirector **MrxStart** routine. If **MrxStart** returns success, the internal state of the mini-redirector in RDBSS is set to RDBSS_STARTED. The **StartStopContext.Version** member of the mini-redirector device object will also be incremented.

The startup sequence for RDBSS and the network mini-redirector must be completed in the context of the system process if asynchronous operation is requested. If the call to **RxStartMinirdr** comes from a user-mode process (a user mode service request, for example), then the request will be internally posted by RDBSS to a work queue for later processing and STATUS_PENDING will be returned and the **PostToFsp** parameter will be set to TRUE. In addition, If certain internal RDBSS locks cannot be obtained without waiting, STATUS_PENDING is returned and **PostToFsp** is set to TRUE. When STATUS_PENDING is returned, **RxStartMinirdr** will be called again from within a system process. If the FSCTL or IOCTL request that initiated the call to **RxStartMinirdr** was set for asynchronous operation, then RDBSS would return STATUS_PENDING back up the call chain to the original FSCTL or IOCTL request from user mode. In contrast, if the FSCTL or IOCTL request was for synchronous operation, then the call would also be posted to a work thread for later execution, but the FSCTL or IOCTL call would not return to user mode until **RxStartMinirdr** had been executed in the context of the file system process. In this case, the caller of the FSCTL or IOCTL would never see the STATUS_PENDING error return. The more typical behavior is to initiate a synchronous request for these start/stop operations to simplify the user-mode application code.

On an abnormal termination or other failure, **RxStartMinirdr** will try to undo these operations, including de-registering the UNC provider with MUP, unregistering the file system, freeing memory allocated for storing the domain name to be used by mailslot broadcasts, and updating internal RDBSS tables.

## See also

[, RxpUnregisterMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxpunregisterminirdr)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[FsRtlRegisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncprovider)

[IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)

[MRxLowIOSubmit[LOWIO_OP_FSCTL]](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxlowiosubmit-lowio-op-fsctl-)

[MRxLowIOSubmit[LOWIO_OP_IOCTL]](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxlowiosubmit-lowio-op-ioctl-)

[MRxStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown_ctx)

[RxFsdDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxfsddispatch)

[RxRegisterMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxregisterminirdr)

[RxSetDomainForMailslotBroadcast](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxsetdomainformailslotbroadcast)

[RxStopMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstopminirdr)

[RxUnregisterMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxstruc/nf-rxstruc-rxunregisterminirdr)

[__RxFillAndInstallFastIoDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-__rxfillandinstallfastiodispatch)