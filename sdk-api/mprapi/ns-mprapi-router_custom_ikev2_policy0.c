typedef struct _ROUTER_CUSTOM_IKEv2_POLICY0 {
  DWORD dwIntegrityMethod;
  DWORD dwEncryptionMethod;
  DWORD dwCipherTransformConstant;
  DWORD dwAuthTransformConstant;
  DWORD dwPfsGroup;
  DWORD dwDhGroup;
} ROUTER_CUSTOM_IKEv2_POLICY0, *PROUTER_CUSTOM_IKEv2_POLICY0, ROUTER_CUSTOM_L2TP_POLICY0, *PROUTER_CUSTOM_L2TP_POLICY0;