# _NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES structure

## Description

The **NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES** structure describes a net adapter's receive side scaling (RSS) capabilities.

## Members

### `Size`

The size of this structure, in bytes.

### `NumberOfQueues`

The number of hardware receive queues. This member must be a power of 2.

### `IndirectionTableSize`

The number of indirection table entries. This member must be a minimum of 128 and a power of 2.

### `UnhashedTargetIndex`

The default destination for frames to which no hash is applied. The value of this member depends on the value of the **UnhashedTargetType** member:

- If **UnhashedTargetType** is set to **NetAdapterReceiveScalingUnhashedTargetTypeUnspecified**, **UnhashedTarget** is ignored.
- If **UnhashedTargetType** is set to **NetAdapterReceiveScalingUnhashedTargetTypeHashIndex**, **UnhashedTarget** specifies a hash index in the indirection table.

This member must be **N**, where `0 <= N < IndirectionTableSize`.

### `UnhashedTargetType`

A [NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_unhashed_target_type) value that indicates the type of handling for unhashed frames.

If this member is set to **NetAdapterReceiveScalingUnhashedTargetTypeUnspecified**, then **UnhashedTargetIndex** is ignored and defaults to **0**.

If this member is set to **NetAdapterReceiveScalingUnhashedTargetTypeHashIndex**, then **UnhashedTargetIndex** indicates the target hash value.

### `ReceiveScalingHashTypes`

A [NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_hash_type) value that indicates supported hash function types for calculating hash values.

### `ReceiveScalingProtocolTypes`

A [NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_protocol_type) value that indicates the supported protocol types for calculating hash values.

### `_RECEIEVE_SCALING_ENCAPSULATION`

The tag identifier for **ReceiveScalingEncapsulationTypes**.

### `ReceiveScalingEncapsulationTypes`

Indicates which encapsulation technologies the hardware is capable of bypassing.

### `ReceiveScalingEncapsulationTypes.Outer`

A bitwise OR of [NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_encapsulation_type) values that indicates the transport (outer) encapsulation types that the NIC is capable of bypassing.

### `ReceiveScalingEncapsulationTypes.Inner`

A bitwise OR of [NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_encapsulation_type) values that indicates the tunnel (inner) encapsulation types that the NIC is capable of bypassing.

### `SynchronizeSetIndirectionEntries`

A boolean value that, when set to **TRUE**, requests that the framework synchronize calls to *[EvtNetAdapterReceiveScalingSetIndirectionEntries](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_indirection_entries)*. This member is set to **FALSE** by default if the client driver does not specify it.

### `EvtAdapterReceiveScalingEnable`

A pointer to the client driver's *[EvtNetAdapterReceiveScalingEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_enable)* event callback function.

### `EvtAdapterReceiveScalingDisable`

A pointer to the client driver's *[EvtNetAdapterReceiveScalingDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_disable)* event callback function.

### `EvtAdapterReceiveScalingSetHashSecretKey`

A pointer to the client driver's *[EvtNetAdapterReceiveScalingSetHashSecretKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_hash_secret_key)* event callback function.

### `EvtAdapterReceiveScalingSetIndirectionEntries`

A pointer to the client driver's *[EvtNetAdapterReceiveScalingSetIndirectionEntries](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_indirection_entries)* event callback function.

## Remarks

Call [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-net_adapter_receive_scaling_capabilities_init) to initialize this structure.

The **NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES** structure is an input parameter to [NetAdapterSetReceiveScalingCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-netadaptersetreceivescalingcapabilities). The client must use [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-net_adapter_receive_scaling_capabilities_init) to initialize this structure before calling **NetAdapterSetReceiveScalingCapabilities**.

## See also

[NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-net_adapter_receive_scaling_capabilities_init)

[NetAdapterSetReceiveScalingCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-netadaptersetreceivescalingcapabilities)

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)