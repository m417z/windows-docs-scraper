HRESULT wiasReadPropBin(
  [in]            BYTE   *pWiasContext,
                  PROPID propid,
  [out]           BYTE   **ppbVal,
  [out, optional] BYTE   **ppbValOld,
                  BOOL   bMustExist
);