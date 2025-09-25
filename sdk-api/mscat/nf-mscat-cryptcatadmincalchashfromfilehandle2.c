BOOL CryptCATAdminCalcHashFromFileHandle2(
  [in]      HCATADMIN hCatAdmin,
  [in]      HANDLE    hFile,
  [in, out] DWORD     *pcbHash,
            BYTE      *pbHash,
            DWORD     dwFlags
);