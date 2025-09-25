typedef struct _WHEA_XPF_CONTEXT_INFO {
  USHORT    RegisterContextType;
  USHORT    RegisterDataSize;
  ULONG     MSRAddress;
  ULONGLONG MmRegisterAddress;
} WHEA_XPF_CONTEXT_INFO, *PWHEA_XPF_CONTEXT_INFO;