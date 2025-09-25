# _NDIS_CO_CLIENT_OPTIONAL_HANDLERS structure

## Description

The NDIS_CO_CLIENT_OPTIONAL_HANDLERS structure specifies entry points for CoNDIS client
*ProtocolXxx* functions for the protocol driver that passes this structure to the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
protocol driver CoNDIS characteristics structure (NDIS_CO_CLIENT_OPTIONAL_HANDLERS). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_CO_CLIENT_OPTIONAL_HANDLERS, the
**Revision** member to NDIS_CO_CLIENT_OPTIONAL_HANDLERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_CO_CLIENT_OPTIONAL_HANDLERS_REVISION_1.

### `Reserved`

Reserved for NDIS.

### `ClCreateVcHandler`

The entry point of the caller's
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `ClDeleteVcHandler`

The entry point of the caller's
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function.

### `ClOidRequestHandler`

The entry point of the caller's
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function.

### `ClOidRequestCompleteHandler`

The entry point of the caller's
[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function.

### `ClOpenAfCompleteHandlerEx`

The entry point of the caller's
[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex) function.

### `ClCloseAfCompleteHandler`

The entry point of the caller's
[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete) function.

### `ClRegisterSapCompleteHandler`

The entry point of the caller's
[ProtocolClRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_register_sap_complete) function. A client uses this function to accept incoming calls from
remote machines.

### `ClDeregisterSapCompleteHandler`

The entry point of the caller's
[ProtocolClDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_deregister_sap_complete) function.

### `ClMakeCallCompleteHandler`

The entry point of the caller's
[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete) function. A client uses this function to make outgoing calls to remote
machines.

### `ClModifyCallQoSCompleteHandler`

The entry point of the caller's
[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete) function. A client uses this function to dynamically make changes
in the quality of service (QoS) on an established virtual connection (VC) or to negotiate with the call
manager to establish the QoS when the client sets up an incoming call.

### `ClCloseCallCompleteHandler`

The entry point of the caller's
[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete) function.

### `ClAddPartyCompleteHandler`

The entry point of the caller's
[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete) function. A client uses this function to establish point-to-multipoint
VCs for outgoing calls to remote machines.

### `ClDropPartyCompleteHandler`

The entry point of the caller's
[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete) function.

### `ClIncomingCallHandler`

The entry point of the caller's
[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function. A client uses this function to accept incoming calls from remote
machines.

### `ClIncomingCallQoSChangeHandler`

The entry point of the caller's
[ProtocolClIncomingCallQoSChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call_qos_change) function. A client uses this function to accept incoming calls
from remote machines on which the sending client can dynamically change the QoS.

### `ClIncomingCloseCallHandler`

The entry point of the caller's
[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call) function.

### `ClIncomingDropPartyHandler`

The entry point of the caller's
[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party) function.

### `ClCallConnectedHandler`

The entry point of the caller's
[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected) function. A client uses this function to accept incoming calls from remote
machines.

### `ClNotifyCloseAfHandler`

The entry point of the caller's
[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af) function.

## Remarks

To specify entry points as a CoNDIS client, a protocol driver initializes an
NDIS_CO_CLIENT_OPTIONAL_HANDLERS structure and passes it to the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

The client calls
**NdisSetOptionalHandlers** from the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. The
client must set every
**Cl***Xxx* member in the NDIS_CO_CLIENT_OPTIONAL_HANDLERS structure to a caller-supplied
*ProtocolXxx* function, even if the call manager does not support incoming calls, outgoing calls, or
point-to-multipoint connections. For whatever subset of connection-oriented functionality that a client
does not support, its placeholder
*ProtocolXxx* functions should return NDIS_STATUS_NOT_SUPPORTED.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete)

[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected)

[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete)

[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete)

[ProtocolClDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_deregister_sap_complete)

[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolClIncomingCallQoSChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call_qos_change)

[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call)

[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party)

[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete)

[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete)

[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex)

[ProtocolClRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_register_sap_complete)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)

[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request)

[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete)

[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)