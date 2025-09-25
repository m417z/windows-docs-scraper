typedef struct _DD_GETMOCOMPFORMATSDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  GUID                 *lpGuid;
  DWORD                dwNumFormats;
  LPDDPIXELFORMAT      lpFormats;
  HRESULT              ddRVal;
} *PDD_GETMOCOMPFORMATSDATA, DD_GETMOCOMPFORMATSDATA;