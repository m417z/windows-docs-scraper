VOID ExInitializeNPagedLookasideList(
  [out]          PNPAGED_LOOKASIDE_LIST Lookaside,
  [in, optional] PALLOCATE_FUNCTION     Allocate,
  [in, optional] PFREE_FUNCTION         Free,
  [in]           ULONG                  Flags,
  [in]           SIZE_T                 Size,
  [in]           ULONG                  Tag,
  [in]           USHORT                 Depth
);