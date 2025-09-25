# FILTER_CANCEL_OID_REQUEST callback function

## Description

NDIS calls a filter driver's
*FilterCancelOidRequest* function to cancel an OID request.

**Note** You must declare the function by using the **FILTER_CANCEL_OID_REQUEST** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module that is the target of this request. The filter
driver created and initialized this context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `RequestId` [in]

A cancellation identifier for the request. This identifier specifies the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structures that are being
canceled.

## Remarks

*FilterCancelOidRequest* is an optional function. If a filter driver does not use OID requests, it
can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

When NDIS calls
*FilterCancelOidRequest*, the filter driver should attempt to call
[NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete) function
as soon as possible.

The request parameters are defined in the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure at
*OidRequest* .

If a filter driver does not queue OID requests, the driver is not required to provide a
*FilterCancelOidRequest* function. If the filter driver does not specify a
*FilterCancelOidRequest* entry point, NDIS calls the cancel OID request function of the underlying
driver.

NDIS calls the
*FilterCancelOidRequest* function either when the originator of the request cancels the request or
when the time-out specified at the
**Timeout** member expires.

If the request processing is still not complete in a filter driver, the driver calls the
**NdisFOidRequestComplete** function with the status set to NDIS_STATUS_REQUEST_ABORTED.

If the filter driver forwarded the request to an underlying driver and the processing is still not
complete, the filter driver calls the
[NdisFCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfcanceloidrequest) function with
the
*OidRequest* parameter set to the value that it sent to the underlying driver.

NDIS calls
*FilterCancelOidRequest* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterCancelOidRequest* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterCancelOidRequest* function that is named "MyCancelOidRequest", use the **FILTER_CANCEL_OID_REQUEST** type as shown in this code example:

```
FILTER_CANCEL_OID_REQUEST MyCancelOidRequest;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCancelOidRequest(
    NDIS_HANDLE  FilterModuleContext,
    PVOID  RequestId
    )
  {...}
```

The **FILTER_CANCEL_OID_REQUEST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_CANCEL_OID_REQUEST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisFCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfcanceloidrequest)

[NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)