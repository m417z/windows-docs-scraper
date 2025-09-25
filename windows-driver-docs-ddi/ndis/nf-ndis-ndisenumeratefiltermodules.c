NDIS_STATUS NdisEnumerateFilterModules(
  [in]      NDIS_HANDLE NdisHandle,
  [in]      PVOID       InterfaceBuffer,
  [in]      ULONG       InterfaceBufferLength,
  [in, out] PULONG      BytesNeeded,
  [in, out] PULONG      BytesWritten
);