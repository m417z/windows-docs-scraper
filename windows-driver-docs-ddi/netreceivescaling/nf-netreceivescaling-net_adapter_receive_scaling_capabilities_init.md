# NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT** function initializes a [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure.

## Parameters

### `Capabilities` [_Out_]

A pointer to the driver-allocated [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure.

### `NumberOfQueues` [_In_]

The number of hardware receive queues. This member must be a power of 2.

### `UnhashedTargetType` [_In_]

A [NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_unhashed_target_type) value that indicates the type of handling for unhashed frames. If this member is set to **NetAdapterReceiveScalingUnhashedTargetTypeUnspecified**, then **UnhashedTarget** is ignored.

### `HashTypes` [_In_]

A [NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_hash_type) value that indicates supported hash function types for calculating hash values.

### `ProtocolTypes` [_In_]

A [NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_protocol_type) value that indicates the supported protocol types for calculating hash values.

### `Enable` [_In_]

A pointer to the client driver's *[EvtNetAdapterReceiveScalingEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_enable)* event callback function.

### `Disable` [_In_]

A pointer to the client driver's *[EvtNetAdapterReceiveScalingDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_disable)* event callback function.

### `SetHashSecretKey` [_In_]

A pointer to the client driver's *[EvtNetAdapterReceiveScalingSetHashSecretKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_hash_secret_key)* event callback function.

### `SetIndirectionEntries` [_In_]

A pointer to the client driver's *[EvtNetAdapterReceiveScalingSetIndirectionEntries](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_indirection_entries)* event callback function.

## Remarks

The [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure is an input parameter to [NetAdapterSetReceiveScalingCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-netadaptersetreceivescalingcapabilities). The client must use **NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT** to initialize this structure before calling **NetAdapterSetReceiveScalingCapabilities**.

## See also

[NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities)

[NetAdapterSetReceiveScalingCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-netadaptersetreceivescalingcapabilities)

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)