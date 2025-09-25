# NET_ADAPTER_PAUSE_FUNCTION_TYPE enumeration

## Description

The **NET_ADAPTER_PAUSE_FUNCTION_TYPE** enumeration specifies what IEEE 802.3 pause frames a net adapter supports.

## Constants

### `NetAdapterPauseFunctionTypeUnsupported:0`

Indicates that the adapter or link partner does not support pause frames.

### `NetAdapterPauseFunctionTypeSendOnly:1`

Indicates that the adapter and link partner only support sending pause frames from the adapter to the link partner.

### `NetAdapterPauseFunctionTypeReceiveOnly:2`

Indicates that the adapter and link partner only support sending pause frames from the link partner to the adapter.

### `NetAdapterPauseFunctionTypeSendAndReceive:3`

Indicates that the adapter and link partner support sending and receiving pause frames in both transint and receive directions.

### `NetAdapterPauseFunctionTypeUnknown:4`

Indicates that pause frame negotiation is in progress. The pause frame support that the link partner provides is unknown.

## Remarks

This enumeration is a member of the [**NET_ADAPTER_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure.

## See also

[**NET_ADAPTER_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state)