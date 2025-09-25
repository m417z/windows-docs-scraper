typedef struct _AVC_STREAM_REQUEST_BLOCK {
  ULONG            SizeOfThisBlock;
  ULONG            Version;
  AVCSTRM_FUNCTION Function;
  ULONG            Flags;
  NTSTATUS         Status;
  PVOID            AVCStreamContext;
  PVOID            Context1;
  PVOID            Context2;
  PVOID            Context3;
  PVOID            Context4;
  ULONG            Reserved[4];
  union {
    KSSTATE               StreamState;
    AVCSTRM_OPEN_STRUCT   OpenStruct;
    AVCSTRM_BUFFER_STRUCT BufferStruct;
  } CommandData;
  _tagCommandData  _tagCommandData;
} AVC_STREAM_REQUEST_BLOCK, *PAVC_STREAM_REQUEST_BLOCK;