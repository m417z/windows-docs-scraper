BOOL IMAGEAPI SymGetModuleInfoW64(
  [in]  HANDLE              hProcess,
  [in]  DWORD64             qwAddr,
  [out] PIMAGEHLP_MODULEW64 ModuleInfo
);