HRESULT ScriptItemize(
  [in]           const WCHAR          *pwcInChars,
  [in]           int                  cInChars,
  [in]           int                  cMaxItems,
  [in, optional] const SCRIPT_CONTROL *psControl,
  [in, optional] const SCRIPT_STATE   *psState,
  [out]          SCRIPT_ITEM          *pItems,
  [out]          int                  *pcItems
);