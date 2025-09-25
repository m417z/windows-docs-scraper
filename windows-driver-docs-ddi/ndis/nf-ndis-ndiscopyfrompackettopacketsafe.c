VOID NdisCopyFromPacketToPacketSafe(
  [in]  IN PNDIS_PACKET     Destination,
  [in]  IN UINT             DestinationOffset,
  [in]  IN UINT             BytesToCopy,
  [in]  IN PNDIS_PACKET     Source,
  [in]  IN UINT             SourceOffset,
  [out] OUT PUINT           BytesCopied,
        IN MM_PAGE_PRIORITY Priority
);