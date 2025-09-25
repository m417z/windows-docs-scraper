# PROTOCOL_CO_OID_REQUEST_COMPLETE callback function

## Description

The
*ProtocolCoOidRequestComplete* function completes the processing of an asynchronous
CoNDIS OID request.

**Note** You must declare the function by using the **PROTOCOL_CO_OID_REQUEST_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolAfContext` [in]

A handle that identifies an address family (AF) context area. If the driver is a client, it
supplied this handle when it called the
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) function to connect itself to the call manager. If the driver is a call
manager or miniport call manager (MCM), it supplied this handle from its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

### `ProtocolVcContext` [in]

A handle that identifies the active virtual connection (VC) that the driver requested or set
information for, if the request was VC-specific. Otherwise, this parameter is **NULL**.

### `ProtocolPartyContext` [in]

A handle that identifies the party on a multipoint VC that the driver requested or set information
for, if the request is party-specific. Otherwise, this parameter is **NULL**.

### `OidRequest` [in, out]

A pointer to the driver-supplied
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that was
previously passed to the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) or
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) function.

### `Status` [in]

The final status of the request. The target driver or NDIS determines this final status. This
parameter determines what
*ProtocolCoOidRequestComplete* does with the information at
*OidRequest*.

## Remarks

NDIS calls the
*ProtocolCoOidRequestComplete* function to complete the processing of CoNDIS
client, call manager, or MCM OID request for which the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) function or
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) function returned
NDIS_STATUS_PENDING.

To register
*ProtocolCoOidRequestComplete* as a client, a driver initializes an
[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers) structure and passes it at the
*OptionalHandlers* parameter of the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.
To register
*ProtocolCoOidRequestComplete* as a call manager, a driver initializes an
[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers) structure and passes it at the
*OptionalHandlers* parameter of
**NdisSetOptionalHandlers**.

The target driver is the driver that serviced the OID information request. A target driver's call to
the
[NdisMCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcooidrequestcomplete),
[NdisCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequestcomplete), or
[NdisMCmOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequestcomplete) function caused NDIS to call the
*ProtocolCoOidRequestComplete* function. NDIS forwards the value of the
*Status* parameter that was passed to these functions as the input
*Status* parameter to
*ProtocolCoOidRequestComplete*.

*ProtocolCoOidRequestComplete* uses the input value of
*Status* as follows:

* If
  *Status* is NDIS_STATUS_SUCCESS, the
  **BytesRead** or
  **BytesWritten** member of the
  [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that the
  *OidRequest* parameter points to specifies how much information was transferred
  from the buffer in the
  **InformationBuffer** member of NDIS_OID_REQUEST to the target driver or how much information was
  returned at
  **InformationBuffer**, respectively.

  If the driver made a query request,
  *ProtocolCoOidRequestComplete* can use the data that is returned in
  **InformationBuffer** as appropriate for the value that is specified in the
  **Oid** member of NDIS_OID_REQUEST.
* If
  *Status* is NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT, the
  **BytesNeeded** member of the NDIS_OID_REQUEST structure that
  *OidRequest* points to specifies the OID-specific value of the
  **InformationBufferLength** member of NDIS_OID_REQUEST that is required to carry out the requested
  operation.

  In these circumstances,
  *ProtocolCoOidRequestComplete* can allocate sufficient buffer space for the
  request, set up another
  [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure with the
  required value for
  **InformationBufferLength**, and retry the OID request.
* If
  *Status* is an NDIS_STATUS_
  *XXX* value that is an unrecoverable error,
  *ProtocolCoOidRequestComplete* should release the memory for the
  NDIS_OID_REQUEST structure.
  *ProtocolCoOidRequestComplete* should also determine whether the driver should
  close the binding or adjust its binding-specific state information to handle continued network I/O
  operations on the binding.

For more information about system-defined OIDs, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

*ProtocolCoOidRequestComplete* can be called before the driver has had time to
inspect the status code that
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) or
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) returns.

NDIS calls
*ProtocolCoOidRequestComplete* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *ProtocolCoOidRequestComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCoOidRequestComplete* function that is named "MyCoOidRequestComplete", use the **PROTOCOL_CO_OID_REQUEST_COMPLETE** type as shown in this code example:

```
PROTOCOL_CO_OID_REQUEST_COMPLETE MyCoOidRequestComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCoOidRequestComplete(
    NDIS_HANDLE  ProtocolAfContext,
    NDIS_HANDLE  ProtocolVcContext,
    NDIS_HANDLE  ProtocolPartyContext,
    PNDIS_OID_REQUEST  OidRequest,
    NDIS_STATUS  Status
    )
  {...}
```

The **PROTOCOL_CO_OID_REQUEST_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CO_OID_REQUEST_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)

[NdisCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequestcomplete)

[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest)

[NdisMCmOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequestcomplete)

[NdisMCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcooidrequestcomplete)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)