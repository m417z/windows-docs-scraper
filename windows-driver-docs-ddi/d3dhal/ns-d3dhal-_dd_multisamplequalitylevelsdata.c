typedef struct _DD_MULTISAMPLEQUALITYLEVELSDATA {
  DD_GETDRIVERINFO2DATA gdi2;
  D3DFORMAT             Format;
  BOOL                  bFlip : 1;
  D3DMULTISAMPLE_TYPE   MSType : 31;
  DWORD                 QualityLevels;
} DD_MULTISAMPLEQUALITYLEVELSDATA;