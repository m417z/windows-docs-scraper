typedef struct _D3DKMT_QUERYVIDPNEXCLUSIVEOWNERSHIP {
  [in]  HANDLE                         hProcess;
  [in]  HWND                           hWindow;
  [out] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [out] LUID                           AdapterLuid;
  [out] D3DKMT_VIDPNSOURCEOWNER_TYPE   OwnerType;
} D3DKMT_QUERYVIDPNEXCLUSIVEOWNERSHIP;