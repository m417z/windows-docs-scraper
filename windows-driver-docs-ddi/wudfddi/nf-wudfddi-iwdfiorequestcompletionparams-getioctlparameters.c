void GetIoctlParameters(
  [out, optional] ULONG      *pIoControlCode,
  [out, optional] IWDFMemory **ppInputMemory,
  [out, optional] SIZE_T     *pInputMemoryOffset,
  [out, optional] IWDFMemory **ppOutputMemory,
  [out, optional] SIZE_T     *pOutputMemoryOffset,
  [out, optional] SIZE_T     *pOutBytes
);