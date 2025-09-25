DWORD PssQuerySnapshot(
  [in]  HPSS                        SnapshotHandle,
  [in]  PSS_QUERY_INFORMATION_CLASS InformationClass,
  [out] void                        *Buffer,
  [in]  DWORD                       BufferLength
);