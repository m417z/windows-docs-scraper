BOOL SetProcessValidCallTargets(
  [in]      HANDLE                hProcess,
  [in]      PVOID                 VirtualAddress,
  [in]      SIZE_T                RegionSize,
  [in]      ULONG                 NumberOfOffsets,
  [in, out] PCFG_CALL_TARGET_INFO OffsetInformation
);