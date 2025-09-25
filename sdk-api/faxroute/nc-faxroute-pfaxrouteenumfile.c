PFAXROUTEENUMFILE Pfaxrouteenumfile;

BOOL Pfaxrouteenumfile(
  [in]      DWORD JobId,
  [in]      GUID *GuidOwner,
  [in]      GUID *GuidCaller,
  [in]      LPCWSTR FileName,
  [in, out] PVOID Context
)
{...}