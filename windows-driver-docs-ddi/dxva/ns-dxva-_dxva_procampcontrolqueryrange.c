typedef struct _DXVA_ProcAmpControlQueryRange {
  DWORD                   Size;
  DXVA_ProcAmpControlProp ProcAmpControlProp;
  DXVA_VideoDesc          VideoDesc;
} DXVA_ProcAmpControlQueryRange, *LPDXVA_ProcAmpControlQueryRange;