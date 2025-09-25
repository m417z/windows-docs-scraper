typedef struct {
  PVOID  UserContext;
  ULONG  BufferSize;
  PUCHAR Buffer;
  UCHAR  MinorFunction;
  UCHAR  ReturnStatus;
  ULONG  ReturnSize;
} SCSIWMI_REQUEST_CONTEXT, *PSCSIWMI_REQUEST_CONTEXT;