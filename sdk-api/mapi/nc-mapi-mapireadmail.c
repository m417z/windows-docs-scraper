MAPIREADMAIL Mapireadmail;

ULONG Mapireadmail(
  [in]  LHANDLE lhSession,
  [in]  ULONG_PTR ulUIParam,
  [in]  LPSTR lpszMessageID,
  [in]  FLAGS flFlags,
        ULONG ulReserved,
        lpMapiMessage *lppMessage
)
{...}