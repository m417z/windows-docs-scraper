DWORD EapPeerGetConfigBlobAndUserBlob(
  [in]  DWORD           dwFlags,
  [in]  EAP_METHOD_TYPE eapMethodType,
  [in]  EapCredential   eapCredential,
  [out] DWORD           *pdwConfigBlobSize,
  [out] BYTE            **ppConfigBlob,
  [out] DWORD           *pdwUserBlobSize,
  [out] BYTE            **ppUserBlob,
  [out] EAP_ERROR       **ppEapError
);