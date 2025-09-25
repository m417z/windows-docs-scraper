BOOL CheckTokenMembershipEx(
  [in, optional] HANDLE TokenHandle,
  [in]           PSID   SidToCheck,
  [in]           DWORD  Flags,
  [out]          PBOOL  IsMember
);