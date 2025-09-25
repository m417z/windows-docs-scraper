HRESULT ConvertToSid(
  [in]      LPCWSTR lpszUniqueID,
  [in]      REFGUID ProviderGUID,
  [in]      USHORT  cbSid,
  [in, out] BYTE    *pSid,
  [out]     USHORT  *pcbRequiredSid
);