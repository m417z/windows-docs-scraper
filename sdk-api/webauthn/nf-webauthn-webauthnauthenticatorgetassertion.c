HRESULT WebAuthNAuthenticatorGetAssertion(
  HWND                                           hWnd,
  LPCWSTR                                        pwszRpId,
  PCWEBAUTHN_CLIENT_DATA                         pWebAuthNClientData,
  PCWEBAUTHN_AUTHENTICATOR_GET_ASSERTION_OPTIONS pWebAuthNGetAssertionOptions,
  PWEBAUTHN_ASSERTION                            *ppWebAuthNAssertion
);