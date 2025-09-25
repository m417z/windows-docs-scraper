# NdisCoOidRequest function

## Description

The
**NdisCoOidRequest** function forwards a request to targeted CoNDIS drivers to query or set OID-specified
information of the target driver.

## Parameters

### `NdisBindingHandle` [in]

A handle that the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function returned
that identifies the target adapter for the binding.

### `NdisAfHandle` [in, optional]

A handle that identifies the address family (AF) that is shared among the client, call manager,
and NDIS. This handle was obtained as follows:

* If the caller is a client that is making a request to the call manager, the client originally
  obtained this handle from a successful call to the
  [NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) function.
* If the caller is a stand-alone call manager or miniport call manager (MCM) that is making a request
  to a client, the call manager or MCM originally obtained this handle as an input parameter to its
  [ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

To make a request from either a client or stand-alone call manager to the underlying miniport driver,
this parameter must be **NULL**.

### `NdisVcHandle` [in, optional]

A handle that identifies the virtual connection (VC) the caller is requesting or setting
information for, if the request is VC-specific. Otherwise, if this parameter is **NULL**, the request is not
VC-specific. For any VC-specific request, the caller originally obtained this handle either when it
created the VC with the
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) function, or as an input
parameter to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function. For a
VC-specific request that is directed to the underlying miniport driver, this handle identifies the VC,
while
*NdisAfHandle* and
*NdisPartyHandle* are **NULL**.

### `NdisPartyHandle` [in, optional]

A handle that identifies the party on a multipoint VC the caller is requesting or setting
information for, if the request is party-specific. Otherwise, if this parameter is **NULL**, the request is
not party-specific. For any party-specific request, a client originally obtained this handle from a
successful call to the
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) function or the
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) function or the call
manager obtained this handle as an input parameter to its
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function. If
*NdisAfHandle* is **NULL**,
*NdisPartyHandle* also is **NULL**.

### `OidRequest` [in, out]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies
the operation that is requested with a given OID_*XXX* code to query or to set information.

## Return value

