typedef struct tagFORMATETC {
  CLIPFORMAT     cfFormat;
  DVTARGETDEVICE *ptd;
  DWORD          dwAspect;
  LONG           lindex;
  DWORD          tymed;
} FORMATETC, *LPFORMATETC;