typedef struct _DD_GETVPORTINPUTFORMATDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  DWORD                dwFlags;
  LPDDPIXELFORMAT      lpddpfFormat;
  DWORD                dwNumFormats;
  HRESULT              ddRVal;
  VOID                 *GetVideoPortInputFormats;
} *PDD_GETVPORTINPUTFORMATDATA, DD_GETVPORTINPUTFORMATDATA;