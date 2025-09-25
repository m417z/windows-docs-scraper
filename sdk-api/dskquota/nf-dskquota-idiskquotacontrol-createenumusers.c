HRESULT CreateEnumUsers(
  [in]  PSID                  *rgpUserSids,
  [in]  DWORD                 cpSids,
  [in]  DWORD                 fNameResolution,
  [out] PENUM_DISKQUOTA_USERS *ppEnum
);