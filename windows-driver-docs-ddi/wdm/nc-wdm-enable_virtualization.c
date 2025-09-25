ENABLE_VIRTUALIZATION EnableVirtualization;

NTSTATUS EnableVirtualization(
  [in, out] PVOID Context,
  [in]      UINT16 NumVFs,
  [in]      BOOLEAN EnableVfMigration,
  [in]      BOOLEAN EnableMigrationInterrupt,
  [in]      BOOLEAN EnableVirtualization
)
{...}