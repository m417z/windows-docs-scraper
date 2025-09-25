HRESULT wiasReadPropStr(
  [in]            BYTE   *pWiasContext,
                  PROPID propid,
  [out]           BSTR   *pbstr,
  [out, optional] BSTR   *pbstrOld,
                  BOOL   bMustExist
);