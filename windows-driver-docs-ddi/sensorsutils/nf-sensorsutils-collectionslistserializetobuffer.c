NTSTATUS CollectionsListSerializeToBuffer(
  [in]  const PSENSOR_COLLECTION_LIST SourceCollection,
  [in]  ULONG                         TargetBufferSizeInBytes,
  [out] BYTE                          *TargetBuffer
);