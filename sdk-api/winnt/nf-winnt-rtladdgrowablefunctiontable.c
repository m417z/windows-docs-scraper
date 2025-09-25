NTSYSAPI DWORD RtlAddGrowableFunctionTable(
  [out] PVOID             *DynamicTable,
        PRUNTIME_FUNCTION FunctionTable,
  [in]  DWORD             EntryCount,
  [in]  DWORD             MaximumEntryCount,
  [in]  ULONG_PTR         RangeBase,
  [in]  ULONG_PTR         RangeEnd
);