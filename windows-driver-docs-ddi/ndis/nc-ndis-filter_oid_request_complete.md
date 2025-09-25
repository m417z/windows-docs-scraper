# FILTER_OID_REQUEST_COMPLETE callback function

## Description

NDIS calls the
*FilterOidRequestComplete* function to complete a filter driver request that queried or set information
in an underlying driver.

**Note** You must declare the function by using the **FILTER_OID_REQUEST_COMPLETE** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in]

A pointer to the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that the filter
driver previously passed to the
[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest) function.

### `Status` [in]

The final status of the request set by an underlying driver or by NDIS. This parameter determines
what
*FilterOidRequestComplete* does with the information at
*OidRequest* . For a list of the possible status values, see the return values of
[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest).

## Remarks

*FilterOidRequestComplete* is an optional function. If a filter driver does not use OID requests, it
can set the entry point for this function to **NULL** when it calls the
**NdisFRegisterFilterDriver** function. If a filter driver defines a
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function, it must
provide the
*FilterOidRequestComplete* function.

If the
[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest) function returns
NDIS_STATUS_PENDING, NDIS must call the
*FilterOidRequestComplete* function to complete the OID request.

If a filter driver forwarded a request that it received in the
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function,
*FilterOidRequestComplete* should pass the completion status up the driver stack by calling the
[NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete) function.
The filter driver must call
[NdisFreeCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreecloneoidrequest), to free
the NDIS_OID_REQUEST structure, before it calls
**NdisFOidRequestComplete**.

A filter driver should keep track of requests that it originates and ensure that it does not call
**NdisFOidRequestComplete** when NDIS calls
*FilterOidRequestComplete* for such requests.

NDIS calls
*FilterOidRequestComplete* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterOidRequestComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterOidRequestComplete* function that is named "MyOidRequestComplete", use the **FILTER_OID_REQUEST_COMPLETE** type as shown in this code example:

```
FILTER_OID_REQUEST_COMPLETE MyOidRequestComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyOidRequestComplete(
    NDIS_HANDLE  FilterModuleContext,
    PNDIS_OID_REQUEST  OidRequest,
    NDIS_STATUS  Status
    )
  {...}
```

The **FILTER_OID_REQUEST_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_OID_REQUEST_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest)

[NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete)

[NdisFreeCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreecloneoidrequest)