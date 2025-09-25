ULONG StorPortInterlockedPushEntrySList(
  [in]      PVOID                              HwDeviceExtension,
  [in, out] PSTOR_SLIST_HEADER                 SListHead,
  [in, out] __drv_aliasesMem PSTOR_SLIST_ENTRY SListEntry,
  [out]     PSTOR_SLIST_ENTRY                  *Result
);