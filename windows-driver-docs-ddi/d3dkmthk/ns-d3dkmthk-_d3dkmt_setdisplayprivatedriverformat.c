typedef struct _D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT {
  [in] D3DKMT_HANDLE                  hDevice;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] UINT                           PrivateDriverFormatAttribute;
} D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT;