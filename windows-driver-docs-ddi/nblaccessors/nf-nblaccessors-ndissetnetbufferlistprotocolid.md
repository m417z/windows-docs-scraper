# NdisSetNetBufferListProtocolId macro

## Description

The **NdisSetNetBufferListProtocolId** macro sets the protocol identifier in the **NetBufferListInfo** member of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_ProtocolId`

A protocol identifier, as one of the following values:

NDIS_PROTOCOL_ID_DEFAULT
A default protocol driver identifier.

NDIS_PROTOCOL_ID_TCP_IP
The TCP/IP protocol.

NDIS_PROTOCOL_ID_IPX
The IPX protocol.

NDIS_PROTOCOL_ID_NBF
The NetBEUI protocol.

## Remarks

Drivers that create [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures should set the protocol identifier by calling the **NdisSetNetBufferListProtocolId** macro or by associating an identifier with a **NET_BUFFER_LIST** pool.

To associate a protocol identifier with a **NET_BUFFER_LIST** pool, call the [**NdisAllocateNetBufferListPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function and specify the protocol identifier in the **ProtocolId** member of the [**NET_BUFFER_LIST_POOL_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters) structure.

Miniport, filter, and intermediate drivers set the protocol identifier to zero.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NET_BUFFER_LIST_POOL_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters)

[**NdisAllocateNetBufferListPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[**NdisGetNetBufferListProtocolId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisgetnetbufferlistprotocolid)