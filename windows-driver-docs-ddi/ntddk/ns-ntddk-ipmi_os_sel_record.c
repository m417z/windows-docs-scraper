typedef struct _IPMI_OS_SEL_RECORD {
  ULONG                   Signature;
  ULONG                   Version;
  ULONG                   Length;
  IPMI_OS_SEL_RECORD_TYPE RecordType;
  ULONG                   DataLength;
  UCHAR                   Data[ANYSIZE_ARRAY];
} IPMI_OS_SEL_RECORD, *PIPMI_OS_SEL_RECORD;