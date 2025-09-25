NTSTATUS CollectionsListAllocateBufferAndSerialize(
  [in]  const PSENSOR_COLLECTION_LIST SourceCollection,
  [out] ULONG                         *pTargetBufferSizeInBytes,
  [out] BYTE                          **pTargetBuffer
);