MAPILOGON Mapilogon;

ULONG Mapilogon(
  [in]           ULONG_PTR ulUIParam,
  [in, optional] LPSTR lpszProfileName,
  [in, optional] LPSTR lpszPassword,
  [in]           FLAGS flFlags,
                 ULONG ulReserved,
  [out]          LPLHANDLE lplhSession
)
{...}