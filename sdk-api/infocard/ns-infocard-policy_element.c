typedef struct _POLICY_ELEMENT {
  LPCWSTR targetEndpointAddress;
  LPCWSTR issuerEndpointAddress;
  LPCWSTR issuedTokenParameters;
  LPCWSTR privacyNoticeLink;
  DWORD   privacyNoticeVersion;
  BOOL    useManagedPresentation;
} POLICY_ELEMENT, *PPOLICY_ELEMENT;