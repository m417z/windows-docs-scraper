BOOL PrivilegeCheck(
  [in]      HANDLE         ClientToken,
  [in, out] PPRIVILEGE_SET RequiredPrivileges,
  [out]     LPBOOL         pfResult
);