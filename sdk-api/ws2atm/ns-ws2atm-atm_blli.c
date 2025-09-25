typedef struct {
  DWORD Layer2Protocol;
  DWORD Layer2UserSpecifiedProtocol;
  DWORD Layer3Protocol;
  DWORD Layer3UserSpecifiedProtocol;
  DWORD Layer3IPI;
  UCHAR SnapID[5];
} ATM_BLLI;