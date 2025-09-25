PFAXROUTEGETFILE Pfaxroutegetfile;

BOOL Pfaxroutegetfile(
  [in]      DWORD JobId,
  [in]      DWORD Index,
  [out]     LPWSTR FileNameBuffer,
  [in, out] LPDWORD RequiredSize
)
{...}