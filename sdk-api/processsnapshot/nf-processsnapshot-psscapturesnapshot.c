DWORD PssCaptureSnapshot(
  [in]           HANDLE            ProcessHandle,
  [in]           PSS_CAPTURE_FLAGS CaptureFlags,
  [in, optional] DWORD             ThreadContextFlags,
  [out]          HPSS              *SnapshotHandle
);