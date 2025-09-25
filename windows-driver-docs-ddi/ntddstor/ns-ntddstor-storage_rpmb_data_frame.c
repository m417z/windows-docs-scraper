typedef struct _STORAGE_RPMB_DATA_FRAME {
  UCHAR Stuff[196];
  UCHAR KeyOrMAC[32];
  UCHAR Data[256];
  UCHAR Nonce[16];
  UCHAR WriteCounter[4];
  UCHAR Address[2];
  UCHAR BlockCount[2];
  UCHAR OperationResult[2];
  UCHAR RequestOrResponseType[2];
} STORAGE_RPMB_DATA_FRAME, *PSTORAGE_RPMB_DATA_FRAME;