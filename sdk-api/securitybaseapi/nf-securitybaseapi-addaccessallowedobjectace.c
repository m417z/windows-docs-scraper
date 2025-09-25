BOOL AddAccessAllowedObjectAce(
  [in, out]      PACL  pAcl,
  [in]           DWORD dwAceRevision,
  [in]           DWORD AceFlags,
  [in]           DWORD AccessMask,
  [in, optional] GUID  *ObjectTypeGuid,
  [in, optional] GUID  *InheritedObjectTypeGuid,
  [in]           PSID  pSid
);