CRYPTCATMEMBER * CryptCATPutMemberInfo(
  [in]           HANDLE hCatalog,
  [in, optional] LPWSTR pwszFileName,
  [in]           LPWSTR pwszReferenceTag,
  [in]           GUID   *pgSubjectType,
  [in]           DWORD  dwCertVersion,
  [in]           DWORD  cbSIPIndirectData,
  [in]           BYTE   *pbSIPIndirectData
);