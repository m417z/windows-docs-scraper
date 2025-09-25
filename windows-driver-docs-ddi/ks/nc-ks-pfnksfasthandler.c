PFNKSFASTHANDLER Pfnksfasthandler;

BOOLEAN Pfnksfasthandler(
  [in]      PFILE_OBJECT FileObject,
  [in]      PKSIDENTIFIER Request,
  [in]      ULONG RequestLength,
  [in, out] PVOID Data,
  [in]      ULONG DataLength,
  [out]     PIO_STATUS_BLOCK IoStatus
)
{...}