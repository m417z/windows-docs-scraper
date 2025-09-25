# NdisMCmOidRequest function

## Description

The
**NdisMCmOidRequest** function sends an OID request from a miniport call manager (MCM) driver to a CoNDIS
client.

## Parameters

### `NdisAfHandle` [in]

A handle that identifies the address family (AF), and implicitly the client, that the OID request
is directed to. The MCM driver originally obtained this handle as an input parameter to its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

### `NdisVcHandle` [in, optional]

A handle that identifies the virtual connection (VC) that the caller is requesting or setting
information for, if the request is VC-specific. Otherwise, if this request is not VC-specific, this
parameter is **NULL**. For any VC-specific request, the caller originally obtained this handle either when
it created the VC with the
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc) function, or as an input
parameter to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `NdisPartyHandle` [in, optional]

A handle that identifies the party on a multipoint VC that the caller is requesting or setting
information for, if the request is party-specific. Otherwise, if this request is not party-specific,
this parameter is **NULL**. For any party-specific request, the MCM driver originally obtained this handle
as an input parameter to its
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function.

### `NdisOidRequest`

A pointer to a caller-allocated buffer that contains an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure.

## Return value

**NdisMCmOidRequest** returns one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The request operation completed successfully. |
| **NDIS_STATUS_PENDING** | The request is being handled asynchronously, and NDIS will call the caller's [ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function when the request is completed. |
| **NDIS_STATUS_INVALID_OID** | The OID_*XXX* code that was specified in the **Oid** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure at the *OidRequest* parameter is invalid or unsupported by the underlying driver. |
| **NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT** | The value that was specified in the **InformationBufferLength** member of the NDIS_OID_REQUEST structure at *OidRequest* does not match the requirements for the given OID_*XXX* code. If the information buffer is too small, the **BytesNeeded** member of NDIS_OID_REQUEST contains the correct value for **InformationBufferLength**, when **NdisMCmOidRequest** returns. |
| **NDIS_STATUS_INVALID_DATA** | The data that was supplied at **InformationBuffer** in the given [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure was invalid for the given OID_*XXX* code. |
| **NDIS_STATUS_NOT_SUPPORTED or NDIS_STATUS_NOT_RECOGNIZED** | The client driver does not support the requested operation. |
| **NDIS_STATUS_RESOURCES** | The request could not be satisfied because of a resource shortage. Usually, this return value indicates that an attempt to allocate memory was unsuccessful, but it does not necessarily indicate that the same request, if submitted later, will fail for the same reason. |
| **NDIS_STATUS_FAILURE** | This value typically is a nonspecific default that is returned when none of the more specific NDIS_STATUS_*XXX* status codes applies. |
| **NDIS_STATUS_REQUEST_ABORTED** | The target driver stopped processing the request. |

## Remarks

To initiate OID requests to CoNDIS clients, MCM drivers call the
**NdisMCmOidRequest** function. Before an MCM driver calls
**NdisMCmOidRequest**, the driver allocates memory for its request and initializes an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. The MCM sets
the
**Oid** member of the NDIS_OID_REQUEST structure with a CoNDIS OID code.

An MCM driver can call
**NdisMCmOidRequest** to communicate connection-oriented information, such as a change in addresses to
the client that the
*NdisAfHandle* parameter identifies.

After the MCM calls
**NdisMCmOidRequest**, NDIS calls the
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function of
the client.

If the MCM driver's request is VC-specific or party-specific, the MCM driver also passes a non-**NULL**
value at the
*NdisVcHandle* or
*NdisPartyHandle* parameter, respectively.

If
**NdisMCmOidRequest** returns NDIS_STATUS_PENDING, the request is being handled asynchronously and NDIS
will call the MCM's
[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function when the request is completed. If
**NdisMCmOidRequest** returns any other status, the request is complete when
**NdisMCmOidRequest** returns and NDIS does not call
*ProtocolCoOidRequestComplete*.

For more information about the OIDs that are defined to use with
**NdisMCmOidRequest**, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)

[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request)

[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete)