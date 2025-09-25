# NET_POWER_OFFLOAD_ARP_PARAMETERS structure

## Description

The **NET_POWER_OFFLOAD_ARP_PARAMETERS** structure contains parameters for an IPv4 ARP low-power protocol offload to a net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `Id`

The identifier for this protocol offload.

### `RemoteIPv4Address`

The Source Protocol Address (SPA) field of the ARP request. This member is optional.

If the incoming ARP request has an SPA value that matches this IPv4 address, the net adapter sends an ARP response when it is in a low power state. If this member is zero, the net adapter should respond to ARP requests from any remote IPv4 address.

### `HostIPv4Address`

The host's IPv4 address. When it sends the ARP response, the net adapter uses this member for the SPA field of the response.

### `LinkLayerAddress`

The media access control (MAC) address. The net adapter uses this MAC address for the Source Hardware Address (SHA) field of the ARP response packet that it generates.

> [!NOTE]
> When it sends an ARP response, the net adapter must always use this MAC address in the ARP payload. However, it should use the current MAC address of the net adapter as the source address in the MAC header.

## Remarks

Call [**NET_POWER_OFFLOAD_ARP_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-net_power_offload_arp_parameters_init) to initialize this structure and fill in its **Size** field. After calling **NET_POWER_OFFLOAD_ARP_PARAMETERS_INIT**, call [**NetPowerOffloadGetArpParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-netpoweroffloadgetarpparameters) to fill in the remaining members of the structure.

For more information about the ARP protocol, see [RFC 826](https://tools.ietf.org/html/rfc826).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_ARP_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-net_power_offload_arp_parameters_init)

[**NetPowerOffloadGetArpParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-netpoweroffloadgetarpparameters)