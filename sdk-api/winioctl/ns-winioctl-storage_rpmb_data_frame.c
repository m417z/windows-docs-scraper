typedef struct _STORAGE_RPMB_DATA_FRAME {
  BYTE Stuff[196];
  BYTE KeyOrMAC[32];
  BYTE Data[256];
  BYTE Nonce[16];
  BYTE WriteCounter[4];
  BYTE Address[2];
  BYTE BlockCount[2];
  BYTE OperationResult[2];
  BYTE RequestOrResponseType[2];
} STORAGE_RPMB_DATA_FRAME, *PSTORAGE_RPMB_DATA_FRAME;