PIMAGEHLP_STATUS_ROUTINE PimagehlpStatusRoutine;

BOOL PimagehlpStatusRoutine(
  [in] IMAGEHLP_STATUS_REASON Reason,
  [in] PCSTR ImageName,
  [in] PCSTR DllName,
  [in] ULONG_PTR Va,
  [in] ULONG_PTR Parameter
)
{...}