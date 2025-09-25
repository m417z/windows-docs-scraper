BOOL IMAGEAPI UpdateDebugInfoFile(
  [in]  PCSTR               ImageFileName,
  [in]  PCSTR               SymbolPath,
  [out] PSTR                DebugFilePath,
  [in]  PIMAGE_NT_HEADERS32 NtHeaders
);