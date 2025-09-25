typedef struct _MFT_OUTPUT_DATA_BUFFER {
  DWORD         dwStreamID;
  IMFSample     *pSample;
  DWORD         dwStatus;
  IMFCollection *pEvents;
} MFT_OUTPUT_DATA_BUFFER, *PMFT_OUTPUT_DATA_BUFFER;