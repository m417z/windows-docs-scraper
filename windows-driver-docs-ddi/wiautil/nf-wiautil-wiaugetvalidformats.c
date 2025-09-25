HRESULT wiauGetValidFormats(
  [in]  IWiaMiniDrv *pDrv,
  [in]  BYTE        *pWiasContext,
        LONG        TymedValue,
  [out] int         *pNumFormats,
  [out] GUID        **ppFormatArray
);