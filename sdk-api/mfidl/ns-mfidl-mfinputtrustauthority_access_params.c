typedef struct _MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS {
  DWORD                               dwSize;
  DWORD                               dwVer;
  DWORD                               cbSignatureOffset;
  DWORD                               cbSignatureSize;
  DWORD                               cbExtensionOffset;
  DWORD                               cbExtensionSize;
  DWORD                               cActions;
  MFINPUTTRUSTAUTHORITY_ACCESS_ACTION rgOutputActions[1];
} MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS;