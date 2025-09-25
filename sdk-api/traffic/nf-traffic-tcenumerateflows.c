ULONG TcEnumerateFlows(
  [in]      HANDLE              IfcHandle,
  [in, out] PHANDLE             pEnumHandle,
  [in, out] PULONG              pFlowCount,
  [in, out] PULONG              pBufSize,
  [out]     PENUMERATION_BUFFER Buffer
);