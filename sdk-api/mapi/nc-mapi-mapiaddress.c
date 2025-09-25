MAPIADDRESS Mapiaddress;

ULONG Mapiaddress(
  [in]  LHANDLE lhSession,
  [in]  ULONG_PTR ulUIParam,
  [in]  LPSTR lpszCaption,
  [in]  ULONG nEditFields,
  [in]  LPSTR lpszLabels,
  [in]  ULONG nRecips,
  [in]  lpMapiRecipDesc lpRecips,
  [in]  FLAGS flFlags,
        ULONG ulReserved,
  [out] LPULONG lpnNewRecips,
        lpMapiRecipDesc *lppNewRecips
)
{...}