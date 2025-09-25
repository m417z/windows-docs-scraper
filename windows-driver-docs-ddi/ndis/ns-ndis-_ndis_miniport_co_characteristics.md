# _NDIS_MINIPORT_CO_CHARACTERISTICS structure

## Description

The NDIS_MINIPORT_CO_CHARACTERISTICS structure specifies the CoNDIS entry points for a CoNDIS
miniport driver.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
miniport driver CoNDIS characteristics structure (NDIS_MINIPORT_CO_CHARACTERISTICS). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_CO_MINIPORT_CHARACTERISTICS, the
**Revision** member to NDIS_MINIPORT_CO_CHARACTERISTICS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MINIPORT_CO_CHARACTERISTICS_REVISION_1.

### `Flags`

Reserved for NDIS.

### `CoCreateVcHandler`

The entry point of the driver's
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function. If
this entry point is for an integrated miniport call manager (MCM) driver, this member should be **NULL**,
because NDIS calls such a driver's
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function
instead. For more information about
*ProtocolCoCreateVc* in an MCM, see
[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers).

### `CoDeleteVcHandler`

The entry point of the driver's
[MiniportCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_delete_vc) function. If
this entry point is for an integrated miniport call manager (MCM) driver, this member should be **NULL**,
because NDIS calls such a driver's
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function
instead. For more information about
*ProtocolCoDeleteVc* in an MCM, see
[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers).

### `CoActivateVcHandler`

The entry point of the driver's
[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc) function.

### `CoDeactivateVcHandler`

The entry point of the driver's
[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc) function.

### `CoSendNetBufferListsHandler`

The entry point of the driver's
[MiniportCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_send_net_buffer_lists) function.

### `CoOidRequestHandler`

The entry point of the driver's
[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request) function.

## Remarks

To specify entry points for CoNDIS, a miniport driver initializes an NDIS_MINIPORT_CO_CHARACTERISTICS
structure and passes it to the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

The miniport driver calls
**NdisSetOptionalHandlers** from the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function.

## See also

[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc)

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc)

[MiniportCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_delete_vc)

[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request)

[MiniportCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_send_net_buffer_lists)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)