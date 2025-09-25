# WdfIoQueueFindRequest function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueFindRequest** method locates the next request in an I/O queue, or the next request that matches specified criteria, but does not grant [ownership](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) of the request to the driver.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `FoundRequest` [in, optional]

A request object handle that the driver received from a previous call to **WdfIoQueueFindRequest**. This parameter is optional and can be **NULL**.

### `FileObject` [in, optional]

A handle to a framework file object. This parameter is optional and can be **NULL**.

### `Parameters` [in, out]

A pointer to a driver-allocated [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure that receives parameters that are associated with the found request. This parameter is optional and can be **NULL**.

### `OutRequest` [out]

A pointer to a location that receives a handle to the found request. If no match is found, the location receives **NULL**.

## Return value

**WdfIoQueueFindRequest** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The driver supplies an invalid handle. |
| **STATUS_NOT_FOUND** | The request that is identified by the *FoundRequest* parameter cannot be found in the I/O queue. |
| **STATUS_NO_MORE_ENTRIES** | The framework reached the end of the I/O queue without finding a request that matches the search criteria. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfIoQueueFindRequest** method searches a specified I/O queue and attempts to find an I/O request.

Your driver can call **WdfIoQueueFindRequest** only if the driver is using the manual [dispatching method](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests) for the specified I/O queue.

If *FileObject* is not **NULL**, **WdfIoQueueFindRequest** only examines requests that are associated with the specified file object handle.

If *FoundRequest* is **NULL**, this method locates the first request in the I/O queue that matches the *FileObject* value. If *FoundRequest* is not **NULL**, the method begins searching at the request that is identified by *FoundRequest*. To create an iterative loop, specify **NULL** for the first call, and then use the returned handle as the *FoundRequest* parameter for subsequent calls.

If *Parameters* is not **NULL**, this method copies the found request's parameters into the driver-supplied structure.

Every call to **WdfIoQueueFindRequest** that returns STATUS_SUCCESS increments the reference count of the request object whose handle is returned in *OutRequest*. Therefore, your driver must call [WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference) after you have finished using the handle.

Calling **WdfIoQueueFindRequest** does *not* grant the driver [ownership](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) of any requests. If you want your driver to obtain ownership of a request so that it can process the request, the driver must call [WdfIoQueueRetrieveFoundRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest). In fact, the driver can do only the following with the handle that it receives for the *OutRequest* parameter:

* Use it as the *FoundRequest* parameter in a subsequent call to **WdfIoQueueFindRequest**.
* Use it as the *FoundRequest* parameter in a subsequent call to [WdfIoQueueRetrieveFoundRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest).
* Use it as the input parameter in a subsequent call to [WdfObjectGetTypedContext](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgettypedcontext) or a driver-defined method for accessing the object's [context space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).
* Use it as the input parameter to [WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference).

If a call to **WdfIoQueueFindRequest** returns STATUS_NOT_FOUND, a request that was previously in the queue has been removed. The request might have been canceled. A call to [WdfIoQueueRetrieveFoundRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest) can also return STATUS_NOT_FOUND.

For more information about the **WdfIoQueueFindRequest** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

**Example 1**

The following code example is from the [PCIDRV](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example searches an I/O queue for a request that contains a specified I/O function code. If a matching request is found, the example calls [WdfIoQueueRetrieveFoundRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest).

```cpp
NTSTATUS
NICGetIoctlRequest(
    IN WDFQUEUE Queue,
    IN ULONG FunctionCode,
    OUT WDFREQUEST*  Request
    )
{
    NTSTATUS  status = STATUS_UNSUCCESSFUL;
    WDF_REQUEST_PARAMETERS  params;
    WDFREQUEST  tagRequest;
    WDFREQUEST  prevTagRequest;

    WDF_REQUEST_PARAMETERS_INIT(&params);

    *Request = NULL;
    prevTagRequest = tagRequest = NULL;

    do {
        WDF_REQUEST_PARAMETERS_INIT(&params);
        status = WdfIoQueueFindRequest(
                                       Queue,
                                       prevTagRequest,
                                       NULL,
                                       &params,
                                       &tagRequest
                                       );
        if (prevTagRequest) {
            WdfObjectDereference(prevTagRequest);
        }
        if (status == STATUS_NO_MORE_ENTRIES) {
            status = STATUS_UNSUCCESSFUL;
            break;
        }
        if (status == STATUS_NOT_FOUND) {
            //
            // The prevTagRequest request has disappeared from the
            // queue. There might be other requests that match
            // the criteria, so restart the search.
            //
            prevTagRequest = tagRequest = NULL;
            continue;
        }
        if (!NT_SUCCESS(status)) {
            status = STATUS_UNSUCCESSFUL;
            break;
        }
        if (FunctionCode == params.Parameters.DeviceIoControl.IoControlCode){
            //
            // Found a match. Retrieve the request from the queue.
            //
            status = WdfIoQueueRetrieveFoundRequest(
                                                    Queue,
                                                    tagRequest,
                                                    Request
                                                    );
            WdfObjectDereference(tagRequest);
            if (status == STATUS_NOT_FOUND) {
                //
                // The tagRequest request has disappeared from the
                // queue. There might be other requests that match
                // the criteria, so restart the search.
                //
                prevTagRequest = tagRequest = NULL;
                continue;
            }
            if (!NT_SUCCESS(status)) {
                status = STATUS_UNSUCCESSFUL;
                break;
            }
            //
            //  Found a request.
            //
            ASSERT(*Request == tagRequest);
            status =  STATUS_SUCCESS;
            break;
        } else {
            //
            // This request is not the correct one. Drop the reference
            // on the tagRequest after the driver obtains the next request.
            //
            prevTagRequest = tagRequest;
            continue;
        }
    } while (TRUE);
    return status;

}
```
**Example 2**

The following code example shows how you can create a general-purpose search routine that calls a search-specific subroutine. If your driver must search one or more queues for multiple types of information, you can provide multiple search-specific subroutines. Each time that your driver calls the general-purpose search routine, it specifies the address of one of your search-specific subroutines.

```cpp
//
// Type declaration for the driver's search-specific subroutines.
//
typedef BOOLEAN (*PFN_CALLBACK_COMPARE)(WDFREQUEST, ULONG);

//
// General-purpose search routine. One of the routine's
// parameters is the address of a search-specific
// subroutine. The search routine calls back to the
// subroutine.
//
WDFREQUEST
FindRequestWithMatchingData(
    __in WDFQUEUE Queue,
    __in PFN_CALLBACK_COMPARE CallbackCompare,
    __in ULONG Data
    )
{
    WDFREQUEST  prevTagRequest = NULL;
    WDFREQUEST  tagRequest = NULL;
    WDFREQUEST  outRequest = NULL;
    NTSTATUS  status = STATUS_INVALID_DEVICE_REQUEST;

    PAGED_CODE();

    do {
        status = WdfIoQueueFindRequest(Queue,
                                       prevTagRequest,
                                       NULL,
                                       NULL,
                                       &tagRequest);
        if (prevTagRequest) {
            //
            // WdfIoQueueFindRequest incremented the
            // reference count of the prevTagRequest object,
            // so we decrement the count here.
            //
            WdfObjectDereference(prevTagRequest);
        }
        if (status == STATUS_NO_MORE_ENTRIES) {
            KdPrint(("WdfIoQueueFindRequest returned status 0x%x\n", status));
            break;
        }
        if (status == STATUS_NOT_FOUND) {
            //
            // The prevTagRequest object is no longer
            // in the queue.
            //
            prevTagRequest = tagRequest = NULL;
            continue;
        }
        if ( !NT_SUCCESS(status)) {
            KdPrint(("WdfIoQueueFindRequest failed 0x%x\n", status));
            break;
        }

        //
        // We have a handle to the next request that is
        // in the queue. Now we call the subroutine
        // that determines if this request matches our
        // search criteria.
        //
        if (CallbackCompare(tagRequest, Data)) {
            //
            // We found a match. Get the request handle.
            //
            status = WdfIoQueueRetrieveFoundRequest(Queue,
                                                    tagRequest,
                                                    &outRequest);
            //
            // WdfIoQueueRetrieveFoundRequest incremented the
            // reference count of the TagRequest object,
            // so we decrement the count here.
            //
            WdfObjectDereference(tagRequest);

            if (status == STATUS_NOT_FOUND) {
                //
                // The TagRequest object is no longer
                // in the queue. But other requests might
                // match our criteria, so we restart the search.
                //
                prevTagRequest = tagRequest = NULL;
                continue;
            }

            if (!NT_SUCCESS(status)) {
                KdPrint(("WdfIoQueueRetrieveFoundRequest failed 0x%x\n",
                          status));
            }

            //
            // We found the request we were looking for.
            //
            break;

        } else {
            //
            // The request did not match our criteria.
            // Get another request.
            //
            prevTagRequest = tagRequest;
            continue;
        }
    } while(TRUE);
    return outRequest;
 }

/
// An example of a driver's search-specific subroutine.
// Your driver can have multiple subroutines to handle
// multiple types of searches.
//
BOOLEAN
CallbackCheckForInfo1(
    __in WDFREQUEST Request,
    __in ULONG DataToBeMatched
    )
{
    PREQUEST_CONTEXT reqContext;

    PAGED_CODE();

    //
    // Retrieve information that the driver has stored
    // in the request object's context space.
    //
    reqContext = GetRequestContext(Request);
    if (reqContext->ContextInfo1 == DataToBeMatched) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

//
// This code shows a call to the FindRequestWithMatchingData routine.
//
WDFREQUEST  matchedRequest = NULL;
...
matchedRequest = FindRequestWithMatchingData(readQueue,
                                             CallbackCheckForInfo1,
                                             INFO_VALUE);
if (matchedRequest != NULL) {
    //
    // Found a request with a context value of INFO_VALIUE.
    //
...
}
...
```

## See also

[WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters)

[WdfIoQueueRetrieveFoundRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest)

[WdfIoQueueStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestop)

[WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference)