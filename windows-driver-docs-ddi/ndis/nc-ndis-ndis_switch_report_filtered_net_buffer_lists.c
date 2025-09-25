NDIS_SWITCH_REPORT_FILTERED_NET_BUFFER_LISTS NdisSwitchReportFilteredNetBufferLists;

VOID NdisSwitchReportFilteredNetBufferLists(
  [in]           NDIS_SWITCH_CONTEXT NdisSwitchContext,
  [in]           PUNICODE_STRING ExtensionGuid,
  [in]           PUNICODE_STRING ExtensionFriendlyName,
  [in]           NDIS_SWITCH_PORT_ID PortId,
  [in]           UINT32 Flags,
  [in]           UINT32 NumberOfNetBufferLists,
  [in]           PNET_BUFFER_LIST NetBufferLists,
  [in, optional] PUNICODE_STRING FilterReason
)
{...}