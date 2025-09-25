MAPIRESOLVENAME Mapiresolvename;

ULONG Mapiresolvename(
  [in]  LHANDLE lhSession,
  [in]  ULONG_PTR ulUIParam,
  [in]  LPSTR lpszName,
  [in]  FLAGS flFlags,
        ULONG ulReserved,
        lpMapiRecipDesc *lppRecip
)
{...}