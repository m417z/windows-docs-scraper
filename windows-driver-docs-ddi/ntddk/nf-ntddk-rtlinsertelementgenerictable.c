NTSYSAPI PVOID RtlInsertElementGenericTable(
  [in]            PRTL_GENERIC_TABLE Table,
  [in]            PVOID              Buffer,
  [in]            CLONG              BufferSize,
  [out, optional] PBOOLEAN           NewElement
);