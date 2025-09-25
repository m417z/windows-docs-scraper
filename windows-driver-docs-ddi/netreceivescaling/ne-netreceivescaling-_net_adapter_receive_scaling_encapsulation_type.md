# _NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE enumeration

## Description

The **NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE** enumeration specifies packet encapsulation technologies an RSS-capable NIC is able to bypass.

## Constants

### `NetAdapterReceiveScalingEncapsulationTypeNone:0x00000000`

Indicates that the hardware cannot bypass any encapsulation technologies.

### `NetAdapterReceiveScalingEncapsulationTypeNVGre:0x00000001`

Indicates that the hardware understands how to bypass [NV-GRE encapsulation](https://learn.microsoft.com/windows-server/networking/sdn/technologies/hyper-v-network-virtualization/hyperv-network-virtualization-technical-details-windows-server#generic-routing-encapsulation-nvgre).

### `NetAdapterReceiveScalingEncapsulationTypeVXLan:0x00000002`

Indicates that the hardware understands how to bypass [VXLan encapsulation](https://learn.microsoft.com/windows-server/networking/sdn/technologies/hyper-v-network-virtualization/hyperv-network-virtualization-technical-details-windows-server#virtual-extensible-local-area-network-vxlan).

### `NetAdapterReceiveScalingEncapsulationTypeVLan:0x00000004`

Indicates that the hardware understands how to bypass [VLan encapsulation](https://learn.microsoft.com/windows-server/networking/sdn/technologies/hyper-v-network-virtualization/hyperv-network-virtualization-technical-details-windows-server#VirtualNetworks).

## Remarks

The **ReceiveScalingEncapsulationTypes** member of the [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure contains information for both outer (transport) and inner (tunnel) encapsulation types that the NIC is capable of bypassing. These members each contain a bitwise OR of **NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE** constants.

## See also

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)

[Hyper-V Network Virtualization Technical Details in Windows Server 2016](https://learn.microsoft.com/windows-server/networking/sdn/technologies/hyper-v-network-virtualization/hyperv-network-virtualization-technical-details-windows-server)