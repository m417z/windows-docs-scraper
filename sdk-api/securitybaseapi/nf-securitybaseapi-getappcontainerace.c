BOOL GetAppContainerAce(
  [in]            PACL  Acl,
  [in]            DWORD StartingAceIndex,
  [out]           PVOID *AppContainerAce,
  [out, optional] DWORD *AppContainerAceIndex
);