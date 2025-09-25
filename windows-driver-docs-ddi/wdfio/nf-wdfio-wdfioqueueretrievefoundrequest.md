# WdfIoQueueRetrieveFoundRequest function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueRetrieveFoundRequest** method delivers a specified request to the driver, so that the driver can process the request.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `FoundRequest` [in]

A handle to a framework request object that was obtained by calling [WdfIoQueueFindRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuefindrequest).

### `OutRequest` [out]

A pointer to a location that receives a handle to a framework request object. The driver must use this handle when processing the request.

## Return value

**WdfIoQueueRetrieveFoundRequest** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The driver supplied an invalid handle. |
| **STATUS_NOT_FOUND** | The request that is identified by the *FoundRequest* parameter cannot be found in the I/O queue. |
| **STATUS_NO_MORE_ENTRIES** | The framework reached the end of the I/O queue without finding a request that matches the search criteria. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After calling **WdfIoQueueRetrieveFoundRequest** to obtain an I/O request, the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the request and must [process the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) in some manner.

Before calling **WdfIoQueueRetrieveFoundRequest**, the driver must call [WdfIoQueueFindRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuefindrequest), which retrieves a handle that the driver can use as the *FoundRequest* parameter to **WdfIoQueueRetrieveFoundRequest**.

If your driver was built with KMDF version 1.11 or later, the driver can call **WdfIoQueueRetrieveFoundRequest** without first calling [WdfIoQueueFindRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuefindrequest). In this case, the driver must ensure that the request object is still valid and in the queue.

If a call to **WdfIoQueueRetrieveFoundRequest** returns STATUS_NOT_FOUND, a request that was previously in the queue has been removed. The request might have been canceled.

For more information about the **WdfIoQueueRetrieveFoundRequest** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

For a code example that uses **WdfIoQueueRetrieveFoundRequest**, see [WdfIoQueueFindRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuefindrequest).

## See also

[WdfIoQueueFindRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuefindrequest)

[WdfIoQueueRetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievenextrequest)

[WdfIoQueueRetrieveRequestByFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueretrieverequestbyfileobject)