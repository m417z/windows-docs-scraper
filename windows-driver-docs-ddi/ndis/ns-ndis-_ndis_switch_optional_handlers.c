typedef struct _NDIS_SWITCH_OPTIONAL_HANDLERS {
  NDIS_OBJECT_HEADER                                              Header;
  NDIS_SWITCH_ALLOCATE_NET_BUFFER_LIST_FORWARDING_CONTEXT_HANDLER AllocateNetBufferListForwardingContext;
  NDIS_SWITCH_FREE_NET_BUFFER_LIST_FORWARDING_CONTEXT_HANDLER     FreeNetBufferListForwardingContext;
  NDIS_SWITCH_SET_NET_BUFFER_LIST_SOURCE_HANDLER                  SetNetBufferListSource;
  NDIS_SWITCH_ADD_NET_BUFFER_LIST_DESTINATION_HANDLER             AddNetBufferListDestination;
  NDIS_SWITCH_GROW_NET_BUFFER_LIST_DESTINATIONS_HANDLER           GrowNetBufferListDestinations;
  NDIS_SWITCH_GET_NET_BUFFER_LIST_DESTINATIONS_HANDLER            GetNetBufferListDestinations;
  NDIS_SWITCH_UPDATE_NET_BUFFER_LIST_DESTINATIONS_HANDLER         UpdateNetBufferListDestinations;
  NDIS_SWITCH_COPY_NET_BUFFER_LIST_INFO_HANDLER                   CopyNetBufferListInfo;
  NDIS_SWITCH_REFERENCE_SWITCH_NIC_HANDLER                        ReferenceSwitchNic;
  NDIS_SWITCH_DEREFERENCE_SWITCH_NIC_HANDLER                      DereferenceSwitchNic;
  NDIS_SWITCH_REFERENCE_SWITCH_PORT_HANDLER                       ReferenceSwitchPort;
  NDIS_SWITCH_DEREFERENCE_SWITCH_PORT_HANDLER                     DereferenceSwitchPort;
  NDIS_SWITCH_REPORT_FILTERED_NET_BUFFER_LISTS_HANDLER            ReportFilteredNetBufferLists;
  NDIS_SWITCH_SET_NET_BUFFER_LIST_SWITCH_CONTEXT_HANDLER          SetNetBufferListSwitchContext;
  NDIS_SWITCH_GET_NET_BUFFER_LIST_SWITCH_CONTEXT_HANDLER          GetNetBufferListSwitchContext;
  PVOID                                                           SwitchPDReserved[NDIS_SWITCH_OPTIONAL_HANDLERS_PD_RESERVED_SIZE];
} NDIS_SWITCH_OPTIONAL_HANDLERS, *PNDIS_SWITCH_OPTIONAL_HANDLERS;