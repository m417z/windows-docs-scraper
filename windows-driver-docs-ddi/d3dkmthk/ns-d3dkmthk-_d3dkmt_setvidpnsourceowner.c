typedef struct _D3DKMT_SETVIDPNSOURCEOWNER {
  [in] D3DKMT_HANDLE                        hDevice;
  [in] const D3DKMT_VIDPNSOURCEOWNER_TYPE   *pType;
  [in] const D3DDDI_VIDEO_PRESENT_SOURCE_ID *pVidPnSourceId;
       UINT                                 VidPnSourceCount;
} D3DKMT_SETVIDPNSOURCEOWNER;