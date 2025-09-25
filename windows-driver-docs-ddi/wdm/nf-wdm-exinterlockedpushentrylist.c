PSINGLE_LIST_ENTRY ExInterlockedPushEntryList(
  [in, out] PSINGLE_LIST_ENTRY                  ListHead,
  [in, out] __drv_aliasesMem PSINGLE_LIST_ENTRY ListEntry,
  [in, out] PKSPIN_LOCK                         Lock
);