VOID BuildTrusteeWithObjectsAndSidA(
  [in, out]      PTRUSTEE_A       pTrustee,
  [in, optional] POBJECTS_AND_SID pObjSid,
  [in, optional] GUID             *pObjectGuid,
  [in, optional] GUID             *pInheritedObjectGuid,
  [in, optional] PSID             pSid
);