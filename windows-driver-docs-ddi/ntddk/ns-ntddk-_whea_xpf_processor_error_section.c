typedef struct _WHEA_XPF_PROCESSOR_ERROR_SECTION {
  WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS ValidBits;
  ULONGLONG                                  LocalAPICId;
  UCHAR                                      CpuId[48];
  UCHAR                                      VariableInfo[ANYSIZE_ARRAY];
} WHEA_XPF_PROCESSOR_ERROR_SECTION, *PWHEA_XPF_PROCESSOR_ERROR_SECTION;