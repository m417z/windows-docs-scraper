HRESULT GetTextReplacement(
  [in, optional]  PCSTR  SrcText,
  [in]            ULONG  Index,
  [out, optional] PSTR   SrcBuffer,
  [in]            ULONG  SrcBufferSize,
  [out, optional] PULONG SrcSize,
  [out, optional] PSTR   DstBuffer,
  [in]            ULONG  DstBufferSize,
  [out, optional] PULONG DstSize
);