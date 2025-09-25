HRESULT ScriptStringAnalyse(
  [in]           HDC                    hdc,
  [in]           const void             *pString,
  [in]           int                    cString,
  [in]           int                    cGlyphs,
  [in]           int                    iCharset,
  [in]           DWORD                  dwFlags,
  [in]           int                    iReqWidth,
  [in, optional] SCRIPT_CONTROL         *psControl,
  [in, optional] SCRIPT_STATE           *psState,
  [in, optional] const int              *piDx,
  [in, optional] SCRIPT_TABDEF          *pTabdef,
  [in]           const BYTE             *pbInClass,
  [out]          SCRIPT_STRING_ANALYSIS *pssa
);