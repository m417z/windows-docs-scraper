NTSTATUS FLTAPI FltRegisterFilter(
  [in]  PDRIVER_OBJECT         Driver,
  [in]  const FLT_REGISTRATION *Registration,
  [out] PFLT_FILTER            *RetFilter
);