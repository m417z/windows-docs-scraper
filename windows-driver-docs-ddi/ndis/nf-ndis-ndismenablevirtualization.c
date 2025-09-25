NDIS_STATUS NdisMEnableVirtualization(
  [in] NDIS_HANDLE NdisMiniportHandle,
  [in] USHORT      NumVFs,
  [in] BOOLEAN     EnableVFMigration,
  [in] BOOLEAN     EnableMigrationInterrupt,
  [in] BOOLEAN     EnableVirtualization
);