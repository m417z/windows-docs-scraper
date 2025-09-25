# NET_POWER_OFFLOAD_NS_PARAMETERS structure

## Description

The **NET_POWER_OFFLOAD_NS_PARAMETERS** structure contains parameters for an IPv6 Neighbor Solicitation (NS) low power protocol offload to a net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `Id`

The identifier for this protocol offload.

### `RemoteIPv6Address`

The Source Address Field in the IPv6 header of the NS message. This member is optional.

If the incoming NS message has a Source Address value that matches this IPv6 address, the net adapter sends a neighbor advertisement (NA) message when it is in a low power state. If this member is zero, the net adapter should respond to NS messages from any remote IPv6 address.

### `SolicitedNodeIPv6Address`

The solicited node IPv6 address.

### `TargetIPv6Addresses`

An array that contains one or two IPv6 addresses. If it contains only one address, that address is stored in the first element in the array and the second element is filled with zeros.

Client drivers must consume all addresses in the array.

These addresses represent the Target Address field of an NS message. If one of these addresses matches the Target Address field of an incoming NS message, the net adapter sends an NA message in response.

### `LinkLayerAddress`

The media access control (MAC) address. When it sends the NA message, the net adapter uses this address for the target link layer address (TLLA) field of the NA message.

> [!NOTE]
> When it sends an NA message, the net adapter must always use this MAC address in the TLLA field of the NA message. However, it should use the current MAC address of the net adapter as the source address in the MAC header.

## Remarks

Call [**NET_POWER_OFFLOAD_NS_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-net_power_offload_ns_parameters_init) to initialize this structure and fill in its **Size** field. After calling **NET_POWER_OFFLOAD_NS_PARAMETERS_INIT**, call [**NetPowerOffloadGetNsParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-netpoweroffloadgetnsparameters) to fill in the remaining members of the structure.

For more information about IPv6 NS and NA messages, see [RFC 4861](https://www.ietf.org/rfc/rfc4861.txt).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_NS_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-net_power_offload_ns_parameters_init)

[**NetPowerOffloadGetNsParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-netpoweroffloadgetnsparameters)