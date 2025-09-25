DXGKDDI_QUERY_CHILD_RELATIONS DxgkddiQueryChildRelations;

NTSTATUS DxgkddiQueryChildRelations(
  [in]      IN_CONST_PVOID MiniportDeviceContext,
  [in, out] PDXGK_CHILD_DESCRIPTOR ChildRelations,
  [in]      ULONG ChildRelationsSize
)
{...}