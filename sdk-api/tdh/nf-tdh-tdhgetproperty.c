TDHSTATUS TdhGetProperty(
  [in]  PEVENT_RECORD             pEvent,
  [in]  ULONG                     TdhContextCount,
  [in]  PTDH_CONTEXT              pTdhContext,
  [in]  ULONG                     PropertyDataCount,
  [in]  PPROPERTY_DATA_DESCRIPTOR pPropertyData,
  [in]  ULONG                     BufferSize,
  [out] PBYTE                     pBuffer
);