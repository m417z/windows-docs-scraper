# _NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS structure

## Description

The NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS structure specifies CoNDIS call manager
*ProtocolXxx* functions for the driver that passes this structure to the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
call manager CoNDIS characteristics structure (NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS). Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_CO_CALL_MANAGER_OPTIONAL_HANDLERS, the
**Revision** member to NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_CO_CALL_MANAGER_OPTIONAL_HANDLERS_REVISION_1.

### `Reserved`

Reserved for NDIS.

### `CmCreateVcHandler`

The entry point of the caller's
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `CmDeleteVcHandler`

The entry point of the caller's
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function.

### `CmOpenAfHandler`

The entry point of the caller's
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

### `CmCloseAfHandler`

The entry point of the caller's
[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af) function.

### `CmRegisterSapHandler`

The entry point of the caller's
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function.

### `CmDeregisterSapHandler`

The entry point of the caller's
[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap) function.

### `CmMakeCallHandler`

The entry point of the caller's
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function.

### `CmCloseCallHandler`

The entry point of the caller's
[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call) function.

### `CmIncomingCallCompleteHandler`

The entry point of the caller's
[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete) function.

### `CmAddPartyHandler`

The entry point of the caller's
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function.

### `CmDropPartyHandler`

The entry point of the caller's
[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party) function.

### `CmActivateVcCompleteHandler`

The entry point of the caller's
[ProtocolCmActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_activate_vc_complete) function.

### `CmDeactivateVcCompleteHandler`

The entry point of the caller's
[ProtocolCmDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deactivate_vc_complete) function.

### `CmModifyCallQoSHandler`

The entry point of the caller's
[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call) function.

### `CmOidRequestHandler`

The entry point of the caller's
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function.

### `CmOidRequestCompleteHandler`

The entry point of the caller's
[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function.

### `CmNotifyCloseAfCompleteHandler`

The entry point of the caller's
[ProtocolCmNotifyCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_notify_close_af_complete) function.

## Remarks

To specify entry points as a CoNDIS call manager, a protocol driver or miniport call manager (MCM)
initializes an NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS structure and passes it to the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

### Stand-alone Call Manager Constraints

A stand-alone call manager calls
**NdisSetOptionalHandlers** from the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. The
call manager must set every entry point in the NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS structure to a
driver-supplied
*ProtocolXxx* function when it calls
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers), even if
the call manager does not support incoming calls, outgoing calls, or point-to-multipoint connections.
For whatever subset of connection-oriented functionality that such a call manager does not support, its
placeholder
*ProtocolXxx* functions should simply return NDIS_STATUS_NOT_SUPPORTED.

After a stand-alone call manager calls the
[NdisCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregisteraddressfamilyex) function successfully, NDIS ignores any entry point that the call
manager previously specified for the
[ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete) function of the
[NDIS_PROTOCOL_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_driver_characteristics) structure that it passed to the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function.

### MCM Constraints

An MCM calls the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
from the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. The
MCM must set every
**Cm***Xxx* member in the NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS structure to a MCM-supplied
*ProtocolXxx* function even if the MCM does not support incoming calls, outgoing calls, or
point-to-multipoint connections. For whatever subset of connection-oriented functionality that such an
MCM driver does not support, its
*ProtocolXxx* functions should simply return NDIS_STATUS_NOT_SUPPORTED. For example, NDIS never
calls an MCM driver's registered
[ProtocolCmActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_activate_vc_complete) or
[ProtocolCmDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deactivate_vc_complete) function, so these functions can return NDIS_STATUS_NOT_SUPPORTED
but must have entry points in the NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS structure.

An MCM driver must specify entry points for the
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) and
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) functions. If
the MCM previously registered a
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) or
[MiniportCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_delete_vc) function. NDIS
ignores the entry points for these functions, whenever NDIS calls the MCM driver to create or delete a
virtual connection (VC). Therefore, NDIS passes in an
*NdisAfHandle* value for the initial parameter to the MCM-supplied
*ProtocolCoCreateVc* or
*ProtocolCoDeleteVc* function, rather than the
*MiniportAdapterContext* value that it would pass to the
*MiniportCoCreateVc* or
*MiniportCoDeleteVc* function of a non-MCM miniport driver.

An MCM driver cannot set the
**CmOidRequestHandler** member of NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS to its
[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request) function.
The driver must provide a separate entry point for a
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function. An
MCM driver must have a
*ProtocolCoOidRequest* function to handle call manager requests from CoNDIS clients and must have a
[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function.

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[MiniportCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_delete_vc)

[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PROTOCOL_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_driver_characteristics)

[NdisCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregisteraddressfamilyex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolCmActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_activate_vc_complete)

[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party)

[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af)

[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call)

[ProtocolCmDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deactivate_vc_complete)

[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap)

[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party)

[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete)

[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call)

[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)

[ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete)

[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)