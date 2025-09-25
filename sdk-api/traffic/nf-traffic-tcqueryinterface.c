ULONG TcQueryInterface(
  [in]      HANDLE  IfcHandle,
  [in]      LPGUID  pGuidParam,
  [in]      BOOLEAN NotifyChange,
  [in, out] PULONG  pBufferSize,
  [out]     PVOID   Buffer
);