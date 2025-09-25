typedef struct {
  UCHAR AvailableData[4];
  UCHAR ResponseToServiceAction : 5;
  UCHAR Reserved1 : 3;
  UCHAR OperationStatus : 7;
  UCHAR Reserved2 : 1;
  UCHAR OperationCounter[2];
  UCHAR EstimatedStatusUpdateDelay[4];
  UCHAR CompletionStatus;
  UCHAR SenseDataFieldLength;
  UCHAR SenseDataLength;
  UCHAR TransferCountUnits;
  UCHAR TransferCount[8];
  UCHAR SegmentsProcessed[2];
  UCHAR Reserved3[6];
  UCHAR SenseData[ANYSIZE_ARRAY];
} RECEIVE_TOKEN_INFORMATION_HEADER, *PRECEIVE_TOKEN_INFORMATION_HEADER;