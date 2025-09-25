HRESULT wiasReadPropLong(
  [in]            BYTE   *pWiasContext,
                  PROPID propid,
  [out]           LONG   *plVal,
  [out, optional] LONG   *plValOld,
                  BOOL   bMustExist
);