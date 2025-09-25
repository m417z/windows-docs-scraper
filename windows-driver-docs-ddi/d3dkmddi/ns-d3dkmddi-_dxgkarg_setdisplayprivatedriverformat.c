typedef struct _DXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT {
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] HANDLE                         PrimaryAllocation;
  [in] UINT                           PrivateDriverFormatAttribute;
} DXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT;