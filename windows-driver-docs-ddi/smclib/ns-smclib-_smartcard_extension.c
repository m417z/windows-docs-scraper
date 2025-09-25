typedef struct _SMARTCARD_EXTENSION {
  ULONG                     Version;
  VENDOR_ATTR               VendorAttr;
  NTSTATUS(                 *ReaderFunction[16];
  SCARD_CARD_CAPABILITIES   CardCapabilities;
  ULONG                     LastError;
  struct {
    PULONG Information;
    PUCHAR RequestBuffer;
    ULONG  RequestBufferLength;
    PUCHAR ReplyBuffer;
    ULONG  ReplyBufferLength;
  } IoRequest;
  ULONG                     MajorIoControlCode;
  ULONG                     MinorIoControlCode;
  POS_DEP_DATA              OsData;
  SCARD_READER_CAPABILITIES ReaderCapabilities;
  PREADER_EXTENSION         ReaderExtension;
  SMARTCARD_REPLY           SmartcardReply;
  SMARTCARD_REQUEST         SmartcardRequest;
  T0_DATA                   T0;
  T1_DATA                   T1;
  PPERF_INFO                PerfInfo;
  ULONG                     Reserved[25 - sizeof(PPERF_INFO)];
} *PSMARTCARD_EXTENSION, SMARTCARD_EXTENSION;