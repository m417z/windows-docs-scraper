FN_VMB_CLIENT_CHANNEL_INIT_SET_RING_BUFFER_PAGE_COUNT FnVmbClientChannelInitSetRingBufferPageCount;

NTSTATUS FnVmbClientChannelInitSetRingBufferPageCount(
  VMBCHANNEL Channel,
  UINT32 IncomingPageCount,
  UINT32 OutgoingPageCount
)
{...}