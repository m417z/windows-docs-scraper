NDIS_SWITCH_COPY_NET_BUFFER_LIST_INFO NdisSwitchCopyNetBufferListInfo;

NDIS_STATUS NdisSwitchCopyNetBufferListInfo(
  [in]      NDIS_SWITCH_CONTEXT NdisSwitchContext,
  [in, out] PNET_BUFFER_LIST DestNetBufferList,
  [in]      PNET_BUFFER_LIST SrcNetBufferList,
  [in]      UINT32 Flags
)
{...}