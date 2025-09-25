# PMRX_CALLDOWN_CTX callback function

## Description

The **MRxStart** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to start the network mini-redirector.

## Parameters

### `RxContext` [in, out]

A pointer to the RX_CONTEXT structure. This parameter contains the IRP that requested the network mini-redirector to start.

### `RxDeviceObject` [in, out]

A pointer to the RDBSS_DEVICE_OBJECT structure for this network mini-redirector.

## Return value

**MRxStart** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| ------------- | ------------- |
| STATUS_REDIRECTOR_STARTED | The network mini-redirector was already started. |
| STATUS_UNSUCCESSFUL | The network mini-redirector was unable to start successfully.

## Remarks

**MRxStart** completes the initialization of the network mini-redirector from the RDBSS perspective. Note that this is different from the initialization done in the **DriverEntry** routine. Any initialization that depends on RDBSS should be done as part of this routine while the initialization that is independent of RDBSS should be done in the **DriverEntry** routine.

Before calling **MRxStart**, RDBSS modifies the following members in the RX_CONTEXT structure pointed to by the **RxContext** parameter:

The **MajorFunction** member is set to the major function of the IRP.

The **LowIoContext.ParamsFor.FsCtl.FsControlCode** member is set to the FSCTL code for the IRP if this was an FSTCL request used to start the network mini-redirector.

**MRxStart** is called by RDBSS from the [**RxStartMinirdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstartminirdr) routine. Before calling **MRxStart**, RDBSS will register **RxDeviceObject** of the network mini-redirector as a file system. RDBSS will also register the network mini-redirector as a UNC provider if the network mini-redirector indicates support for UNC names.

If **MRxStart** returns STATUS_SUCCESS, then the routine was successful. Any other return value indicates that an error occurred in the startup sequence.

If **MRxStart** returns STATUS_SUCCESS, RDBSS sets the state of RDBSS to RDBSS_STARTED. This state is stored in the **StartStopContext.State** member of the RDBSS_DEVICE_OBJECT structure pointed to by **RxDeviceObject**.

A network mini-redirector would normally maintain an internal variable indicating whether the network mini-redirector is started. For example, a network mini-redirector might track when it is stopped, started, and when a start operation or stop operation is in progress.

## See also

[**MRxDevFcbXXXControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxdevfcbxxxcontrolfile)

[**MRxStop**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxstop)

[**RxStartMinirdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstartminirdr)