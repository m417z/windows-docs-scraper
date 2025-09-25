typedef struct {
  DWORD_PTR dwCallback;
  DWORD     dwFrom;
  DWORD     dwTo;
  POINT     ptOffset;
  POINT     ptExtent;
  RECT      rc;
  DWORD     dwAudioStream;
  DWORD     dwVideoStream;
} MCI_DGV_DELETE_PARMS;