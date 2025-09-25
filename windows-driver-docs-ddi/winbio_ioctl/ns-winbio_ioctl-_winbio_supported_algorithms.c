typedef struct _WINBIO_SUPPORTED_ALGORITHMS {
  DWORD       PayloadSize;
  HRESULT     WinBioHresult;
  DWORD       NumberOfAlgorithms;
  WINBIO_DATA AlgorithmData;
} WINBIO_SUPPORTED_ALGORITHMS, *PWINBIO_SUPPORTED_ALGORITHMS;