# NDIS_SWITCH_REPORT_FILTERED_NET_BUFFER_LISTS callback function

## Description

The *ReportFilteredNetBufferLists* function reports on one or more network packets that were dropped or excluded from port delivery by the extensible switch extension. Each network packet is defined through a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `ExtensionGuid` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the GUID of the extension. NDIS specifies this GUID in the **FilterModuleGuidName** member of the [NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure. NDIS passes a pointer to this structure in the *AttachParameters* parameter when it calls the extension's [FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `ExtensionFriendlyName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the user-friendly name of the extension. This name is defined by the **DisplayName** entry in the [AddService Directive](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addservice-directive)
of the extension's INF file.

### `PortId` [in]

An NDIS_SWITCH_PORT_ID value that specifies an extensible switch port. For more information, see the Remarks section.

### `Flags` [in]

A UINT32 value. When the NDIS_SWITCH_REPORT_FILTERED_NBL_FLAGS_IS_INCOMING flag is specified, it indicates that the **PortId** member defines the source of the dropped packet. When it is not specified, the PortId member defines the destination extensible switch port. For more information, see the Remarks section.

### `NumberOfNetBufferLists` [in]

A UINT32 value that contains the number of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that is specified by the *NetBufferLists* parameter.

### `NetBufferLists` [in]

A pointer to a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

### `FilterReason` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a user-friendly description of the reason for the drop or exclusion of the packets. For more information, see the Remarks section.

## Remarks

When the extension excludes the delivery of a packet to an extensible switch port, it must call *ReportFilteredNetBufferLists*. When this function is called, the extensible switch module increments counters and logs events for the dropped or excluded packets. When it logs an event for a dropped or excluded set of packets, the extensible switch module uses the user-friendly description that is specified by the *FilterReason* parameter.

The extension can exclude the delivery of a packet in the following ways:

* The extension completes the packet instead of forwarding it on through the extensible switch driver stack. For example, the extension can call [NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) to drop a packet that it inspected when NDIS calls its [FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) function.
* The extension changes the destination ports for a packet. For example, the extension must call *ReportFilteredNetBufferLists* if it sets the **IsExcluded** member to **TRUE** in the [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure for a destination port of the packet.

  For more information on how to exclude packet delivery to extensible switch ports, see [Excluding Packet Delivery to Extensible Switch Destination Ports](https://learn.microsoft.com/windows-hardware/drivers/network/excluding-packet-delivery-to-extensible-switch-destination-ports).

The extension must follow these guidelines when it calls *ReportFilteredNetBufferLists*:

* The *NetBufferLists* parameter specified a linked-list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. All of the packets specified by these structures must have been received from or sent to the same port, and were dropped or excluded for the same reason.
* If the packet is being dropped due to policy based on the source port, the NDIS_SWITCH_REPORT_FILTERED_NBL_FLAGS_IS_INCOMING flag must be specified. The extension must also set the *PortId* parameter to the identifier of the port from which the packet was received.
* If the packet is being dropped due to policy based on the destination port, the NDIS_SWITCH_REPORT_FILTERED_NBL_FLAGS_IS_INCOMING flag must not be specified. The extension must also set the *PortId* parameter to the identifier of the port to which the packet was to be sent.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[INF AddService Directive](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addservice-directive)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)