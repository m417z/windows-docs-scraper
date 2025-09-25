HRESULT ErrorAdvise(
  [in]  HRESULT                   hr,
  [in]  LPCWSTR                   pszErrorMessage,
  [in]  ERROR_ADVISE_MESSAGE_TYPE nMessageType,
  [out] ERROR_ADVISE_RESULT       *pnErrorAdviseResult
);