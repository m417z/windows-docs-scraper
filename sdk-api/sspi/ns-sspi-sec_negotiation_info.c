typedef struct _SEC_NEGOTIATION_INFO {
  unsigned long Size;
  unsigned long NameLength;
  SEC_WCHAR     *Name;
  void          *Reserved;
} SEC_NEGOTIATION_INFO, *PSEC_NEGOTIATION_INFO;