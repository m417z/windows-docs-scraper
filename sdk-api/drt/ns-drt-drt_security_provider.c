typedef struct drt_security_provider_tag {
  PVOID    pvContext;
  HRESULT( )(const PVOID pvContext) *Attach;
  VOID( )(const PVOID pvContext)    *Detach;
  HRESULT()(const PVOID pvContext, const DRT_REGISTRATION *pRegistration,PVOID pvKeyContext) * RegisterKey;
  HRESULT()(const PVOID pvContext, const DRT_DATA *pKey,PVOID pvKeyContext) * UnregisterKey;
  HRESULT( pvContext,DRT_DATA *pSecuredAddressPayload,DRT_DATA *pCertChain,DRT_DATA *pClassifier,DRT_DATA *pNonce,DRT_DATA *pSecuredPayload,BYTE *pbProtocolMajor,BYTE *pbProtocolMinor,DRT_DATA *pKey,DRT_DATA *pPayload,CERT_PUBLIC_KEY_INFO **ppPublicKey,SOCKET_ADDRESS_LIST **ppAddressList,DWORD *pdwFlags) * )(const PVOIDValidateAndUnpackPayload;
  HRESULT( PVOID pvContext,PVOID pvKeyContext,BYTE bProtocolMajor,BYTE bProtocolMinor,DWORD dwFlags, const DRT_DATA *pKey, const DRT_DATA *pPayload, const SOCKET_ADDRESS_LIST *pAddressList, const DRT_DATA *pNonce,DRT_DATA *pSecuredAddressPayload,DRT_DATA *pClassifier,DRT_DATA *pSecuredPayload,DRT_DATA *pCertChain) * )(constSecureAndPackPayload;
  void( )(const PVOID pvContext,PVOID pv)    *FreeData;
  HRESULT(onst PVOID pvContext, const DRT_DATA *pRemoteCredential,DWORD dwBuffers,DRT_DATA *pDataBuffers,DRT_DATA *pEncryptedBuffers,DRT_DATA *pKeyToken) * )(cEncryptData;
  HRESULT((const PVOID pvContext,DRT_DATA *pKeyToken, const PVOID pvKeyContext,DWORD dwBuffers,DRT_DATA *pData) * )DecryptData;
  HRESULT()(const PVOID pvContext,DRT_DATA *pSelfCredential) * GetSerializedCredential;
  HRESULT()(const PVOID pvContext,DRT_DATA *pRemoteCredential) * ValidateRemoteCredential;
  HRESULT(const PVOID pvContext,DWORD dwBuffers,DRT_DATA *pDataBuffers,DRT_DATA *pKeyIdentifier,DRT_DATA *pSignature) * )(SignData;
  HRESULT(onst PVOID pvContext,DWORD dwBuffers,DRT_DATA *pDataBuffers,DRT_DATA *pRemoteCredentials,DRT_DATA *pKeyIdentifier,DRT_DATA *pSignature) * )(cVerifyData;
} DRT_SECURITY_PROVIDER, *PDRT_SECURITY_PROVIDER;