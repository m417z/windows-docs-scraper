HRESULT wiasReadPropFloat(
  [in]            BYTE   *pWiasContext,
                  PROPID propid,
  [out]           FLOAT  *pfVal,
  [out, optional] FLOAT  *pfValOld,
                  BOOL   bMustExist
);