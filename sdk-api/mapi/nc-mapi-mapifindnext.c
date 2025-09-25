MAPIFINDNEXT Mapifindnext;

ULONG Mapifindnext(
  [in]  LHANDLE lhSession,
  [in]  ULONG_PTR ulUIParam,
  [in]  LPSTR lpszMessageType,
  [in]  LPSTR lpszSeedMessageID,
  [in]  FLAGS flFlags,
        ULONG ulReserved,
  [out] LPSTR lpszMessageID
)
{...}