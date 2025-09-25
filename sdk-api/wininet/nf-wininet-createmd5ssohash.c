BOOL CreateMD5SSOHash(
  [in]  PWSTR pszChallengeInfo,
  [in]  PWSTR pwszRealm,
  [in]  PWSTR pwszTarget,
  [out] PBYTE pbHexHash
);