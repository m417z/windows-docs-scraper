BOOL AddAuditAccessObjectAce(
  [in, out]      PACL  pAcl,
  [in]           DWORD dwAceRevision,
  [in]           DWORD AceFlags,
  [in]           DWORD AccessMask,
  [in, optional] GUID  *ObjectTypeGuid,
  [in, optional] GUID  *InheritedObjectTypeGuid,
  [in]           PSID  pSid,
  [in]           BOOL  bAuditSuccess,
  [in]           BOOL  bAuditFailure
);