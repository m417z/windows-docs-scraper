typedef struct _DXGKARG_GETDPADDRESS {
  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId;
  UINT                           DPNativeError;
  UINT                           RootPortIndex;
  BYTE                           NumLinks;
  BYTE                           RelAddress[MAX_DP_ADDRESS_SIZE];
} DXGKARG_GETDPADDRESS, *PDXGKARG_GETDPADDRESS;