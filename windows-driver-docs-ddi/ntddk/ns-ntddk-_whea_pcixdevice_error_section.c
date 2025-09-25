typedef struct _WHEA_PCIXDEVICE_ERROR_SECTION {
  WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS ValidBits;
  WHEA_ERROR_STATUS                       ErrorStatus;
  WHEA_PCIXDEVICE_ID                      IdInfo;
  ULONG                                   MemoryNumber;
  ULONG                                   IoNumber;
  WHEA_PCIXDEVICE_REGISTER_PAIR           RegisterDataPairs[ANYSIZE_ARRAY];
} WHEA_PCIXDEVICE_ERROR_SECTION, *PWHEA_PCIXDEVICE_ERROR_SECTION;