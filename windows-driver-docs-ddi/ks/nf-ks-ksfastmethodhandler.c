KSDDKAPI BOOLEAN KsFastMethodHandler(
  [in]      PFILE_OBJECT       FileObject,
  [in]      PKSMETHOD          Method,
  [in]      ULONG              MethodLength,
  [in, out] PVOID              Data,
  [in]      ULONG              DataLength,
  [out]     PIO_STATUS_BLOCK   IoStatus,
  [in]      ULONG              MethodSetsCount,
  [in]      const KSMETHOD_SET *MethodSet
);