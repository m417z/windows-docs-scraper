NTSYSAPI PRUNTIME_FUNCTION RtlLookupFunctionEntry(
  [in]  DWORD64               ControlPc,
  [out] PDWORD64              ImageBase,
  [out] PUNWIND_HISTORY_TABLE HistoryTable
);