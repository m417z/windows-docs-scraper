DWORD PssWalkSnapshot(
  [in]  HPSS                       SnapshotHandle,
  [in]  PSS_WALK_INFORMATION_CLASS InformationClass,
  [in]  HPSSWALK                   WalkMarkerHandle,
  [out] void                       *Buffer,
  [in]  DWORD                      BufferLength
);