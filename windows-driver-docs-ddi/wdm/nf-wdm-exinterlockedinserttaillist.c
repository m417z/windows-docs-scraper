PLIST_ENTRY ExInterlockedInsertTailList(
  [in, out] PLIST_ENTRY                  ListHead,
  [in, out] __drv_aliasesMem PLIST_ENTRY ListEntry,
  [in, out] PKSPIN_LOCK                  Lock
);