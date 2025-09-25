SHSTDAPI SHPropStgCreate(
  [in]            IPropertySetStorage *psstg,
  [in]            REFFMTID            fmtid,
  [in, optional]  const CLSID         *pclsid,
                  DWORD               grfFlags,
                  DWORD               grfMode,
                  DWORD               dwDisposition,
  [out]           IPropertyStorage    **ppstg,
  [out, optional] UINT                *puCodePage
);