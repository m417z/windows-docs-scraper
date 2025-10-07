HRESULT OleConvertOLESTREAMToIStorage2(
  [in]  LPOLESTREAM          lpolestream,
  [out] LPSTORAGE            pstg,
  [in]  const DVTARGETDEVICE *ptd,
  [in]  DWORD                opt,
  [in]  PVOID                pvCallbackContext,
  [in]  OLESTREAMQUERYCONVERTOLELINKCALLBACK pQueryConvertOLELinkCallback
);