# FILTER_DIRECT_OID_REQUEST callback function

## Description

NDIS calls a filter driver's
*FilterDirectOidRequest* function to process a direct OID request that is
associated with the specified filter module.

**Note** You must declare the function by using the **FILTER_DIRECT_OID_REQUEST** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module that is the target of this request. The filter
driver created and initialized this context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies
the operation requested, including the OID_
*Xx* code. The structure can specify either a query request or a set
request

## Return value

*FilterDirectOidRequest* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *FilterDirectOidRequest* successfully completed the filter driver's query or set operation for this filter module. |
| **NDIS_STATUS_PENDING** | The filter driver will complete the request asynchronously. After the driver completes the request, it must call the [NdisFDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequestcomplete) function to inform NDIS that the request is complete. |
| **NDIS_STATUS_INVALID_OID** | The request that *OidRequest* specified was invalid or not recognized. |
| **NDIS_STATUS_NOT_SUPPORTED** | *FilterDirectOidRequest* does not support the OID; the OID is optional. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The buffer that *OidRequest* supplied was too small to hold the requested data. |
| **NDIS_STATUS_INVALID_LENGTH** | For a query operation, the **InformationBufferLength** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure does not match the length that the given OID requires. *FilterDirectOidRequest* returned the required buffer size, in bytes, in the **BytesNeeded** member of the NDIS_OID_REQUEST structure. |
| **NDIS_STATUS_INVALID_DATA** | For a set operation, the data that was supplied in the **InformationBuffer** member of the NDIS_OID_REQUEST structure was invalid for the given OID. |
| **NDIS_STATUS_NOT_ACCEPTED** | *FilterDirectOidRequest* attempted to gather the requested information but was unsuccessful. |
| **NDIS_STATUS_RESOURCES** | *FilterDirectOidRequest* failed because of insufficient resources. |
| **NDIS_STATUS_FAILURE** | *N* one of the preceding return values applies. The filter driver should call the [NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry) function with parameters that specify the reason for the failure. |

## Remarks

*FilterDirectOidRequest* is an optional function. If a filter driver does not use
direct OID requests, it can set the entry point for this function to **NULL** when it calls the
**NdisFRegisterFilterDriver** function. If a filter driver defines a
[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete) function, it must provide the
*FilterDirectOidRequest* function.

NDIS calls the filter driver's
*FilterDirectOidRequest* function to process direct OID requests that are
originated by overlying drivers. Filter drivers can forward such requests to underlying drivers by
calling the
[NdisFDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequest) function. As
an option, a filter driver can also complete a request immediately without forwarding the request.

Before the driver calls
**NdisFDirectOidRequest**, the driver must allocate an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure and transfer the
request information to the new structure by calling the
[NdisAllocateCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatecloneoidrequest) function.

To complete a request synchronously, the filter driver returns NDIS_STATUS_SUCCESS or a failure
status. If the driver returns NDIS_STATUS_PENDING, it must call the
[NdisFDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequestcomplete) function to inform NDIS that the request is complete.

For a query operation,
*FilterDirectOidRequest* returns the requested information in the
**InformationBuffer** member and sets the variable in the
**BytesWritten** member of the NDIS_OID_REQUEST structure to the amount of information it returned. The
underlying drivers do this if the filter driver passed the request on with
**NdisFDirectOidRequest**.

For a set operation
*, FilterDirectOidRequest* can use the data in the
**InformationBuffer** member of the NDIS_OID_REQUEST structure to set the information that the given
OID requires. In this case,
*FilterDirectOidRequest* sets the variable at
**BytesRead** to the amount of the supplied data that it used. The underlying drivers set
**BytesRead** in this way if the filter driver passed the request on with
**NdisFDirectOidRequest**.

NDIS does not serialize requests that it sends to
*FilterDirectOidRequest* with other OID requests. The filter driver must be able
to handle multiple calls to
*FilterDirectOidRequest* when other requests that are sent to
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) or
*FilterDirectOidRequest* are outstanding.

NDIS calls
*FilterDirectOidRequest* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterDirectOidRequest* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterDirectOidRequest* function that is named "MyDirectOidRequest", use the **FILTER_DIRECT_OID_REQUEST** type as shown in this code example:

```
FILTER_DIRECT_OID_REQUEST MyDirectOidRequest;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyDirectOidRequest(
    NDIS_HANDLE  FilterModuleContext,
    PNDIS_OID_REQUEST  OidRequest
    )
  {...}
```

The **FILTER_DIRECT_OID_REQUEST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_DIRECT_OID_REQUEST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisAllocateCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatecloneoidrequest)

[NdisFDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequest)

[NdisFDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequestcomplete)

[NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry)