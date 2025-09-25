typedef struct _WHEA_PROCESSOR_GENERIC_ERROR_SECTION {
  WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS ValidBits;
  UCHAR                                          ProcessorType;
  UCHAR                                          InstructionSet;
  UCHAR                                          ErrorType;
  UCHAR                                          Operation;
  UCHAR                                          Flags;
  UCHAR                                          Level;
  USHORT                                         Reserved;
  ULONGLONG                                      CPUVersion;
  UCHAR                                          CPUBrandString[128];
  ULONGLONG                                      ProcessorId;
  ULONGLONG                                      TargetAddress;
  ULONGLONG                                      RequesterId;
  ULONGLONG                                      ResponderId;
  ULONGLONG                                      InstructionPointer;
} WHEA_PROCESSOR_GENERIC_ERROR_SECTION, *PWHEA_PROCESSOR_GENERIC_ERROR_SECTION;