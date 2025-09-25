typedef struct _DD_VPORTCOLORDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  DWORD                dwFlags;
  LPDDCOLORCONTROL     lpColorData;
  HRESULT              ddRVal;
  VOID                 *ColorControl;
} *PDD_VPORTCOLORDATA, DD_VPORTCOLORDATA;