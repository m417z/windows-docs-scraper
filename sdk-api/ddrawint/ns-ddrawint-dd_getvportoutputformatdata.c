typedef struct _DD_GETVPORTOUTPUTFORMATDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  DWORD                dwFlags;
  LPDDPIXELFORMAT      lpddpfInputFormat;
  LPDDPIXELFORMAT      lpddpfOutputFormats;
  DWORD                dwNumFormats;
  HRESULT              ddRVal;
  VOID                 *GetVideoPortInputFormats;
} *PDD_GETVPORTOUTPUTFORMATDATA, DD_GETVPORTOUTPUTFORMATDATA;