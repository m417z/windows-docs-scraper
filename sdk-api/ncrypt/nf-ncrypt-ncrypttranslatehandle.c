SECURITY_STATUS NCryptTranslateHandle(
  [out, optional] NCRYPT_PROV_HANDLE *phProvider,
  [out]           NCRYPT_KEY_HANDLE  *phKey,
  [in]            HCRYPTPROV         hLegacyProv,
  [in, optional]  HCRYPTKEY          hLegacyKey,
  [in, optional]  DWORD              dwLegacyKeySpec,
  [in]            DWORD              dwFlags
);