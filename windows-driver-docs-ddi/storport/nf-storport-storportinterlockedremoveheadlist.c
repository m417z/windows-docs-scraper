ULONG StorPortInterlockedRemoveHeadList(
  [in]      PVOID            HwDeviceExtension,
  [in, out] PSTOR_LIST_ENTRY ListHead,
  [in, out] PSTOR_LIST_ENTRY *Result,
  [in, out] PSTOR_KSPIN_LOCK Lock
);