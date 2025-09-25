PSYMBOLSERVERCALLBACKPROC Psymbolservercallbackproc;

BOOL Psymbolservercallbackproc(
  [in] UINT_PTR action,
  [in] ULONG64 data,
  [in] ULONG64 context
)
{...}