DWORD EapHostPeerGetDataToUnplumbCredentials(
  [out] GUID          *pConnectionIdThatLastSavedCreds,
  [out] __int3264     *phCredentialImpersonationToken,
  [out] EAP_SESSIONID sessionHandle,
  [in]  EAP_ERROR     **ppEapError,
  [out] BOOL          *fSaveToCredMan
);