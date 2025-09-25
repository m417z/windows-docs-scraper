NTSYSAPI PVOID RtlInsertElementGenericTableAvl(
  [in]            PRTL_AVL_TABLE Table,
  [in]            PVOID          Buffer,
  [in]            CLONG          BufferSize,
  [out, optional] PBOOLEAN       NewElement
);