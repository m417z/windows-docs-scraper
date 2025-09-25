typedef struct tagCapDriverCaps {
  UINT   wDeviceIndex;
  BOOL   fHasOverlay;
  BOOL   fHasDlgVideoSource;
  BOOL   fHasDlgVideoFormat;
  BOOL   fHasDlgVideoDisplay;
  BOOL   fCaptureInitialized;
  BOOL   fDriverSuppliesPalettes;
  HANDLE hVideoIn;
  HANDLE hVideoOut;
  HANDLE hVideoExtIn;
  HANDLE hVideoExtOut;
} CAPDRIVERCAPS, *PCAPDRIVERCAPS, *LPCAPDRIVERCAPS;