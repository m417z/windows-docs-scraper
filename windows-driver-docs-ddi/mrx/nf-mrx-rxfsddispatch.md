# RxFsdDispatch function

## Description

**RxFsdDispatch** implements the file system driver (FSD) dispatch for RDBSS to process an I/O request packet (IRP). A pointer to this routine is copied over the device driver dispatch table for the network mini-redirector driver by the **RxDriverEntry** routine when RDBSS is initialized.

## Parameters

### `RxDeviceObject` [in]

A pointer to the RDBSS device object for this network mini-redirector.

### `Irp` [in]

A pointer to the I/O request packet being processed.

## Return value

**RxFsdDispatch** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INVALID_DEVICE_REQUEST | A request was made on an invalid device object. For example, this error is returned if a file system object is passed as the **RxDeviceObject** parameter. This status value indicates failure. |
| STATUS_OBJECT_NAME_INVALID | An invalid request was made to create a named pipe or a mailslot (the **MajorFunction** member of the **Irp** was IRP_MJ_CREATE_MAILSLOT or IRP_MJ_CREATE_NAMED_PIPE). This status value indicates failure. |
| STATUS_PENDING | An asynchronous request was made and the status of the request is pending. |
| STATUS_SUCCESS | The **RxFsdDispatch** routine call was successful. |

## Remarks

**RxFsdDispatch** is called by RDBSS to process an I/O request packet (IRP). These IRPs are normally received by RDBSS in response to a user-mode application requesting operations on a file. It is also possible for another kernel driver to issue such an IRP.

A pointer to **RxFsdDispatch** routine is copied over the driver dispatch table for a network mini-redirector driver when the **RxDriverEntry** routine is called to initialize RDBSS.

Internally, RDBSS maintains two dispatch vectors:

* A common dispatch vector for most operations.

* A private dispatch vector for file device FCB operations.

If the IRP is an IRP_MJ_CREATE request, then **RxFsdDispatch** will use a common dispatch vector. If the IRP is for an operation on an FCB of a file object, **RxFsdDispatch** will check if a private dispatch vector should be used. Otherwise a common dispatch vector will be used to process the IRP.

**RxFsdDispatch** calls internal routines to process the standard IRPs most of which result in a call to one of the callback routines implemented by the network mini-redirector driver.

A few IRPs are treated as special and handled internally by RDBSS. For example, the IRP_MJ_SYSTEM_CONTROL is used internally if WMI is enabled. IRP_MJ_CREATE_MAILSLOT or IRP_MJ_CREATE_NAMED_PIPE requests are treated specially and rejected (a STATUS_OBJECT_NAME_INVALID error is returned).

## See also

[**RxDriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdriverentry)