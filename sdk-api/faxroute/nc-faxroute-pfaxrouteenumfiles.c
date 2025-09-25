PFAXROUTEENUMFILES Pfaxrouteenumfiles;

BOOL Pfaxrouteenumfiles(
  [in]      DWORD JobId,
  [in]      GUID *Guid,
  [in]      PFAXROUTEENUMFILE FileEnumerator,
  [in, out] PVOID Context
)
{...}