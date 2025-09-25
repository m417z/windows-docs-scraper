NTSTATUS FLTAPI FltEnumerateFilters(
  [out] PFLT_FILTER *FilterList,
  [in]  ULONG       FilterListSize,
  [out] PULONG      NumberFiltersReturned
);