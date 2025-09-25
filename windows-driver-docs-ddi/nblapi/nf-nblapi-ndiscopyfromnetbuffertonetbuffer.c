NDIS_EXPORTED_ROUTINE NDIS_STATUS NdisCopyFromNetBufferToNetBuffer(
  [in]  NET_BUFFER       *Destination,
  [in]  ULONG            DestinationOffset,
  [in]  ULONG            BytesToCopy,
  [in]  NET_BUFFER const *Source,
  [in]  ULONG            SourceOffset,
  [out] ULONG            *BytesCopied
);