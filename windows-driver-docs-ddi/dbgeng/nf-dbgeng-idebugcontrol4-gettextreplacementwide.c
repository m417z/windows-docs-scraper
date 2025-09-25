HRESULT GetTextReplacementWide(
  [in, optional]  PCWSTR SrcText,
  [in]            ULONG  Index,
  [out, optional] PWSTR  SrcBuffer,
  [in]            ULONG  SrcBufferSize,
  [out, optional] PULONG SrcSize,
  [out, optional] PWSTR  DstBuffer,
  [in]            ULONG  DstBufferSize,
  [out, optional] PULONG DstSize
);