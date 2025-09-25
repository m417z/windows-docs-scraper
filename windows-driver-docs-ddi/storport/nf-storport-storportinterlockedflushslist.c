ULONG StorPortInterlockedFlushSList(
  [in]      PVOID              HwDeviceExtension,
  [in, out] PSTOR_SLIST_HEADER SListHead,
  [out]     PSTOR_SLIST_ENTRY  *Result
);