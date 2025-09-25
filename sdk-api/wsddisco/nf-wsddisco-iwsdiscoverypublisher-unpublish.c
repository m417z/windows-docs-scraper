HRESULT UnPublish(
  [in]           LPCWSTR              pszId,
  [in]           ULONGLONG            ullInstanceId,
  [in]           ULONGLONG            ullMessageNumber,
  [in, optional] LPCWSTR              pszSessionId,
  [in, optional] const WSDXML_ELEMENT *pAny
);