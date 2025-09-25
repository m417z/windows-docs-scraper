typedef struct TpcGetSamplesArgs {
  BYTE  *pbSampleBuf;
  DWORD cbSampleBuf;
  DWORD dwSamplesReturned;
  DWORD dwSamplesAvailable;
} TpcGetSamplesArgs;