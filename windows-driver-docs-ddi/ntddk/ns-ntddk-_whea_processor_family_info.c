typedef union _WHEA_PROCESSOR_FAMILY_INFO {
  struct {
    ULONG Stepping : 4;
    ULONG Model : 4;
    ULONG Family : 4;
    ULONG ProcessorType : 2;
    ULONG Reserved1 : 2;
    ULONG ExtendedModel : 4;
    ULONG ExtendedFamily : 8;
    ULONG Reserved2 : 4;
    ULONG NativeModelId;
  } DUMMYSTRUCTNAME;
  ULONGLONG AsULONGLONG;
} WHEA_PROCESSOR_FAMILY_INFO, *PWHEA_PROCESSOR_FAMILY_INFO;