HRESULT LoginToTarget(
  [in]  VDS_ISCSI_LOGIN_TYPE loginType,
  [in]  VDS_OBJECT_ID        targetId,
  [in]  VDS_OBJECT_ID        targetPortalId,
  [in]  VDS_OBJECT_ID        initiatorPortalId,
  [in]  ULONG                ulLoginFlags,
  [in]  BOOL                 bHeaderDigest,
  [in]  BOOL                 bDataDigest,
  [in]  VDS_ISCSI_AUTH_TYPE  authType,
  [out] IVdsAsync            **ppAsync
);