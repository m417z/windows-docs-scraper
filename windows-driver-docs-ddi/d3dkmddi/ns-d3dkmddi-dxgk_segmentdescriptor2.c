typedef struct _DXGK_SEGMENTDESCRIPTOR2 {
  DXGK_SEGMENTFLAGS2 Flags;
  SIZE_T             Size;
  PMDL               pMdl;
  PHYSICAL_ADDRESS   BaseAddress;
  PHYSICAL_ADDRESS   CpuTranslatedAddress;
} DXGK_SEGMENTDESCRIPTOR2;