DWORD PssDuplicateSnapshot(
  [in]           HANDLE              SourceProcessHandle,
  [in]           HPSS                SnapshotHandle,
  [in]           HANDLE              TargetProcessHandle,
  [out]          HPSS                *TargetSnapshotHandle,
  [in, optional] PSS_DUPLICATE_FLAGS Flags
);