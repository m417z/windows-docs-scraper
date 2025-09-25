HRESULT WebAuthNAuthenticatorMakeCredential(
  HWND                                             hWnd,
  PCWEBAUTHN_RP_ENTITY_INFORMATION                 pRpInformation,
  PCWEBAUTHN_USER_ENTITY_INFORMATION               pUserInformation,
  PCWEBAUTHN_COSE_CREDENTIAL_PARAMETERS            pPubKeyCredParams,
  PCWEBAUTHN_CLIENT_DATA                           pWebAuthNClientData,
  PCWEBAUTHN_AUTHENTICATOR_MAKE_CREDENTIAL_OPTIONS pWebAuthNMakeCredentialOptions,
  PWEBAUTHN_CREDENTIAL_ATTESTATION                 *ppWebAuthNCredentialAttestation
);