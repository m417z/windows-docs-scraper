typedef struct _ETW_BUFFER_CONTEXT {
  union {
    struct {
      UCHAR ProcessorNumber;
      UCHAR Alignment;
    } DUMMYSTRUCTNAME;
    USHORT ProcessorIndex;
  } DUMMYUNIONNAME;
  USHORT LoggerId;
} ETW_BUFFER_CONTEXT, *PETW_BUFFER_CONTEXT;