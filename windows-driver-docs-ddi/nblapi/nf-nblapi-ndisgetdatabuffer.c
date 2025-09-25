NDIS_EXPORTED_ROUTINE PVOID NdisGetDataBuffer(
  [in]           NET_BUFFER *NetBuffer,
  [in]           ULONG      BytesNeeded,
  [in, optional] PVOID      Storage,
  [in]           ULONG      AlignMultiple,
  [in]           ULONG      AlignOffset
);