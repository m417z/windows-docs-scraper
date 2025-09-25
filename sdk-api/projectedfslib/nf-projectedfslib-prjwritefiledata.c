HRESULT PrjWriteFileData(
  [in] PRJ_NAMESPACE_VIRTUALIZATION_CONTEXT namespaceVirtualizationContext,
  [in] const GUID                           *dataStreamId,
  [in] void                                 *buffer,
  [in] UINT64                               byteOffset,
  [in] UINT32                               length
);