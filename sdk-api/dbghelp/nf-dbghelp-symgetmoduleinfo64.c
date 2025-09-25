BOOL IMAGEAPI SymGetModuleInfo64(
  [in]  HANDLE             hProcess,
  [in]  DWORD64            qwAddr,
  [out] PIMAGEHLP_MODULE64 ModuleInfo
);