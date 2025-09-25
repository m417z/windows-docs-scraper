NTSTATUS CollectionsListDeserializeFromBuffer(
  [in]     ULONG                   SourceBufferSizeInBytes,
  [in]     const BYTE              *SourceBuffer,
  [in/out] PSENSOR_COLLECTION_LIST TargetCollection
);