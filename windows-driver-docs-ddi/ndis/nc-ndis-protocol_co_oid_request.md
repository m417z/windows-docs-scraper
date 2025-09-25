# PROTOCOL_CO_OID_REQUEST callback function

## Description

The
*ProtocolCoOidRequest* function handles OID requests that CoNDIS clients or stand-alone call managers
initiate by calls to the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) function or that a
miniport call manager (MCM) driver initiates by calls to the
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) function.

**Note** You must declare the function by using the **PROTOCOL_CO_OID_REQUEST** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolAfContext` [in]

A handle that identifies an address family (AF) context area. If the driver is a client, it
supplied this handle when it called the
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) function to connect itself to the call manager. If the driver is a call
manager, it supplied this handle from its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

### `ProtocolVcContext` [in]

A handle that identifies the virtual connection (VC) to query or set information on, if the
request is VC-specific. Otherwise, this parameter is **NULL**.

### `ProtocolPartyContext` [in]

A handle that identifies the party on a multipoint VC to query or set information on, if the
request is party-specific. Otherwise, this parameter is **NULL**.

### `OidRequest` [in, out]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that contains
both the buffer and the request packet for the target driver to handle. Depending on the request, the
driver returns requested information in the structure that
*OidRequest* points to.

## Return value

*ProtocolCoOidRequest* can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The client or call manager carried out the requested operation. |
| **NDIS_STATUS_PENDING** | The client, or call manager is handling this request asynchronously, and it will call the [NdisCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequestcomplete) function or the [NdisMCmOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequestcomplete) function when the requested operation is complete. |
| **NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT** | The driver is failing the request because the caller of the [NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) or [NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) function did not supply an adequate value for the **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure for the given request. The driver set the **BytesNeeded** member of NDIS_OID_REQUEST in the buffer at the *OidRequest* parameter to the OID-specific value of the **InformationBufferLength** member that is required to carry out the requested operation. |
| **NDIS_STATUS_*XXX*** | The client or call manager failed the request for some driver-determined reason, such as invalid input data that was specified for a set. |
| **NDIS_STATUS_NOT_SUPPORTED** | The client or call manager failed this request because it did not recognize the OID_GEN_CO_*XXX* code in the **Oid** member in the buffer at *NdisRequest*. |

## Remarks

The
*ProtocolCoOidRequest* function is required for CoNDIS clients, call managers, and MCMs.
*ProtocolCoOidRequest* is similar to the miniport driver's
[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request) function.

CoNDIS clients and call managers send information to each other by specifying a non-**NULL** value in the
*NdisAfHandle* parameter when they call the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) function. Similarly,
MCMs call the
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) with explicit values
for
*NdisAfHandle* to communicate information to clients. Such calls to
**NdisCoOidRequest** or
**NdisMCmOidRequest** cause NDIS to call the
*ProtocolCoOidRequest* function of the targeted client, call manager, or MCM that is associated with
the specified AF handle.

To register
*ProtocolCoOidRequest* as a client, a driver initializes an
[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers) structure and passes it at the
*OptionalHandlers* parameter of the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.
To register
*ProtocolCoOidRequest* as a call manager, a driver initializes an
[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers) structure and passes it at the
*OptionalHandlers* parameter.

If the
*NdisVcHandle* and
*NdisPartyHandle* parameters of
**NdisCoOidRequest** or
**NdisMCmOidRequest** are **NULL**, the request is global in nature. That is, an explicit value for
*NdisVcHandle* or
*NdisPartyHandle* indicates that
*ProtocolCoOidRequest* should satisfy the given request on a per-VC or per-party basis,
respectively.

The buffer at the
*OidRequest* parameter was allocated from nonpaged pool and is, therefore, accessible at raised IRQL.
The caller of
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)(or
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest)) must release this
buffer and the internal buffer at the
**InformationBuffer** member of the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that
*OidRequest* points to.

If
*ProtocolCoOidRequest* returns NDIS_STATUS_PENDING, the driver must subsequently call the
[NdisCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequestcomplete) function, or the
[NdisMCmOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequestcomplete) function for an MCM driver, when the driver completes the request.

### Examples

To define a *ProtocolCoOidRequest* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCoOidRequest* function that is named "MyCoOidRequest", use the **PROTOCOL_CO_OID_REQUEST** type as shown in this code example:

```
PROTOCOL_CO_OID_REQUEST MyCoOidRequest;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCoOidRequest(
    NDIS_HANDLE  ProtocolAfContext,
    NDIS_HANDLE  ProtocolVcContext,
    NDIS_HANDLE  ProtocolPartyContext,
    PNDIS_OID_REQUEST  OidRequest
    )
  {...}
```

The **PROTOCOL_CO_OID_REQUEST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CO_OID_REQUEST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request)

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)

[NdisCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequestcomplete)

[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest)

[NdisMCmOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequestcomplete)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)