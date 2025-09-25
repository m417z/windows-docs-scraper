BOOL CheckTokenMembership(
  [in, optional] HANDLE TokenHandle,
  [in]           PSID   SidToCheck,
  [out]          PBOOL  IsMember
);