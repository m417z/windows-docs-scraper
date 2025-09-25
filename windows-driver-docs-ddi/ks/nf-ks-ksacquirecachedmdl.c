KSDDKAPI NTSTATUS KsAcquireCachedMdl(
  PIRP                 Irp,
  REFGUID              Guid,
  PFNKSCANCELPINNEDMDL CancelRoutine,
  PVOID                CancelContext,
  PMDL                 *MdlAddr,
  PVOID                *ReleaseContext
);