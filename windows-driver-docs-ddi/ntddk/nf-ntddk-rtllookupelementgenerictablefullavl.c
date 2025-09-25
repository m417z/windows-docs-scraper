NTSYSAPI PVOID RtlLookupElementGenericTableFullAvl(
  [in]  PRTL_AVL_TABLE      Table,
  [in]  PVOID               Buffer,
  [out] PVOID               *NodeOrParent,
  [out] TABLE_SEARCH_RESULT *SearchResult
);