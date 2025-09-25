HRESULT GetClientCertificate(
  [out] BG_CERT_STORE_LOCATION *pStoreLocation,
  [out] LPWSTR                 *pStoreName,
  [out] byte                   **ppCertHashBlob,
  [out] LPWSTR                 *pSubjectName
);