# FILTER_OID_REQUEST callback function

## Description

NDIS calls a filter driver's
*FilterOidRequest* function to process an OID request that is associated with the specified filter
module.

**Note** You must declare the function by using the **FILTER_OID_REQUEST** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module that is the target of this request. The filter
driver created and initialized this context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies
the operation requested including the OID_*XXX* code. The structure can specify either an OID query request or an OID set request. For more information
about OIDs, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

## Return value

*FilterOidRequest* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *FilterOidRequest* successfully completed the filter driver's query or set operation for this filter module. |
| **NDIS_STATUS_PENDING** | Indicates that the filter driver will complete the request asynchronously. After the driver completes the request, it must call the [NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete) function to inform NDIS that the request is complete. |
| **NDIS_STATUS_INVALID_OID** | Indicates that the request, specified at *OidRequest*, is invalid or not recognized. |
| **NDIS_STATUS_NOT_SUPPORTED** | *FilterOidRequest* does not support the OID, the OID is optional. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | Indicates that the buffer, supplied at *OidRequest*, is too small to hold the requested data. |
| **NDIS_STATUS_INVALID_LENGTH** | For a query operation, the **InformationBufferLength** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure does not match the length required by the given OID. *FilterOidRequest* returned the required buffer size, in bytes, in the **BytesNeeded** member of the NDIS_OID_REQUEST structure. |
| **NDIS_STATUS_INVALID_DATA** | For a set operation, the data supplied in the **InformationBuffer** member of the NDIS_OID_REQUEST structure was invalid for the given OID. |
| **NDIS_STATUS_NOT_ACCEPTED** | *FilterOidRequest* attempted to gather the requested information but was unsuccessful. |
| **NDIS_STATUS_RESOURCES** | *FilterOidRequest* failed due to insufficient resources. |
| **NDIS_STATUS_FAILURE** | *FilterOidRequest* returns NDIS_STATUS_FAILURE if none of the preceding values applies. The filter driver should call the [NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry) function with parameters that specify the reason for the failure. |

## Remarks

*FilterOidRequest* is an optional function. If a filter driver does not use OID requests, it can set
the entry point for this function to **NULL** when it calls the
**NdisFRegisterFilterDriver** function. If a filter driver defines a
*FilterOidRequestComplete* function, it must provide the
*FilterOidRequest* function.

NDIS calls the filter driver's
*FilterOidRequest* function to process OID requests that are originated by overlying drivers. Filter
drivers can forward such requests to underlying drivers by calling the
[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest) function.

Before the driver calls
**NdisFOidRequest**, the driver must allocate an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure and transfer the
request information to the new structure by calling
[NdisAllocateCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatecloneoidrequest).
As an option, a filter driver can complete a request immediately without forwarding the request.

To complete a request synchronously, the filter driver returns NDIS_STATUS_SUCCESS or a failure
status. If the driver returns NDIS_STATUS_PENDING, it must call the
[NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete) function
to inform NDIS that the request is complete.

For a query operation,
*FilterOidRequest* returns the requested information in the
**InformationBuffer** member and sets the variable in the
**BytesWritten** member of the NDIS_OID_REQUEST structure to the amount of information it returned. The
underlying drivers do this if the filter driver passed the request on with
**NdisFOidRequest**.

For a set operation, *FilterOidRequest* can use the data in the
**InformationBuffer** member of the NDIS_OID_REQUEST structure to set the information required by the
given OID. In this case,
*FilterOidRequest* sets the variable at
**BytesRead** to the amount of the supplied data that it used. The underlying drivers do this if the
filter driver passed the request on with
**NdisFOidRequest**.

Like miniport drivers, filter drivers can receive only one request at a time. NDIS serializes requests
that it sends to a filter driver. NDIS cannot call
*FilterOidRequest* before a filter driver completes the current request.

NDIS calls
*FilterOidRequest* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterOidRequest* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterOidRequest* function that is named "MyOidRequest", use the **FILTER_OID_REQUEST** type as shown in this code example:

```
FILTER_OID_REQUEST MyOidRequest;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyOidRequest(
    NDIS_HANDLE  FilterModuleContext,
    PNDIS_OID_REQUEST  OidRequest
    )
  {...}
```

The **FILTER_OID_REQUEST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_OID_REQUEST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisAllocateCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatecloneoidrequest)

[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest)

[NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete)

[NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry)