typedef struct _AVCSTRM_OPEN_STRUCT {
  KSPIN_DATAFLOW       DataFlow;
  PAVCSTRM_FORMAT_INFO AVCFormatInfo;
  PVOID                AVCStreamContext;
  HANDLE               hPlugLocal;
} AVCSTRM_OPEN_STRUCT, *PAVCSTRM_OPEN_STRUCT;