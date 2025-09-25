# NdisGetNetBufferListProtocolId function

## Description

The
**NdisGetNetBufferListProtocolId** function retrieves the protocol identifier from the
**NetBufferListInfo** member of a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Return value

**NdisGetNetBufferListProtocolId** returns a protocol identifier as one of the following
values:

| Return code | Description |
| --- | --- |
| **NDIS_PROTOCOL_ID_DEFAULT** | A default protocol driver identifier. |
| **NDIS_PROTOCOL_ID_TCP_IP** | The TCP/IP protocol identifier. |
| **NDIS_PROTOCOL_ID_IPX** | The IPX protocol identifier. |
| **NDIS_PROTOCOL_ID_NBF** | The NetBEUI protocol identifier. |

## Remarks

NDIS drivers can call the
**NdisGetNetBufferListProtocolId** function to determine the type of protocol driver that created a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. For example,
miniport drivers that support TCP chimney offload can verify that a NET_BUFFER_LIST structure comes from
a TCP protocol.

Protocol drivers that create NET_BUFFER_LIST structures should set the protocol identifier by calling the [NdisSetNetBufferListProtocolId](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-ndissetnetbufferlistprotocolid) macro or by associating an identifier with a NET_BUFFER_LIST pool.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisSetNetBufferListProtocolId](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-ndissetnetbufferlistprotocolid)