# FWPS_INCOMING_METADATA_VALUES0_ structure

## Description

The **FWPS_INCOMING_METADATA_VALUES0** structure defines metadata values that the filter engine passes to a callout's [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

> [!NOTE]
> **FWPS_INCOMING_METADATA_VALUES0** is a specific version of **FWPS_INCOMING_METADATA_VALUES**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `currentMetadataValues`

A UINT32 value that contains a bitwise OR of a combination of [Metadata Field Identifiers](https://learn.microsoft.com/windows-hardware/drivers/network/metadata-field-identifiers) that specify which metadata values are set in the structure.

### `flags`

Used internally by the filter engine. Callout drivers should ignore this member.

### `reserved`

Reserved for system use. Callout drivers should ignore this member.

### `discardMetadata`

An [FWPS_DISCARD_METADATA0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_discard_metadata0) structure that describes the reason why the data was discarded. This member contains valid data only if the FWPS_METADATA_FIELD_DISCARD_REASON flag is set in the **currentMetadataValues** member.

### `flowHandle`

A handle for the data flow. This member contains valid data only if the FWPS_METADATA_FIELD_FLOW_HANDLE flag is set in the `currentMetadataValues` member.

### `ipHeaderSize`

The offset, in bytes, of the IP header.

On inbound paths, **ipHeaderSize**, when used in conjunction with the **transportHeaderSize** member, specifies the number of bytes to retreat from the data offset location to the beginning of the IP header.

On the following inbound ICMP error layers, **ipHeaderSize** alone specifies the total number of bytes to retreat from the data offset to the beginning of the IP header:

FWPS_LAYER_INBOUND_ICMP_ERROR_V4

FWPS_LAYER_INBOUND_ICMP_ERROR_V6

FWPS_LAYER_INBOUND_ICMP_ERROR_V4_DISCARD

FWPS_LAYER_INBOUND_ICMP_ERROR_V6_DISCARD

On outbound paths, if `ipHeaderSize` is greater than zero, it specifies the number of bytes to advance from the data offset location to the end of the IP header.

This member is not applicable to the outbound path at the following layers:

FWPS_LAYER_DATAGRAM_DATA_V4

FWPS_LAYER_DATAGRAM_DATA_V6

FWPS_LAYER_DATAGRAM_DATA_V4_DISCARD

FWPS_LAYER_DATAGRAM_DATA_V6_DISCARD

This member contains valid data only if the FWPS_METADATA_FIELD_IP_HEADER_SIZE flag is set in the **currentMetadataValues** member.

### `transportHeaderSize`

The offset or size, in bytes, of the transport header.

On inbound paths, **transportHeaderSize** specifies the number of bytes to retreat from the data offset location to the end of the transport header.

On the following inbound ICMP error layers, **transportHeaderSize** specifies the size of the ICMP header:

- FWPS_LAYER_INBOUND_ICMP_ERROR_V4
- FWPS_LAYER_INBOUND_ICMP_ERROR_V6
- FWPS_LAYER_INBOUND_ICMP_ERROR_V4_DISCARD
- FWPS_LAYER_INBOUND_ICMP_ERROR_V6_DISCARD

On outbound paths, **transportHeaderSize** specifies the number of bytes to advance from the data offset location to the end of the transport header.

This member contains valid data only if the FWPS_METADATA_FIELD_TRANSPORT_HEADER_SIZE flag is set in the **currentMetadataValues** member.

### `processPath`

A pointer to an [FWP_BYTE_BLOB](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552427(v=vs.85)) structure that contains the full path to the process that owns the endpoint. This member contains valid data only if the FWPS_METADATA_FIELD_PROCESS_PATH flag is set in the **currentMetadataValues** member.

### `token`

A handle for the token used to validate the permissions for the user. This member contains valid data only if the FWPS_METADATA_FIELD_TOKEN flag is set in the `currentMetadataValues` member.

### `processId`

The process ID for the process that owns the endpoint. This member contains valid data only if the FWPS_METADATA_FIELD_PROCESS_ID flag is set in the **currentMetadataValues** member.

### `sourceInterfaceIndex`

The index of the network interface where an incoming packet was received. This member contains valid data only if the FWPS_METADATA_FIELD_SOURCE_INTERFACE_INDEX flag is set in the **currentMetadataValues** member.

### `destinationInterfaceIndex`

The index of the network interface where an outgoing packet is to be sent. This member contains valid data only if the FWPS_METADATA_FIELD_DESTINATION_INTERFACE_INDEX flag is set in the **currentMetadataValues** member.

### `compartmentId`

The identifier of the routing compartment in which the packet either was received or is being sent. Any modified packets should be injected back into the same routing compartment that is indicated for the original packet. This member contains valid data only if the FWPS_METADATA_FIELD_COMPARTMENT_ID flag is set in the **currentMetadataValues** member.

### `fragmentMetadata`

An [FWPS_INBOUND_FRAGMENT_METADATA0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_inbound_fragment_metadata0) structure that describes the fragment data for a received packet fragment. This member contains valid data only if the FWPS_METADATA_FIELD_FRAGMENT_DATA flag is set in the **currentMetadataValues** member.

### `pathMtu`

The path maximum transmission unit (path MTU) for an outbound packet. This value indicates the largest physical packet size, in bytes, that a network can transmit without fragmentation, This member contains valid data only if the FWPS_METADATA_FIELD_PATH_MTU flag is set in the **currentMetadataValues** member.

### `completionHandle`

A completion handle that is required to pend the current filtering operation. This member contains valid data only if the FWPS_METADATA_FIELD_COMPLETION_HANDLE flag is set in the **currentMetadataValues** member.

### `transportEndpointHandle`

An endpoint handle that indicates the end of the packet to be injected into the outbound transport layer. This member contains valid data only if the FWPS_METADATA_FIELD_TRANSPORT_ENDPOINT_HANDLE flag is set in the **currentMetadataValues** member.

### `remoteScopeId`

The remote scope identifier to be used in outbound transport layer injection. This member contains valid data only if the FWPS_METADATA_FIELD_REMOTE_SCOPE_ID flag is set in the **currentMetadataValues** member.

### `controlData`

An optional socket control data object. This member contains valid data only if the FWPS_METADATA_FIELD_TRANSPORT_CONTROL_DATA flag is set in the **currentMetadataValues** member. For information about the WSACMSGHDR type, see [CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr).

### `controlDataLength`

The length, in bytes, of the **controlData** member.

### `packetDirection`

The direction of network traffic (inbound or outbound) as specified by one of the constant values of [FWP_DIRECTION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552433(v=vs.85)). This member is set at the application layer enforcement (ALE) connect or receive/accept layers during a reauthorization classify operation. For more information, see the Remarks section.

> [!NOTE]
> This member contains valid data only if the FWPS_METADATA_FIELD_PACKET_DIRECTION flag is set in the **currentMetadataValues** member.

### `headerIncludeHeader`

A pointer to the IP header if the packet is sent from a raw socket.

### `headerIncludeHeaderLength`

The length, in bytes, of the IP header that is pointed to by **headerIncludeHeader**.

### `destinationPrefix`

The destination prefix.

### `frameLength`

The frame length.

### `parentEndpointHandle`

The handle of the endpoint's parent.

### `icmpIdAndSequence`

The ICMP identifier and sequence.

### `localRedirectTargetPID`

The PID of the process that is responsible for a redirected connection.

### `originalDestination`

The original destination of a redirected connection.

### `redirectRecords`

A redirect records handle that can be passed to the [FwpsQueryConnectionRedirectState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsqueryconnectionredirectstate0) function to get the redirect state.

### `currentL2MetadataValues`

A bitmask that contains flags that specify which layer 2 values are set. One or more values can be combined with a bitwise OR.

 | Value | Meaning |
|--|--|
| **FWPS_L2_METADATA_FIELD_ETHERNET_MAC_HEADER_SIZE** | The value of the **ethernetMacHeaderSize** member indicates the size of the MAC header. |
| **FWPS_L2_METADATA_FIELD_WIFI_OPERATION_MODE** | The value of the **wiFiOperationMode** member indicates current Native 802.11 operation mode. |
| **FWPS_L2_METADATA_FIELD_VSWITCH_SOURCE_PORT_ID** | The value of the **vSwitchSourcePortId** member indicates the identifier for the source port on the virtual switch. |
| **FWPS_L2_METADATA_FIELD_VSWITCH_SOURCE_NIC_INDEX** | The value of the **vSwitchSourceNicIndex** member indicates the index for the source NIC on the virtual switch. |
| **FWPS_L2_METADATA_FIELD_VSWITCH_PACKET_CONTEXT** | The value of the **vSwitchPacketContext** member indicates a HANDLE to the virtual switch packet context. |
| **FWPS_L2_METADATA_FIELD_VSWITCH_DESTINATION_PORT_ID** | The value of the **vSwitchDestinationPortId** member indicates the identifier for the destination port on the virtual switch. |

### `l2Flags`

A bitmask containing layer 2 flags that can be combined with a bitwise OR.

| Value | Meaning |
|--|--|
| **FWPS_L2_INCOMING_FLAG_IS_RAW_IPV4_FRAMING** | Indicates raw IP4 framing. |
| **FWPS_L2_INCOMING_FLAG_IS_RAW_IPV6_FRAMING** | Indicates raw IP6 framing. |
| **FWPS_L2_INCOMING_FLAG_RECLASSIFY_MULTI_DESTINATION** | This flag indicates that an NBL that was seen once at ingress has been distributed into multiple NBLs, each of which is destined to a different VM, and the first NBL of this distribution has already been indicated to your callout driver.<br><br>The first NBL of the distributed group will not have this flag set. All subsequent NBLs for the group will have this flag set.<br><br>For the purpose of injecting, your callout driver should clone the NBL, block and absorb the original packet, and clear the FWPS_RIGHT_ACTION_WRITE flag for the first indication. Then modify the clone and inject it into the ingress path.<br><br>For all subsequent indications, you should block and absorb the original packet and clear the FWPS_RIGHT_ACTION_WRITE flag for the clone. When the injected clone comes out of ingress, it will then be redistributed again, and all indications will have an injection state of FWPS_PACKET_INJECTED_BY_SELF or FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF. |

### `ethernetMacHeaderSize`

The size, in bytes, of the MAC header if the FWPS_L2_METADATA_FIELD_802_3_MAC_HEADER_SIZE flag is set. This flag is set for the inbound 802.3 layer only.

### `wiFiOperationMode`

The current Native 802.11 operation mode if the FWPS_L2_METADATA_FIELD_802_11_OPERATION_MODE flag is set. For more information, see [DOT11_CURRENT_OPERATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_current_operation_mode).

### `vSwitchSourcePortId`

A unique identifier for the source port on the virtual switch.

### `vSwitchSourceNicIndex`

A index for the source NIC on the virtual switch.

### `vSwitchDestinationPortId`

A unique identifier for the destination port on the virtual switch.

### `padding0`

Reserved.

### `padding1`

Reserved.

### `padding2`

Reserved.

### `vSwitchPacketContext`

A handle to the virtual switch packet context.

### `subProcessTag`

Reserved.

### `reserved1`

Reserved.

## Remarks

The filter engine passes a pointer to an FWPS_INCOMING_METADATA_VALUES0 structure to a callout's [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. The metadata values contained in the structure are not processed by the filter engine but are supplied to a callout's *classifyFn* callout function to provide additional information.

A callout driver can use the following macro to test if a specific metadata value is present in an FWPS_INCOMING_METADATA_VALUES0 structure:

```c++
FWPS_IS_METADATA_FIELD_PRESENT(metadataValues, metadataField)
```

If the FWPS_METADATA_FIELD_PACKET_DIRECTION metadata value is present in an FWPS_INCOMING_METADATA_VALUES0 structure, the **packetDirection** member specifies whether the packet was inbound or outbound during a reauthorization classify operation. Otherwise, the FWPS_METADATA_FIELD_PACKET_DIRECTION metadata value is not present.

The callout driver must follow these guidelines when it inspects the packet:

- At the ALE connect or receive/accept layers, the callout driver should not assume that the packet contains a valid IP header if **packetDirection** is set to **FWP_DIRECTION_OUTBOUND** and the FWPS_METADATA_FIELD_PACKET_DIRECTION metadata value is present.
- At the ALE connect layer, if the FWPS_METADATA_FIELD_PACKET_DIRECTION metadata value is not present, the callout driver should assume a packet direction of FWP_DIRECTION_OUTBOUND.
- At the ALE receive/accept layer, if the FWPS_METADATA_FIELD_PACKET_DIRECTION metadata value is not present, the callout driver should assume a packet direction of FWP_DIRECTION_INBOUND.

## See also

- [CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr)
- [FWPS_DISCARD_METADATA0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_discard_metadata0)
- [FWPS_INBOUND_FRAGMENT_METADATA0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_inbound_fragment_metadata0)
- [FWP_BYTE_BLOB](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552427(v=vs.85))
- [FWP_DIRECTION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552433(v=vs.85))
- [FwpsQueryConnectionRedirectState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsqueryconnectionredirectstate0)
- [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
- [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)