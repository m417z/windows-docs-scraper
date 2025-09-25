typedef struct _D3DKMT_ESCAPE_VIRTUAL_REFRESH_RATE {
  D3DKMT_ESCAPE_VIRTUAL_REFRESH_RATE_TYPE Type;
  UINT                                    VidPnSourceId;
  BOOLEAN                                 ProcessBoostEligible;
  UINT                                    VSyncMultiplier;
  UINT                                    BaseDesktopDuration;
  UCHAR                                   Reserved[16];
} D3DKMT_ESCAPE_VIRTUAL_REFRESH_RATE;