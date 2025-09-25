HRESULT wiasReadPropGuid(
  [in]            BYTE   *pWiasContext,
                  PROPID propid,
  [out]           GUID   *pguidVal,
  [out, optional] GUID   *pguidValOld,
                  BOOL   bMustExist
);