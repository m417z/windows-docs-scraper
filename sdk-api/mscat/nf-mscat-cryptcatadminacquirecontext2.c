BOOL CryptCATAdminAcquireContext2(
  [out]          HCATADMIN               *phCatAdmin,
  [in, optional] const GUID              *pgSubsystem,
  [in, optional] PCWSTR                  pwszHashAlgorithm,
  [in, optional] PCCERT_STRONG_SIGN_PARA pStrongHashPolicy,
                 DWORD                   dwFlags
);