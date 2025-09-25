HRESULT GetDVDTextStringAsNative(
  [in]  ULONG              ulLangIndex,
  [in]  ULONG              ulStringIndex,
  [out] BYTE               *pbBuffer,
  [in]  ULONG              ulMaxBufferSize,
  [out] ULONG              *pulActualSize,
  [out] DVD_TextStringType *pType
);