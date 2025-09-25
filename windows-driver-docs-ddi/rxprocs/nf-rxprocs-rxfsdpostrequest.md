# RxFsdPostRequest function

## Description

**RxFsdPostRequest** queues the I/O request packet (IRP) specified by an RX_CONTEXT structure to the worker queue for processing by the file system process (FSP).

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT containing the IRP to be queued to a worker thread.

## Return value

**RxFsdPostRequest** returns the following values:

| Return code | Description |
| --- | --- |
| **STATUS_PENDING** | An asynchronous request was made and has been queued to a worker thread for later processing. The status of the request is pending. |

## Remarks

**RxFsdPostRequest** is normally called by RDBSS to process an asynchronous I/O request packet (IRP). These IRPs are normally received by RDBSS in response to a user-mode application requesting operations on a file. It is also possible for another kernel driver to issue such an IRP.

If the **Flags** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter does not have the RX_CONTEXT_FLAG_NO_PREPOSTING_NEEDED bit set, then **RxFsdPostRequest** will try to lock down any user address space that is required for certain types of requests. The requests that result in this behavior are based on the **MajorFunction** member of RX_CONTEXT structure pointed to by *RxContext* and include the following:

* IRP_MJ_DIRECTORY CONTROL when **RxContext->MinorFunction** *is* IRP_MN_QUERY_DIRECTORY.
* IRP_MJ_QUERY_EA
* IRP_MJ_READ
* IRP_MJ_SET_EA
* IRP_MJ_WRITE

The **MajorFunction** member of *RxContext* will determine which work queue this request will be posted to. An IRP_MJ_DEVICE_CONTROL request where the **Parameters.DeviceIoControl.IoControlCode** member is IOCTL_REDIR_QUERY_PATH will be posted to the delayed work queue. In the case, the **Flags** member of the *RxContext* parameter will have the RX_CONTEXT_FLAG_FSP_DELAYED_OVERFLOW_QUEUE bit set. All other requests are posted to the critical work queue and the Flags member of the *RxContext* parameter will have the RX_CONTEXT_FLAG_FSP_CRITICAL_OVERFLOW_QUEUE bit set.

If the **FileObject** member of the IRP is not **NULL** and the request can be posted immediately for processing (the threshold for the device queue is empty), then this will occur. Otherwise, the request will be posted to an overflow queue on the volume.

All calls to **RxFsdPostRequest** are queued to a worker thread to call the **RxFsdDispatch** routine passing in the *RxContext* parameter.

## See also

[RxFsdDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxfsddispatch)