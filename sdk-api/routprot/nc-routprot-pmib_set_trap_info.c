PMIB_SET_TRAP_INFO PmibSetTrapInfo;

DWORD PmibSetTrapInfo(
  [in]  HANDLE Event,
  [in]  ULONG InputDataSize,
  [in]  PVOID InputData,
  [out] PULONG OutputDataSize,
  [out] PVOID OutputData
)
{...}