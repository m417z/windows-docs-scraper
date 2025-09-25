VOID BuildTrusteeWithObjectsAndSidW(
  [in, out]      PTRUSTEE_W       pTrustee,
  [in, optional] POBJECTS_AND_SID pObjSid,
  [in, optional] GUID             *pObjectGuid,
  [in, optional] GUID             *pInheritedObjectGuid,
  [in, optional] PSID             pSid
);