HRESULT GetDVDTextStringAsUnicode(
  [in]  ULONG              ulLangIndex,
  [in]  ULONG              ulStringIndex,
  [out] WCHAR              *pchwBuffer,
  [in]  ULONG              ulMaxBufferSize,
  [out] ULONG              *pulActualSize,
  [out] DVD_TextStringType *pType
);