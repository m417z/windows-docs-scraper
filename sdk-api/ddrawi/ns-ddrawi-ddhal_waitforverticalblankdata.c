typedef struct _DDHAL_WAITFORVERTICALBLANKDATA {
  LPDDRAWI_DIRECTDRAW_GBL      lpDD;
  DWORD                        dwFlags;
  DWORD                        bIsInVB;
  ULONG_PTR                    hEvent;
  HRESULT                      ddRVal;
  LPDDHAL_WAITFORVERTICALBLANK WaitForVerticalBlank;
} *LPDDHAL_WAITFORVERTICALBLANKDATA, DDHAL_WAITFORVERTICALBLANKDATA;