The target driver determines which NDIS_STATUS_*XXX* code
**NdisCoOidRequest** returns, usually one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The request operation completed successfully. |
| **NDIS_STATUS_PENDING** | The request is being handled asynchronously, and NDIS will call the caller's [ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function when the request is completed. |
| **NDIS_STATUS_INVALID_OID** | The OID_*XXX* code that was specified in the **Oid** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure at the *OidRequest* parameter is invalid or unsupported by the underlying driver. |
| **NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT** | The value that was specified in the **InformationBufferLength** member of the NDIS_OID_REQUEST-structured buffer at *OidRequest* does not match the requirements for the given OID_*XXX* code. If the information buffer is too small, the **BytesNeeded** member of NDIS_OID_REQUEST contains the correct value for **InformationBufferLength**, when **NdisCoOidRequest** returns. |
| **NDIS_STATUS_INVALID_DATA** | The data supplied at **InformationBuffer** in the given [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure is invalid for the given OID_*XXX* code. |
| **NDIS_STATUS_NOT_SUPPORTED or NDIS_STATUS_NOT_RECOGNIZED** | The underlying driver does not support the requested operation. |
| **NDIS_STATUS_RESOURCES** | The request could not be satisfied because of a resource shortage. Usually, this return value indicates that an attempt to allocate memory was unsuccessful, but it does not necessarily indicate that the same request, if submitted later, will fail for the same reason. |
| **NDIS_STATUS_NOT_ACCEPTED** | The underlying driver attempted the requested operation, usually a set request, but the operation failed. For example, an attempt to set too many multicast addresses might cause **NdisCoOidRequest** to return this value. |
| **NDIS_STATUS_CLOSING or NDIS_STATUS_CLOSING_INDICATING** | The underlying driver failed the requested operation because a close operation is in progress. |
| **NDIS_STATUS_RESET_IN_PROGRESS** | The underlying miniport driver cannot satisfy the request at this time because it is currently resetting the affected NIC. The caller's [ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex) function was or will be called with NDIS_STATUS_RESET_START to indicate that a reset is in progress. This return value does not necessarily indicate that the same request, if submitted later, will fail for the same reason. |
| **NDIS_STATUS_FAILURE** | This value usually is a nonspecific default value that is returned when none of the more specific NDIS_STATUS_*XXX* caused the underlying driver to fail the request. |
| **NDIS_STATUS_REQUEST_ABORTED** | The miniport driver stopped processing the request. For example, NDIS called an underlying miniport driver's [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) or [MiniportCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_oid_request) function. |

## Remarks

CoNDIS clients and stand-alone call managers can call the
**NdisCoOidRequest** function to send an OID request to query or set OID-specified information in a
target driver. The target driver can be another CoNDIS protocol driver or an underlying driver.

The caller of
**NdisCoOidRequest** must allocate sufficient memory to hold the information buffer that is associated
with the specified OID. The caller must also allocate and set up the buffer at
*OidRequest* before it calls
**NdisCoOidRequest**. Both buffers must be allocated from nonpaged pool because the target driver can
run at raised IRQL while it processes the request.

Some errors that
**NdisCoOidRequest** returns are recoverable, including the following:

* NDIS_STATUS_INVALID_OID
* NDIS_STATUS_INVALID_LENGTH
* NDIS_STATUS_BUFFER_TOO_SHORT
* NDIS_STATUS_INVALID_DATA
* NDIS_STATUS_RESOURCES
* NDIS_STATUS_RESET_IN_PROGRESS

That is, a driver can modify the packet at
*OidRequest* appropriately to correct the OID_*XXX* code or the size or contents of the buffer at
**InformationBuffer** and resubmit the request packet to
**NdisCoOidRequest**. The same packet might be satisfied when the driver resubmits it to
**NdisCoOidRequest** if the original call indicated a reset in progress or that a resource shortage,
which might be temporary, prevented that request from being carried out.

Depending on the value of the
*NdisAfHandle* parameter, clients and stand-alone call managers call
**NdisCoOidRequest** to communicate with each other or with the underlying connection-oriented miniport
driver.

If a driver passes **NULL** for
*NdisVcHandle*, the request is global in nature, whether the request is directed to the client, call
manager, or miniport driver. For example, if the caller supplies a non-**NULL** value for
*NdisVcHandle*, an
[OID_GEN_CO_RCV_CRC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-co-rcv-crc-error) OID request
to an underlying connection-oriented miniport driver returns the number of cyclic redundancy check (CRC)
errors that were encountered for a particular VC. For the same request with **NULL** for
*NdisVcHandle*, the underlying miniport driver returns the total number of CRC errors that were
encountered for all of the VCs.

Clients and stand-alone call managers should call the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function for all of the OIDs
that are not connection-oriented, such as those that are returned in an
[OID_GEN_SUPPORTED_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-list) query, which is
commonly issued during initialization after the protocol driver has bound itself to the underlying NIC
driver.

If
**NdisCoOidRequest** returns NDIS_STATUS_PENDING, the request is being handled asynchronously and NDIS
will call the driver's
[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function when the request is completed. If
**NdisCoOidRequest** returns any other status, the request is complete when
**NdisCoOidRequest** returns, and NDIS does not call
*ProtocolCoOidRequestComplete*.

For more information about the sets of OIDs that are defined to use with
**NdisCoOidRequest** and
**NdisOidRequest**, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

Only clients and stand-alone call managers, which are protocol drivers, can call
**NdisCoOidRequest**. MCMs call the
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) function to
communicate with their clients.

## See also

[MiniportCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_oid_request)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[OID_GEN_CO_RCV_CRC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-co-rcv-crc-error)

[OID_GEN_SUPPORTED_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-list)

[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete)

[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex)