# _NDIS_PROTOCOL_CO_CHARACTERISTICS structure

## Description

The NDIS_PROTOCOL_CO_CHARACTERISTICS structure specifies CoNDIS entry points for CoNDIS protocol
drivers.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
protocol driver CoNDIS characteristics structure (NDIS_PROTOCOL_CO_CHARACTERISTICS). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_CO_PROTOCOL_CHARACTERISTICS, the
**Revision** member to NDIS_PROTOCOL_CO_CHARACTERISTICS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_PROTOCOL_CO_CHARACTERISTICS_REVISION_1.

### `Flags`

Reserved for NDIS.

### `CoStatusHandlerEx`

The entry point of the driver's
[ProtocolCoStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_status_ex) function.

### `CoAfRegisterNotifyHandler`

The entry point of the driver's
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) function.

### `CoReceiveNetBufferListsHandler`

The entry point of the driver's
[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists) function.

### `CoSendNetBufferListsCompleteHandler`

The entry point of the driver's
[ProtocolCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_send_net_buffer_lists_complete) function.

## Remarks

To specify entry points for CoNDIS, a protocol driver initializes an NDIS_PROTOCOL_CO_CHARACTERISTICS
structure and passes it to the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

The protocol driver calls
**NdisSetOptionalHandlers** from the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)

[ProtocolCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_send_net_buffer_lists_complete)

[ProtocolCoStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_status_ex)

[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)