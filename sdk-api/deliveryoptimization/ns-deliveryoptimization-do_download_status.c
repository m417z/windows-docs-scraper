typedef struct _DO_DOWNLOAD_STATUS {
  UINT64          BytesTotal;
  UINT64          BytesTransferred;
  DODownloadState State;
  HRESULT         Error;
  HRESULT         ExtendedError;
} DO_DOWNLOAD_STATUS;