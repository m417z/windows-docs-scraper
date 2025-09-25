NTSYSAPI PVOID RtlInsertElementGenericTableFullAvl(
  [in]            PRTL_AVL_TABLE      Table,
  [in]            PVOID               Buffer,
  [in]            CLONG               BufferSize,
  [out, optional] PBOOLEAN            NewElement,
  [in]            PVOID               NodeOrParent,
  [in]            TABLE_SEARCH_RESULT SearchResult
);