# FILTER_DIRECT_OID_REQUEST_COMPLETE callback function

## Description

NDIS calls the
*FilterDirectOidRequestComplete* function to complete a filter driver direct OID request that queried
or set information in an underlying driver.

**Note** You must declare the function by using the **FILTER_DIRECT_OID_REQUEST_COMPLETE** type. For more
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
[NdisFDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequest) function.

### `Status` [in]

The final status of the request that an underlying driver or NDIS set. This parameter determines
what
*FilterDirectOidRequestComplete* does with the information at
*OidRequest* . For a list of the possible status values, see the return values of
[NdisFDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequest).

## Remarks

*FilterDirectOidRequestComplete* is an optional function. If a filter driver does not use direct OID
requests, it can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function. If a filter driver defines a
[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request) function,
it must provide the
*FilterDirectOidRequestComplete* function.

If the
[NdisFDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequest) function
returns NDIS_STATUS_PENDING, NDIS must call the
*FilterDirectOidRequestComplete* function to complete the OID request.

If a filter driver forwarded a request that it received in the
[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request) function,
*FilterDirectOidRequestComplete* should pass the completion status up the driver stack by calling the
[NdisFDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequestcomplete) function. In this case, the filter driver must call
[NdisFreeCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreecloneoidrequest), to free
the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure, before it calls
**NdisFDirectOidRequestComplete**.

A filter driver should keep track of requests that it originates and ensure that it does not call
**NdisFDirectOidRequestComplete** when NDIS calls
*FilterDirectOidRequestComplete* for such requests.

NDIS calls
*FilterDirectOidRequestComplete* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterDirectOidRequestComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterDirectOidRequestComplete* function that is named "MyDirectOidRequestComplete", use the **FILTER_DIRECT_OID_REQUEST_COMPLETE** type as shown in this code example:

```
FILTER_DIRECT_OID_REQUEST_COMPLETE MyDirectOidRequestComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyDirectOidRequestComplete(
    NDIS_HANDLE  FilterModuleContext,
    PNDIS_OID_REQUEST  OidRequest,
    NDIS_STATUS Status
    )
  {...}
```

The **FILTER_DIRECT_OID_REQUEST_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_DIRECT_OID_REQUEST_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisFDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequest)

[NdisFDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequestcomplete)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFreeCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreecloneoidrequest)